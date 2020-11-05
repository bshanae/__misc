/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:07:02 by ashari            #+#    #+#             */
/*   Updated: 2019/06/29 16:10:52 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_H
# define EASY_H

# include "vector2.h"

# include <stdlib.h>

typedef struct				s_julia
{
	t_vector2				min;
	t_vector2				max;
	t_vector2				offset;
	t_vector2				c;
	double					scale;
	int						iterations;
	int						mod;
}							t_julia;

typedef struct				s_mandelbrot
{
	t_vector2				min;
	t_vector2				max;
	t_vector2				offset;
	double					scale;
	int						iterations;
}							t_mandelbrot;

typedef	struct				s_easy
{
	t_mandelbrot			mandelbrot;
	t_julia					julia;
	int						mod;
	int						width;
	int						height;
	int						palette;
}							t_easy;

t_easy						*easy_new(int width, int height);

void						easy_new_mandelbrot(t_easy *easy);

void						easy_new_julia(t_easy *easy);

void						easy_delete(t_easy **easy);

#endif
