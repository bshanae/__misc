/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_complex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:05:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 17:42:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_free_params				object_init_free(void)
{
	t_free_params			free;

	free.render.march_epsilon = 0.001;
	free.render.normal_epsilon = 0.001;
	free.render.shadow_epsilon = 0.001;
	free.render.step_ratio = 1.;
	free.render.step_limit = 512;
	free.render.distance_limit = 100.;
	return (free);
}

t_cube_params				object_init_cube(void)
{
	t_cube_params			cube;

	cube.iterations = 6;
	cube.render.march_epsilon = 0.001;
	cube.render.normal_epsilon = 0.001;
	cube.render.shadow_epsilon = 5 * cube.render.march_epsilon;
	cube.render.step_ratio = 1.;
	cube.render.step_limit = 512;
	cube.render.distance_limit = 100.;
	return (cube);
}

t_r_sphere_params			object_init_r_sphere(void)
{
	t_r_sphere_params		sphere;

	sphere.render.march_epsilon = 0.0001;
	sphere.render.normal_epsilon = 0.01;
	sphere.render.shadow_epsilon = 0.1;
	sphere.render.step_ratio = .9;
	sphere.render.step_limit = 256;
	sphere.render.distance_limit = 5000.;
	return (sphere);
}

t_tetrahedron_params		object_init_tetrahedron(void)
{
	t_tetrahedron_params	tetrahedron;

	tetrahedron.iterations = 10;
	tetrahedron.scale = 1.875;
	tetrahedron.render.step_ratio = .6;
	tetrahedron.render.step_limit = 512;
	tetrahedron.render.march_epsilon = 0.005;
	tetrahedron.render.normal_epsilon = 0.001;
	tetrahedron.render.shadow_epsilon = 0.01;
	tetrahedron.render.distance_limit = 100.;
	return (tetrahedron);
}
