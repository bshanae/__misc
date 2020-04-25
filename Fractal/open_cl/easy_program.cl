// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							VECTOR2
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct              s_vector2
{
	double                  x;
	double                  y;
}                           t_vector2;

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							EASY
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct              s_julia
{
	t_vector2				min;
	t_vector2				max;
	t_vector2				offset;
	t_vector2				c;
	double                  scale;
	int						iterations;
}                           t_julia;

typedef struct              s_mandelbrot
{
	t_vector2				min;
	t_vector2				max;
	t_vector2				offset;
	double                  scale;
	int						iterations;
}                           t_mandelbrot;

typedef	struct 				s_easy
{
	t_mandelbrot            mandelbrot;
	t_julia		            julia;
	int                     mod;
	int 					width;
	int 					height;
	int						color_mod;
}							t_easy;

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							COLOR
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct		        s_rgba
{
	unsigned char           b;
	unsigned char           g;
	unsigned char           r;
	unsigned char           a;
}					        t_rgba;

typedef union		        u_color
{
	int			            value;
	t_rgba		            rgba;
}					        t_color;

typedef struct		        s_palette
{
	unsigned char           count;
	int			            colors[10];
}					        t_palette;

static int                 color(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

static int		get_light(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static t_color		mix_color(t_color c1, t_color c2, double p)
{
	t_color			c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)get_light((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)get_light((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)get_light((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

static t_color      linear_interpolation(double iter, int color_mod, int max_iterations)
{
	t_palette		palette[4];
	t_palette		result_color;
	double			index;
	double			regulate;
	int				c;

	palette[0] = (t_palette){9, {0xB0E2FF, 0xFF7F50, 0xffdc73, 0xF57336, 0xC22121, 0xff6f69, 0xff6f69, 0xff6f69, 0xff6f69}};
	palette[1] = (t_palette){9, {0x976cab, 0x664790, 0x4a2a75, 0x4e4e95, 0x7474b0, 0x7474b0, 0x7474b0, 0x7474b0, 0x7474b0}};
	palette[2] = (t_palette){9, {0x011f4b, 0x03396c, 0x005b96, 0x6497b1, 0xb3cde0, 0xb3cde0, 0xb3cde0, 0xb3cde0, 0xb3cde0}};
	palette[3] = (t_palette){9, {0x028900, 0x74d600, 0xadff00, 0x00d27f, 0x00ff83, 0x00ff83, 0x00ff83, 0x00ff83, 0x00ff83}};

	result_color = palette[color_mod];

	index = iter / max_iterations;
	c = result_color.count - 1;
	regulate = fmod((double)index, (double)(1.0f / c)) * c;
	return (mix_color((t_color)(result_color.colors[(int)(index * c) + 1]),
				(t_color)(result_color.colors[(int)(index * c)]),
				(int)(regulate + 1) - regulate));
}

static int			smooth(int iter, t_vector2 z, int color_mod, int max_iterations)
{
	double			tmp;

	tmp = iter - log2(log2(z.x * z.x + z.y * z.y)) + 4.;
	return (linear_interpolation(tmp < 0 ? 0 : tmp, color_mod, max_iterations).value);
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							JULIA
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int 					julia(constant t_easy *easy, t_vector2 *z_complex, t_vector2 *screen)
{
	int 					iter;
	double 					tmp;

	z_complex->x = easy->julia.min.x + (screen->x / easy->width) * (easy->julia.max.x - easy->julia.min.x);
	z_complex->y = -(easy->julia.min.y + (screen->y / easy->height) * (easy->julia.max.y - easy->julia.min.y));

	z_complex->x /= easy->julia.scale;
	z_complex->y /= easy->julia.scale;
	z_complex->x += easy->julia.offset.x;
	z_complex->y += easy->julia.offset.y;

	iter = 0;
	while ((z_complex->x * z_complex->x + z_complex->y * z_complex->y <= 4.) && (iter < easy->julia.iterations))
	{
		tmp = (z_complex->x * z_complex->x) - (z_complex->y * z_complex->y) + easy->julia.c.x;
		z_complex->y = 2. * z_complex->x * z_complex->y + easy->julia.c.y;
		z_complex->x = tmp;
		iter++;
	}
	if (iter == easy->julia.iterations)
		return (0);
	else
		return (smooth(iter, *z_complex, easy->color_mod, easy->julia.iterations));
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							MANDELBROT
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int 					mandelbrot(constant t_easy *easy, t_vector2 *z_complex, t_vector2 *screen)
{
	int 					iter;
	double 					tmp;
	t_vector2       		c_complex;

	z_complex->x = easy->mandelbrot.min.x + ((double)screen->x / easy->width) * (easy->mandelbrot.max.x - easy->mandelbrot.min.x);
	z_complex->y = -(easy->mandelbrot.min.y + ((double)screen->y / easy->height) * (easy->mandelbrot.max.y - easy->mandelbrot.min.y));

	z_complex->x /= easy->mandelbrot.scale;
	z_complex->y /= easy->mandelbrot.scale;
	z_complex->x += easy->mandelbrot.offset.x;
	z_complex->y += easy->mandelbrot.offset.y;

	c_complex.x = z_complex->x;
	c_complex.y = z_complex->y;
	iter = 0;
	while ((z_complex->x * z_complex->x + z_complex->y * z_complex->y <= 4.) && (iter < easy->mandelbrot.iterations))
	{
		tmp = (z_complex->x * z_complex->x) - (z_complex->y * z_complex->y) + c_complex.x;
		z_complex->y = 2. * z_complex->x * z_complex->y + c_complex.y;
		z_complex->x = tmp;
		iter++;
	}
	if (iter == easy->mandelbrot.iterations)
		return (0);
	else
		return (smooth(iter, *z_complex, easy->color_mod, easy->mandelbrot.iterations));
}

kernel void					easy
							(global int *image,
							constant t_easy *easy)
{
	int             		global_id;
	t_vector2       		screen;
	t_vector2       		z_complex;

	global_id = get_global_id(0);

	screen.x = global_id % easy->width;
	screen.y = global_id / easy->width;

	if (easy->mod == 1)
		image[global_id] = julia(easy, &z_complex, &screen);
	else if (easy->mod == 2)
		image[global_id] = mandelbrot(easy, &z_complex, &screen);
}