//#define constant			const

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							VECTOR3
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct				s_vector3
{
	double 					x;
	double 					y;
	double 					z;
}							t_vector3;

static double 				vector3_length(const t_vector3 *me)
{
	return (sqrt(me->x * me->x + me->y * me->y + me->z * me->z));
}

static double 				vector3_s_length(t_vector3 me)
{
	return (sqrt(me.x * me.x + me.y * me.y + me.z * me.z));
}

static void					vector3_normalize(t_vector3 *me)
{
	double		length;

	length = vector3_length(me);
	me->x /= length;
	me->y /= length;
	me->z /= length;
}

static t_vector3			vector3_s_normalize(t_vector3 me)
{
	double		length;

	length = vector3_length(&me);
	me.x /= length;
	me.y /= length;
	me.z /= length;
	return (me);
}

static t_vector3			vector3_normalized(const t_vector3 *me)
{
	t_vector3		result;

	result = *me;
	vector3_normalize(&result);
	return (result);
}

static double 				vector3_dot(const t_vector3 *v1, const t_vector3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

static double 				vector3_s_dot(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

static t_vector3			vector3_cross(const t_vector3 *v1, const t_vector3 *v2)
{
	t_vector3		result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}

static t_vector3			vector3_s_cross(t_vector3 v1, t_vector3 v2)
{
	t_vector3		result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

static t_vector3			vector3_sub(const t_vector3 *v1, const t_vector3 *v2)
{
	t_vector3		result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

static t_vector3			vector3_s_sub(t_vector3 v1, t_vector3 v2)
{
	t_vector3		result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

static void					vector3_sub_eq(t_vector3 *v1, const t_vector3 *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
}

static void					vector3_s_sub_eq(t_vector3 *v1, t_vector3 v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
}

static t_vector3			vector3_add(const t_vector3 *v1, const t_vector3 *v2)
{
	t_vector3		result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

static t_vector3			vector3_s_add(t_vector3 v1, t_vector3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

static void					vector3_add_eq(t_vector3 *v1, const t_vector3 *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

static void					vector3_s_add_eq(t_vector3 *v1, t_vector3 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

static t_vector3			vector3_mul(const t_vector3 *v1, double k)
{
	t_vector3		result;

	result.x = v1->x * k;
	result.y = v1->y * k;
	result.z = v1->z * k;
	return (result);
}

static t_vector3			vector3_s_mul(t_vector3 v1, double k)
{
	v1.x *= k;
	v1.y *= k;
	v1.z *= k;
	return (v1);
}

static void					vector3_mul_eq(t_vector3 *v1, double k)
{
	v1->x = v1->x * k;
	v1->y = v1->y * k;
	v1->z = v1->z * k;
}

static t_vector3			vector3_div(const t_vector3 *v1, double k)
{
	t_vector3		result;

	result.x = v1->x / k;
	result.y = v1->y / k;
	result.z = v1->z / k;
	return (result);
}

static t_vector3			vector3_s_div(t_vector3 v1, double k)
{
	t_vector3		result;

	result.x = v1.x / k;
	result.y = v1.y / k;
	result.z = v1.z / k;
	return (result);
}

static void					vector3_div_eq(t_vector3 *v1, double k)
{
	v1->x = v1->x / k;
	v1->y = v1->y / k;
	v1->z = v1->z / k;
}

static void					vector3_rotate_x(t_vector3 *me, double theta)
{
	t_vector3		copy;

	copy = *me;
	me->y = copy.y * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.y * sinf(theta) + copy.z * cosf(theta);
}

static void					vector3_rotate_y(t_vector3 *me, double theta)
{
	t_vector3		copy;

	copy = *me;
	me->x = copy.x * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.x * sinf(theta) + copy.z * cosf(theta);
}

static t_vector3			vector3_abs(const t_vector3 *me)
{
	t_vector3		result;

	result.x = fabs(me->x);
	result.y = fabs(me->y);
	result.z = fabs(me->z);
	return (result);
}

static t_vector3			vector3_max(const t_vector3 *a, const t_vector3 *b)
{
	t_vector3		result;

	result.x = fmax(a->x, b->x);
	result.y = fmax(a->y, b->y);
	result.z = fmax(a->z, b->z);
	return (result);
}

static t_vector3			vector3_min(const t_vector3 *a, const t_vector3 *b)
{
	t_vector3		result;

	result.x = fmin(a->x, b->x);
	result.y = fmin(a->y, b->y);
	result.z = fmin(a->z, b->z);
	return (result);
}

static t_vector3			vector3_s_max(t_vector3 a, t_vector3 b)
{
	t_vector3		result;

	result.x = fmax(a.x, b.x);
	result.y = fmax(a.y, b.y);
	result.z = fmax(a.z, b.z);
	return (result);
}

static t_vector3			vector3_s_min(t_vector3 a, t_vector3 b)
{
	t_vector3		result;

	result.x = fmin(a.x, b.x);
	result.y = fmin(a.y, b.y);
	result.z = fmin(a.z, b.z);
	return (result);
}

static t_vector3			vector3_mod(const t_vector3 *v, double k)
{
	t_vector3		result;

	result.x = fmod(v->x, k);
	result.y = fmod(v->y, k);
	result.z = fmod(v->z, k);
	return (result);
}

static t_vector3			vector3_s_mod(t_vector3 v, double k)
{
	t_vector3		result;

	result.x = fmod(v.x, k);
	result.y = fmod(v.y, k);
	result.z = fmod(v.z, k);
	return (result);
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							VECTOR4
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 				s_vector4
{
	double 					x;
	double 					y;
	double 					z;
	double 					w;
}							t_vector4;

static t_vector4			vector4_cast3(const t_vector3 *source)
{
	return ((t_vector4){
			.x = source->x,
			.y = source->y,
			.z = source->z,
			.w = 0.});
}

static void					vector4_add_eq(t_vector4 *a, const t_vector4 *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	a->w += b->w;
}

static void					vector4_s_add_eq(t_vector4 *a, t_vector4 b)
{
	a->x += b.x;
	a->y += b.y;
	a->z += b.z;
	a->w += b.w;
}

static double 				vector4_dot(const t_vector4 *a, const t_vector4 *b)
{
	return (a->x * b->x +
			a->y * b->y +
			a->z * b->z +
			a->w * b->w);
}

static t_vector4 			vector4_square(const t_vector4 *v)
{
	return ((t_vector4){
			v->x * v->x - v->y * v->y - v->z * v->z - v->w * v->w,
			2. * v->x * v->y,
			2. * v->x * v->z,
			2. * v->x * v->w});
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							COLOR
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct				s_rgb
{
	unsigned char			b;
	unsigned char			g;
	unsigned char			r;
	unsigned char			a;
}							t_rgb;

typedef union				u_color
{
	int						mix;
	t_rgb					rgb;
}							t_color;

static int					color_unpack(t_vector3 vector)
{
	t_color         		color;
	double		 			*ptr;
	int 					counter;
	double		 			left;

	ptr = &vector.x;
	counter = 0;
	left = 0.;
	while (counter++ < 3)
	{
		if (*ptr > 1.)
		{
			left += *ptr - 1.;
			*ptr = 1.;
		}
		ptr++;
	}
	color.rgb.a = 0;
	color.rgb.r = (unsigned char)(255. * vector.x);
	color.rgb.g = (unsigned char)(255. * vector.y);
	color.rgb.b = (unsigned char)(255. * vector.z);
	return (color.mix);
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							RAY
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 				s_ray
{
	t_vector3				direction;
	t_vector3				position;
}							t_ray;

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							CAMERA
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 				s_camera
{
	t_vector3				position;
	const double			direction_length;
	t_vector3				direction;
	t_vector3				axis_x;
	t_vector3				axis_y;
	t_vector3				axis_z;
	t_vector3				vp_axis_x;
	t_vector3				vp_axis_y;
	t_vector3       		angles;
}							t_camera;

static t_ray				camera_cast_ray(constant t_camera *me, t_vector3 *vp_values)
{
	t_ray					result;
	t_vector3   			up;
	t_vector3   			right;
	t_vector3				point;

	right = me->vp_axis_x;
	up = me->vp_axis_y;
	vector3_mul_eq(&right, vp_values->x);
	vector3_mul_eq(&up, vp_values->y);
	point = vector3_add(&right, &up);
	result.direction = me->direction;
	vector3_add_eq(&result.direction, &point);
	vector3_normalize(&result.direction);
	result.position = me->position;
	return (result);
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							OBJECT
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

# define UNIT3				(t_vector3){1., 1., 1.}
# define ZERO3				(t_vector3){.0, .0, .0}

# define SDF_I_FREE			0
# define SDF_I_CUBE			1
# define SDF_I_R_SPHERE		2
# define SDF_I_TETRAHEDRON	3
# define SDF_I_MANDELBROT	4
# define SDF_I_MANDELBULB	5
# define SDF_I_JULIA		6

typedef struct s_object		t_object;

typedef struct				s_render_params
{
	double 					march_epsilon;
	double 					shadow_epsilon;
	double 					normal_epsilon;
	double 					step_ratio;
	double 					step_limit;
	double 					distance_limit;
}							t_render_params;

typedef struct				s_free_params
{
	t_render_params			render;
}							t_free_params;

typedef struct				s_cube_params
{
	t_render_params			render;
	int 					iterations;
}							t_cube_params;

typedef struct				s_r_sphere_params
{
	t_render_params			render;
}							t_r_sphere_params;

typedef struct				s_tetrahedron_params
{
	t_render_params			render;
	int						iterations;
	double					scale;
}							t_tetrahedron_params;

typedef struct				s_mandelbrot_params
{
	t_render_params			render;
	int						iterations;
	double 					bailout;
}							t_mandelbrot_params;

typedef struct				s_mandelbulb_params
{
	t_render_params			render;
	int						iterations;
	double 					power;
	double 					bailout;
}							t_mandelbulb_params;

typedef struct				s_julia_params
{
	t_render_params			render;
	int						iterations;
	t_vector4				value;
}							t_julia_params;

struct 						s_object
{
	int 					iter;
	const t_vector3			unit;
	t_free_params			free;
	t_cube_params			cube;
	t_r_sphere_params		r_sphere;
	t_tetrahedron_params	tetrahedron;
	t_mandelbrot_params		mandelbrot;
	t_mandelbulb_params		mandelbulb;
	t_julia_params			julia;
};

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							OBJECT PRIMITIVES
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static double 				sdf_plane(const t_vector3 *point)
{
	return (point->y);
}

static double 				sdf_box(t_vector3 size, const t_vector3 *point)
{
	t_vector3		temp;

	temp = vector3_abs(point);
	vector3_sub_eq(&temp, &size);
	return (vector3_s_length(vector3_s_max(temp, ZERO3)) + fmin(fmax(temp.x, fmax(temp.y, temp.z)), 0.));
}

static double				sdf_cross_inf(const t_vector3 *point)
{
	t_vector3		point_var;
	t_vector3		size;
	double 			d[3];

	size = (t_vector3){INFINITY, 1., 1.};
	point_var = (t_vector3){point->x, point->y, point->z};
	d[0] = sdf_box(size, &point_var);

	size = (t_vector3){1., INFINITY, 1.};
	point_var = (t_vector3){point->y, point->z, point->x};
	d[1] = sdf_box(size, &point_var);

	size = (t_vector3){1., 1., INFINITY};
	point_var = (t_vector3){point->z, point->x, point->y};
	d[2] = sdf_box(size, &point_var);
	return (fmin(d[0], fmin(d[1], d[2])));
}

static double 				sdf_sphere(t_vector3 center, const t_vector3 *point)
{
	t_vector3		temp;

	temp = vector3_sub(point, &center);
	return (vector3_length(&temp) - .3);
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							OBJECT COMPLEX
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static double 				sdf_free(constant t_object *obj, const t_vector3 *point)
{
	return (fmin(sdf_box((t_vector3)obj->unit, point), sdf_plane(point)));
}

static double 				sdf_cube(constant t_object *obj, const t_vector3 *point)
{
	double 			value;
	double 			cross_value;
	double 			cross_division;
	double 			cross_period;
	t_vector3		cross_shift;
	t_vector3		shifted_point;

	value = sdf_box((t_vector3)obj->unit, point);

	cross_period = 2.;
	cross_division = 3.;
	cross_shift = (t_vector3){1., 1., 1.};

	for (int i = 0; i < obj->cube.iterations; i++)
	{
		shifted_point = vector3_abs(point);

		shifted_point = vector3_add(&shifted_point, &cross_shift);
		shifted_point = vector3_mod(&shifted_point, cross_period);
		shifted_point = vector3_sub(&shifted_point, &cross_shift);

		shifted_point = vector3_mul(&shifted_point, cross_division);
		cross_value = sdf_cross_inf(&shifted_point) / cross_division;

		value = fmax(value, -1. * cross_value);

		cross_period /= 3.;
		vector3_div_eq(&cross_shift, 3.);
		cross_division *= 3.;
	}
	return (value);
}

static double 				sdf_repeated_sphere(constant t_object *obj, const t_vector3 *point)
{
	t_vector3		a;

	a = vector3_abs(point);
	a = vector3_mod(&a, 2.);
	a.y = point->y;
	return (sdf_sphere((t_vector3)obj->unit, &a));
}

static double 				sdf_tetrahedron(constant t_object *obj, const t_vector3 *point)
{
	t_vector3		vertex[4];
	t_vector3		c;
	t_vector3		p;
	double 			distance[2];

	vertex[0] = (t_vector3){1., 1., 1.};
	vertex[1] = (t_vector3){-1., -1., 1.};
	vertex[2] = (t_vector3){1., -1., -1.};
	vertex[3] = (t_vector3){-1., 1., -1.};
	p =  *point;
	for (int i = 0; i < obj->tetrahedron.iterations; i++)
	{
		c = vertex[0];
		distance[0] = vector3_s_length(vector3_sub(&p, vertex + 0));

		distance[1] = vector3_s_length(vector3_sub(&p, vertex + 1));
		if (distance[1] < distance[0])
		{
			c = vertex[1];
			distance[0] = distance[1];
		}

		distance[1] = vector3_s_length(vector3_sub(&p, vertex + 2));
		if (distance[1] < distance[0])
		{
			c = vertex[2];
			distance[0] = distance[1];
		}

		distance[1] = vector3_s_length(vector3_sub(&p, vertex + 3));
		if (distance[1] < distance[0])
		{
			c = vertex[3];
			distance[0] = distance[1];
		}

		p = vector3_mul(&p, obj->tetrahedron.scale);
		vector3_s_sub_eq(&p, vector3_mul(&c, obj->tetrahedron.scale - 1.));
	}
	return (vector3_length(&p) * pow(obj->tetrahedron.scale, (double)(-obj->tetrahedron.iterations)));
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							OBJECT FRACTALS
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static double 				sdf_mandelbulb(constant t_object *obj,const t_vector3 *point)
{
	t_vector3		z;
	double 			dr;
	double 			r;
	double 			theta;
	double 			phi;
	double 			zr;

	r = 0.;
	dr = 1.;
	z = *point;
	int i;
	for (i = 0; i < obj->mandelbulb.iterations; i++)
	{
		r = vector3_length(&z);
		if (r > obj->mandelbulb.bailout)
			break ;
		theta = acos(z.z / r);
		phi = atan2(z.y, z.x);
		dr = pow(r, obj->mandelbulb.power - 1.) * obj->mandelbulb.power * dr + 1.;

		zr = pow(r, obj->mandelbulb.power);
		theta *= obj->mandelbulb.power;
		phi *= obj->mandelbulb.power;

		z = vector3_s_mul((t_vector3){sin(theta) * cos(phi), sin(phi) * sin(theta), cos(theta)}, zr);
		vector3_add_eq(&z, point);
	}
	return (.5 * log(r) * r / dr);
}

static double 				sdf_mandelbrot(constant t_object *obj, const t_vector3 *point)
{
	t_vector3		z_current;
	t_vector3		z_next;
	double 			r;
	double			dr;

	r = 0.;
	z_current = *point;
	dr = 1.;
	int i;
	for (i = 0; i < obj->mandelbrot.iterations; i++)
	{
		r = vector3_length(&z_current);

		if (r > obj->mandelbrot.bailout)
			break ;
		z_next.x = (z_current.x * z_current.x + z_current.y * z_current.y - z_current.z * z_current.z) * (z_current.x * z_current.x - z_current.y * z_current.y) / (z_current.x * z_current.x + z_current.y * z_current.y);
		z_next.y = 2 * (z_current.x * z_current.x + z_current.y * z_current.y - z_current.z * z_current.z) * z_current.x * z_current.y / (z_current.x * z_current.x + z_current.y * z_current.y);
		z_next.z = -2 * z_current.z * sqrt(z_current.x * z_current.x + z_current.y * z_current.y);
		vector3_add_eq(&z_next, point);
		dr = r * 2. * dr + 1.;
		z_current = z_next;
	}
	return (.5 * log(r) * r / dr);
}

static double 				sdf_julia(constant t_object *obj, const t_vector3 *point)
{
	t_vector4 z;
	double md;
	double mz;

	z = vector4_cast3(point);
	md = 1.;
	mz = vector4_dot(&z, &z);

	for (int i = 0; i < obj->julia.iterations; i++) {
		md *= 4. * mz;
		z = vector4_square(&z);
		vector4_s_add_eq(&z, (t_vector4)obj->julia.value);
		mz = vector4_dot(&z, &z);
		if (mz > 4.)
			break;
	}
	return (.25 * sqrt(mz / md) * log(mz));
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							OBJECT PARAMS
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static constant t_render_params *object_params(constant t_object *obj)
{
	if (obj->iter == 0)
		return (&obj->free.render);
	else if (obj->iter == 1)
		return (&obj->cube.render);
	else if (obj->iter == 2)
		return (&obj->r_sphere.render);
	else if (obj->iter == 3)
		return (&obj->tetrahedron.render);
	else if (obj->iter == 4)
		return (&obj->mandelbrot.render);
	else if (obj->iter == 5)
		return (&obj->mandelbulb.render);
	else if (obj->iter == 6)
		return (&obj->julia.render);
	return (0);
}

static double 				object_call_sdf(constant t_object *obj, const t_vector3 *point)
{
	if (obj->iter == 0)
		return (sdf_free(obj, point));
	else if (obj->iter == 1)
		return (sdf_cube(obj, point));
	else if (obj->iter == 2)
		return (sdf_repeated_sphere(obj, point));
	else if (obj->iter == 3)
		return (sdf_tetrahedron(obj, point));
	else if (obj->iter == 4)
		return (sdf_mandelbrot(obj, point));
	else if (obj->iter == 5)
		return (sdf_mandelbulb(obj, point));
	else if (obj->iter == 6)
		return (sdf_julia(obj, point));
	return (0);
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							OBJECT NORMAL
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static t_vector3			object_normal
							(constant t_object *obj,
							constant t_render_params *obj_params,
							const t_vector3 *hit)
{
	t_vector3				nudged_hit;
	t_vector3				normal;
	t_vector3				normal_m;
	t_vector3				nudge;

	nudge = (t_vector3){obj_params->normal_epsilon, 0., 0.};
	nudged_hit = vector3_s_add(*hit, nudge);
	normal.x = object_call_sdf(obj, &nudged_hit);
	nudged_hit = vector3_s_sub(*hit, nudge);
	normal_m.x = object_call_sdf(obj, &nudged_hit);
	normal.x -= normal_m.x;

	nudge = (t_vector3){0., obj_params->normal_epsilon, 0.};
	nudged_hit = vector3_s_add(*hit, nudge);
	normal.y = object_call_sdf(obj, &nudged_hit);
	nudged_hit = vector3_s_sub(*hit, nudge);
	normal_m.y = object_call_sdf(obj, &nudged_hit);
	normal.y -= normal_m.y;

	nudge = (t_vector3){0., 0., obj_params->normal_epsilon};
	nudged_hit = vector3_s_add(*hit, nudge);
	normal.z = object_call_sdf(obj, &nudged_hit);
	nudged_hit = vector3_s_sub(*hit, nudge);
	normal_m.z = object_call_sdf(obj, &nudged_hit);
	normal.z -= normal_m.z;

	return (vector3_normalized(&normal));
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							LIGHT
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct				s_light
{
	t_vector3				direction;
	t_vector3				opposite;
	double 					intensity;
}							t_light;

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							SCENE
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

# define BACKGROUND			(t_vector3){.1, .1, .1}
# define AMBIENT_VALUE		0.1
# define COLOR				(t_vector3){.047, .227, .247}

typedef struct				s_scene
{
	int 					light_mod;
	t_light					lights[16];
	int 					lights_length;
	t_vector3				last_hit;
	int 					shadow_mod;
	double					shadow_ratio;
}							t_scene;

static double				scene_shadow
							(constant t_scene *scene,
							const t_ray *ray,
							constant t_object *obj,
							constant t_render_params *obj_params)
{
	t_vector3				step;
	t_vector3				move;
	int 					i;
	double 					distance;
	double 					total_distance;
	double 					result;

	total_distance = 0.;
	i = 0;
	result = 1.;
	step = vector3_mul(&ray->direction, obj_params->shadow_epsilon);
	move = vector3_add(&ray->position, &step);
	while (i < obj_params->step_limit)
	{
		if ((distance = object_call_sdf(obj, &move)) < obj_params->march_epsilon)
			return (0.);
		if (total_distance > obj_params->distance_limit)
			return (result);
		result = fmin(result, scene->shadow_ratio * distance / total_distance);
		total_distance += distance;
		step = vector3_mul(&ray->direction, total_distance);
		move = vector3_add(&ray->position, &step);
		i++;
	}
	return (result);
}

static int 					scene_light
							(constant t_scene *scene,
							constant t_object *obj,
							constant t_render_params *obj_params,
							t_vector3 *hit)
{
	int 			i;
	t_vector3		normal;
	double 			total_intensity;
	double 			current_intensity;
	double 			shadow_intensity;
	t_ray			shadow_ray;

	if (!scene->light_mod)
		return (color_unpack(COLOR));
	normal = object_normal(obj, obj_params, hit);
	total_intensity = 0.;
	i = 0;
	while (i < scene->lights_length)
	{
		current_intensity = vector3_s_dot(normal, (t_vector3)scene->lights[i].opposite);
		current_intensity *= scene->lights[i].intensity;
		if (scene->shadow_mod)
		{
			shadow_ray.position = *hit;
			shadow_ray.direction = scene->lights[i].opposite;
			shadow_intensity = scene_shadow(scene, &shadow_ray, obj, obj_params);
			if (obj->iter == SDF_I_MANDELBROT)
				shadow_intensity = fmax(.55, shadow_intensity);
			current_intensity *= shadow_intensity;
		}
		total_intensity += fmax(current_intensity, 0.);
		i++;
	}
	total_intensity = fmax(AMBIENT_VALUE, total_intensity);
	return (color_unpack(vector3_s_mul(COLOR, total_intensity)));
}

static int 					scene_march
							(constant t_scene *scene,
							const t_ray *ray,
							constant t_object *obj,
							constant t_render_params *obj_params,
							t_vector3 *hit)
{
	t_vector3				step;
	int 					i;
	double 					distance;
	double 					total_distance;

	*hit = ray->position;
	total_distance = 0.;
	i = 0;
	while (i < obj_params->step_limit)
	{
		distance = object_call_sdf(obj, hit);
		total_distance += obj_params->step_ratio * distance;
		step = vector3_mul(&ray->direction, total_distance);
		*hit = vector3_add(&ray->position, &step);
		if (distance < obj_params->march_epsilon)
			return (1);
		if (total_distance > obj_params->distance_limit)
			return (0);
		i++;
	}
	return (0);
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//							RAY MARCHING
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

kernel void					render(
							global int *image,
							constant t_camera *camera,
							constant t_object *object,
							constant t_scene *scene,
							constant int *width,
							constant int *height,
							global int *counter)
{
	int						global_id;
	t_vector3				screen;
	t_vector3				vp;
	t_ray					ray;
	t_vector3				hit;
	constant t_render_params		*obj_params;
	volatile global int*	counter_atomic = counter;

	global_id = get_global_id(0);

	screen.x = global_id % *width;
	screen.y = global_id / *width;
	vp.x = screen.x - (*width - 1.) / 2.;
	vp.y = -1 * screen.y + (*height - 1.) / 2.;
	ray = camera_cast_ray(camera, &vp);
	obj_params = object_params(object);
	if (scene_march(scene, &ray, object, obj_params, &hit))
		image[global_id] = scene_light(scene, object, obj_params, &hit);
	else
		image[global_id] = color_unpack(BACKGROUND);

	if (*counter_atomic == -1)
		return ;
	int						counter_copy = atomic_inc(counter_atomic);
	if (!(counter_copy % ((*width * *height) / 10)))
		printf("%d / 100 done\n", (counter_copy * 100) / (*width * *height));
}