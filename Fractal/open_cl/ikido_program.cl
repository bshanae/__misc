#include "color.h"
#include "vector2.h"
#include "ikido_definition.h"

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							MATH
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static double				ft_ipart(double x)
{
	return (floor(x));
}

static double				ft_fpart(double x)
{
	return (x - floor(x));
}

static double				ft_rfpart(double x)
{
	return (1 - ft_fpart(x));
}

static void					swap_double(double *a, double *b)
{
	double					c;

	c = *a;
	*a = *b;
	*b = c;
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							WU
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



typedef struct				s_wu_set
{
	t_vector2				a;
	t_vector2				b;
	t_vector2				delta;
	t_vector2				end;
	t_vector2				l1;
	t_vector2				l2;
	int						steep;
	double					intersection;
	double					gradient;
	double					gap;
	int						width;
	int						height;
}							t_wu_set;

static void					wu_set_point
							(t_wu_set *set,
		 					global int *image,
		 					int x,
		 					int y,
		 					int iter)
{
	t_color					color;

	if (y < 0 || y >= set->height)
		return ;
	if (x < 0 || x >= set->width)
		return ;
	color.mix = 0x222222;
	color.rgb.r = min(IKIDO_COLOR_STEP * color.rgb.r * iter, 255.);
	color.rgb.g = min(IKIDO_COLOR_STEP * color.rgb.g * iter, 255.);
	color.rgb.b = min(IKIDO_COLOR_STEP * color.rgb.b * iter, 255.);
	image[y * set->width + x] = color.mix;
}

static void					wu_swap
							(t_wu_set *set)
{
	set->steep = fabs(set->b.y - set->a.y) > fabs(set->b.x - set->a.x);
	if (set->steep)
	{
		swap_double(&set->a.x, &set->a.y);
		swap_double(&(set->b.x), &(set->b.y));
	}
	if (set->a.x > set->b.x)
	{
		swap_double(&(set->a.x), &(set->b.x));
		swap_double(&(set->a.y), &(set->b.y));
	}
}

static void					wu_end_point
							(t_wu_set *set,
							global int *image,
							t_vector2 *ab,
							t_vector2 *l12,
							int iter)
{
	set->end = (t_vector2){.x = (int)(ab->x), .y = (int)(ab->y + set->gradient * (round(ab->x) - ab->x))};
	set->gap = ft_rfpart(ab->x + 0.5);
	*l12 = (t_vector2){.x = set->end.x, .y = (int)ft_ipart(set->end.y)};
	if (set->steep)
	{
		wu_set_point(set, image, l12->y, l12->x, iter);
		l12->y++;
		wu_set_point(set, image, l12->y, l12->x, iter);
	}
	else
	{
		wu_set_point(set, image, l12->x, l12->y, iter);
		l12->y++;
		wu_set_point(set, image, l12->x, l12->y, iter);
	}
	l12->y--;
}

static void					wu_steep_case
							(t_wu_set *set,
							global int *image,
							int iter)
{
	int						x;
	t_vector2				temp;

	x = set->l1.x;
	while (x < set->l2.x)
	{
		temp.x = (int)ft_ipart(set->intersection);
		temp.y = (int)x;
		wu_set_point(set, image, temp.x, temp.y, iter);
		temp.x++;
		wu_set_point(set, image, temp.x, temp.y, iter);
		x++;
		set->intersection += set->gradient;
	}
}

static void					wu_non_steep_case
							(t_wu_set *set,
							global int *image,
							int iter)
{
	int						x;
	t_vector2				temp;

	x = set->l1.x;
	while (x < set->l2.x)
	{
		temp.x = (int)x;
		temp.y = (int)ft_ipart(set->intersection);
		wu_set_point(set, image, temp.x, temp.y, iter);
		temp.y++;
		wu_set_point(set, image, temp.x, temp.y, iter);
		x++;
		set->intersection += set->gradient;
	}
}

static void					wu
							(global int *image,
							constant int *width,
							constant int *height,
							const t_vector2 *a,
							const t_vector2 *b,
							int iter)
{
	t_wu_set				set;

	set.width = *width;
	set.height = *height;
	set.a = *a;
	set.b = *b;
	wu_swap(&set);
	set.delta = (t_vector2){.x = set.b.x - set.a.x, .y = set.b.y - set.a.y};
	set.gradient = (set.delta.x) ? ((double)set.delta.y / (double)set.delta.x) : (0);
	wu_end_point(&set, image, &set.a, &set.l1, iter);
	set.intersection = set.end.y + set.gradient;
	wu_end_point(&set, image, &set.b, &set.l2, iter);
	if (set.steep)
		wu_steep_case(&set, image, iter);
	else
		wu_non_steep_case(&set, image, iter);
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							IKIDO
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void					transform
							(constant t_ikido *ikido,
							t_vector2 *v)
{
	v->x = v->x * ikido->zoom + ikido->offset.x;
	v->y = v->y * ikido->zoom + ikido->offset.y;
}

kernel void					ikido
							(global int *image,
		 					constant t_ikido *ikido)
{
 	t_vector2				current[2];
	t_vector2				next[2];
	double					t;

	for (int i = 0; i < IKIDO_POINTS; i++)
	{
		current[0] = ikido->random[get_global_id(0)];

		for (int j = 0; j < IKIDO_ITERS; j++)
		{
			t = 0.4 - 6. / (1. + current[0].x * current[0].x + current[0].y * current[0].y);

			next[0].x = 1. + ikido->u * (current[0].x * cos(t) - current[0].y * sin(t));
			next[0].y = ikido->u * (current[0].x * sin(t) + current[0].y * cos(t));

			current[1] = current[0];
			next[1] = next[0];

			transform(ikido, current + 1);
			transform(ikido, next + 1);

			wu(image, &ikido->width, &ikido->height, current + 1, next + 1, j);
			current[0] = next[0];
		}
	}
}