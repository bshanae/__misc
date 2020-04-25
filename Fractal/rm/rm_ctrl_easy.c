/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_easy_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:15:09 by ashari            #+#    #+#             */
/*   Updated: 2019/06/29 16:16:34 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm.h"

int					rm_ctrl_easy(t_rm *me, int key)
{
	if (me->mod != MOD_EASY)
		return (0);
	if (me->easy->mod == 1 && rm_ctrl_easy_julia(me, key))
		;
	else if (me->easy->mod == 2 && rm_ctrl_easy_mandelbrot(me, key))
		;
	else if (key == KEY_P)
	{
		if (++me->easy->palette == 5)
			me->easy->palette = 0;
	}
	else
		return (0);
	return (1);
}

int					rm_ctrl_easy_mandelbrot(t_rm *me, int key)
{
	if (key == KEY_PLUS_1 && me->easy->mandelbrot.iterations < EASY_MAX_ITER)
		me->easy->mandelbrot.iterations += 50;
	else if (key == KEY_MINUS_1 && me->easy->mandelbrot.iterations > 100)
		me->easy->mandelbrot.iterations -= 50;
	else if (key == KEY_D)
		me->easy->mandelbrot.offset.x += 0.5 / me->easy->mandelbrot.scale;
	else if (key == KEY_A)
		me->easy->mandelbrot.offset.x -= 0.5 / me->easy->mandelbrot.scale;
	else if (key == KEY_W)
		me->easy->mandelbrot.offset.y += 0.5 / me->easy->mandelbrot.scale;
	else if (key == KEY_S)
		me->easy->mandelbrot.offset.y -= 0.5 / me->easy->mandelbrot.scale;
	else
		return (0);
	return (1);
}

int					rm_ctrl_easy_julia(t_rm *me, int key)
{
	if (key == KEY_PLUS_1 && me->easy->julia.iterations < EASY_MAX_ITER)
		me->easy->julia.iterations += 50;
	else if (key == KEY_MINUS_1 && me->easy->julia.iterations > 100)
		me->easy->julia.iterations -= 50;
	else if (key == KEY_C)
		me->easy->julia.mod *= -1;
	else if (key == KEY_D)
		me->easy->julia.offset.x += 0.5 / me->easy->julia.scale;
	else if (key == KEY_A)
		me->easy->julia.offset.x -= 0.5 / me->easy->julia.scale;
	else if (key == KEY_W)
		me->easy->julia.offset.y += 0.5 / me->easy->julia.scale;
	else if (key == KEY_S)
		me->easy->julia.offset.y -= 0.5 / me->easy->julia.scale;
	else
		return (0);
	return (1);
}
