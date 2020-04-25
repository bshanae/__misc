/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:04:21 by ashari            #+#    #+#             */
/*   Updated: 2019/06/29 16:06:52 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easy.h"

t_easy				*easy_new(int width, int height)
{
	t_easy			*easy;

	if (!(easy = (t_easy *)malloc(sizeof(t_easy))))
		exit(21);
	easy->mod = 1;
	easy_new_mandelbrot(easy);
	easy_new_julia(easy);
	easy->width = width;
	easy->height = height;
	easy->palette = 0;
	return (easy);
}

void				easy_new_mandelbrot(t_easy *easy)
{
	easy->mandelbrot.scale = 1.;
	easy->mandelbrot.offset.x = 0.;
	easy->mandelbrot.offset.y = 0.;
	easy->mandelbrot.min.x = -3.;
	easy->mandelbrot.max.x = 2.;
	easy->mandelbrot.min.y = -1.5;
	easy->mandelbrot.max.y = 1.5;
	easy->mandelbrot.iterations = 200;
}

void				easy_new_julia(t_easy *easy)
{
	easy->julia.scale = 1.;
	easy->julia.offset.x = 0.;
	easy->julia.offset.y = 0.;
	easy->julia.min.x = -3.;
	easy->julia.max.x = 2.;
	easy->julia.min.y = -1.5;
	easy->julia.max.y = 1.5;
	easy->julia.c.x = 0.5;
	easy->julia.c.y = 0.2;
	easy->julia.iterations = 200;
	easy->julia.mod = -1;
}

void				easy_delete(t_easy **easy)
{
	free(*easy);
	*easy = NULL;
}
