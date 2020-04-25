/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:08:42 by ashari            #+#    #+#             */
/*   Updated: 2019/06/29 17:26:09 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm.h"

void				easy_mandelbrot_scale(t_rm *rm, int x, int y)
{
	rm->easy->mandelbrot.scale *= 1.1;
	rm->easy->mandelbrot.offset.x += (x - WIN_WIDTH / 2)
		/ (rm->easy->mandelbrot.scale * WIN_WIDTH);
	rm->easy->mandelbrot.offset.y -= ((y - WIN_HEIGHT / 2)
		/ (rm->easy->mandelbrot.scale * WIN_HEIGHT));
}

void				easy_julia_scale(t_rm *rm, int x, int y)
{
	rm->easy->julia.scale *= 1.1;
	rm->easy->julia.offset.x += (x - WIN_WIDTH / 2)
		/ (rm->easy->julia.scale * WIN_WIDTH);
	rm->easy->julia.offset.y -= ((y - WIN_HEIGHT / 2)
		/ (rm->easy->julia.scale * WIN_HEIGHT));
}

void				calculate_z(t_easy *easy, int x, int y, t_vector2 *z)
{
	z->x = easy->julia.min.x + ((double)x / WIN_WIDTH)
		* (easy->julia.max.x - easy->julia.min.x);
	z->y = -(easy->julia.min.y + ((double)y / WIN_HEIGHT)
		* (easy->julia.max.y - easy->julia.min.y));
	z->x /= easy->julia.scale;
	z->y /= easy->julia.scale;
	z->x += easy->julia.offset.x;
	z->y += easy->julia.offset.y;
}

int					rm_mouse_move(int x, int y, t_rm *rm)
{
	t_vector2		z;

	if (rm->easy->mod != 1 || rm->mod != MOD_EASY || rm->easy->julia.mod < 0)
		return (0);
	calculate_z(rm->easy, x, y, &z);
	rm->easy->julia.c = z;
	rm_render(rm);
	return (0);
}

int					rm_mouse_scroll(int button, int x, int y, t_rm *rm)
{
	if (rm->mod != MOD_EASY)
		return (0);
	if (button == SCRL_DWN)
	{
		if (rm->easy->mod == 1)
			easy_julia_scale(rm, x, y);
		else if (rm->easy->mod == 2)
			easy_mandelbrot_scale(rm, x, y);
	}
	if (button == SCRL_UP)
	{
		if (rm->easy->mod == 1)
			rm->easy->julia.scale /= 1.1;
		else if (rm->easy->mod == 2)
			rm->easy->mandelbrot.scale /= 1.1;
	}
	rm_render(rm);
	return (0);
}
