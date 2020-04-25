/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_color_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:43:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:43:38 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_color.h"

t_gui_color			gui_color_set(int r, int g, int b)
{
	return ((t_gui_color){255, b, g, r});
}

t_gui_color			gui_color_mul(t_gui_color color, float k)
{
	color.r = (UCHAR)((float)color.r * k);
	color.g = (UCHAR)((float)color.g * k);
	color.b = (UCHAR)((float)color.b * k);
	color.a = (UCHAR)((float)color.a * k);
	return (color);
}

t_gui_color			gui_color_blend(
	t_gui_color left, t_gui_color right, float alpha)
{
	t_gui_color		result;

	result = left;
	result.r = (UCHAR)((float)result.r * (1 - alpha) + (float)right.r * alpha);
	result.g = (UCHAR)((float)result.g * (1 - alpha) + (float)right.g * alpha);
	result.b = (UCHAR)((float)result.b * (1 - alpha) + (float)right.b * alpha);
	result.a = 255;
	return (result);
}

Uint32				gui_color_to_sdl(t_gui_color color)
{
	return (*(Uint32 *)&color);
}
