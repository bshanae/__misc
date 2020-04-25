/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:08:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector3.h"
# include "vector4.h"

# define UNIT3				(t_vector3){1., 1., 1.}
# define ZERO3				(t_vector3){.0, .0, .0}
# define EPSILON			0.0001
# define NUDGE_X			(t_vector3){EPSILON, 0., 0.}
# define NUDGE_Y			(t_vector3){0., EPSILON, 0.}
# define NUDGE_Z			(t_vector3){0., 0., EPSILON}

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
	double					march_epsilon;
	double					shadow_epsilon;
	double					normal_epsilon;
	double					step_ratio;
	double					step_limit;
	double					distance_limit;
}							t_render_params;

typedef struct				s_free_params
{
	t_render_params			render;
}							t_free_params;

typedef struct				s_cube_params
{
	t_render_params			render;
	int						iterations;
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
	double					bailout;
}							t_mandelbrot_params;

typedef struct				s_mandelbulb_params
{
	t_render_params			render;
	int						iterations;
	double					power;
	double					bailout;
}							t_mandelbulb_params;

typedef struct				s_julia_params
{
	t_render_params			render;
	int						iterations;
	t_vector4				value;
}							t_julia_params;

struct						s_object
{
	int						iter;
	const t_vector3			unit;
	t_free_params			free;
	t_cube_params			cube;
	t_r_sphere_params		r_sphere;
	t_tetrahedron_params	tetrahedron;
	t_mandelbrot_params		mandelbrot;
	t_mandelbulb_params		mandelbulb;
	t_julia_params			julia;
};

t_object					*object_new();

void						object_delete(t_object **obj);

t_free_params				object_init_free();

t_cube_params				object_init_cube();

t_r_sphere_params			object_init_r_sphere();

t_tetrahedron_params		object_init_tetrahedron();

t_mandelbrot_params			object_init_mandelbrot();

t_mandelbulb_params			object_init_mandelbulb();

t_julia_params				object_init_julia();

#endif
