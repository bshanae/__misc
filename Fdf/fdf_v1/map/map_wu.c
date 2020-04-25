/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:16:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:33:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void			map_wu_swap(t_wu_set *set)
{
	set->steep = (abs(set->b.y - set->a.y) > abs(set->b.x - set->a.x));
	if (set->steep)
	{
		swap_int(&(set->a.x), &(set->a.y));
		swap_int(&(set->b.x), &(set->b.y));
	}
	if (set->a.x > set->b.x)
	{
		swap_int(&(set->a.x), &(set->b.x));
		swap_int(&(set->a.y), &(set->b.y));
		swap_int(&set->a.color.mix, &set->b.color.mix);
	}
}

void				map_wu_end_point
	(t_wu_set *set, t_point_2d *ab, t_point_2d *l12)
{
	t_color			temp;

	set->end = (t_point_2d){.x = (int)(ab->x),
		.y = (int)(ab->y + set->gradient * (round(ab->x) - ab->x)),
		.color = ab->color};
	set->gap = ft_rfpart(ab->x + 0.5);
	*l12 = (t_point_2d){.x = set->end.x,
		.y = (int)ft_ipart(set->end.y), .color = set->end.color};
	if (set->steep)
	{
		temp = color_adjust(l12->color.mix, ft_rfpart(set->end.y) * set->gap);
		map_point_set(set->map, &l12->y, &l12->x, &temp);
		temp = color_adjust(l12->color.mix, ft_fpart(set->end.y) * set->gap);
		l12->y++;
		map_point_set(set->map, &l12->y, &l12->x, &temp);
	}
	else
	{
		temp = color_adjust(l12->color.mix, ft_rfpart(set->end.y) * set->gap);
		map_point_set(set->map, &l12->x, &l12->y, &temp);
		temp = color_adjust(l12->color.mix, ft_fpart(set->end.y) * set->gap);
		l12->y++;
		map_point_set(set->map, &l12->x, &l12->y, &temp);
	}
	l12->y--;
}

static void			map_wu_steep_case(t_wu_set *set)
{
	int				x;
	t_point_2d		temp;

	x = set->l1.x;
	while (x < set->l2.x)
	{
		temp.x = (int)ft_ipart(set->intersection);
		temp.y = (int)x;
		temp.color = point_color_gradient(&set->l1, &set->l2, &x,
			ft_rfpart(set->intersection));
		map_point_set(set->map, &temp.x, &temp.y, &temp.color);
		temp.x++;
		temp.color = point_color_gradient(&set->l1, &set->l2, &x,
			ft_fpart(set->intersection));
		map_point_set(set->map, &temp.x, &temp.y, &temp.color);
		x++;
		set->intersection += set->gradient;
	}
}

static void			map_wu_non_steep_case(t_wu_set *set)
{
	int				x;
	t_point_2d		temp;

	x = set->l1.x;
	while (x < set->l2.x)
	{
		temp.x = (int)x;
		temp.y = (int)ft_ipart(set->intersection);
		temp.color = point_color_gradient(&set->l1, &set->l2, &x,
			ft_rfpart(set->intersection));
		map_point_set(set->map, &temp.x, &temp.y, &temp.color);
		temp.y++;
		temp.color = point_color_gradient(&set->l1, &set->l2, &x,
			ft_fpart(set->intersection));
		map_point_set(set->map, &temp.x, &temp.y, &temp.color);
		x++;
		set->intersection += set->gradient;
	}
}

void				map_wu(t_map *map, const t_point_2d *a, const t_point_2d *b)
{
	t_wu_set		set;

	set.map = map;
	set.a = *a;
	set.b = *b;
	map_wu_swap(&set);
	set.delta = (t_point_2d){.x = set.b.x - set.a.x, .y = set.b.y - set.a.y};
	set.gradient =
			(set.delta.x) ? ((double)set.delta.y / (double)set.delta.x) : (0);
	map_wu_end_point(&set, &set.a, &set.l1);
	set.intersection = set.end.y + set.gradient;
	map_wu_end_point(&set, &set.b, &set.l2);
	if (set.steep)
		map_wu_steep_case(&set);
	else
		map_wu_non_steep_case(&set);
}
