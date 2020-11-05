/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_fractal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:06:19 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_mandelbrot_params			object_init_mandelbrot(void)
{
	t_mandelbrot_params		mandelbrot;

	mandelbrot.iterations = 100;
	mandelbrot.bailout = 2.;
	mandelbrot.render.march_epsilon = 0.0007;
	mandelbrot.render.normal_epsilon = 0.007;
	mandelbrot.render.shadow_epsilon = 0.1;
	mandelbrot.render.step_ratio = .5;
	mandelbrot.render.step_limit = 512;
	mandelbrot.render.distance_limit = 10.;
	return (mandelbrot);
}

t_mandelbulb_params			object_init_mandelbulb(void)
{
	t_mandelbulb_params		mandelbulb;

	mandelbulb.iterations = 50;
	mandelbulb.power = 8.;
	mandelbulb.bailout = 2.;
	mandelbulb.render.distance_limit = 50.;
	mandelbulb.render.march_epsilon = 0.001;
	mandelbulb.render.normal_epsilon = 0.001;
	mandelbulb.render.shadow_epsilon = 0.1;
	mandelbulb.render.step_limit = 512;
	mandelbulb.render.step_ratio = .4;
	return (mandelbulb);
}

t_julia_params				object_init_julia(void)
{
	t_julia_params			julia;

	julia.iterations = 50;
	julia.value = (t_vector4){.1, .3, .5, .5};
	julia.render.march_epsilon = 0.001;
	julia.render.normal_epsilon = 0.01;
	julia.render.shadow_epsilon = 0.1;
	julia.render.step_ratio = .6;
	julia.render.step_limit = 512;
	julia.render.distance_limit = 10.;
	return (julia);
}
