/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:43:30 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:43:30 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_COLOR_H
# define GUI_COLOR_H

# include "libft_standart.h"

# include <SDL.h>

typedef struct					s_gui_color
{
	UCHAR						a;
	UCHAR						b;
	UCHAR						g;
	UCHAR						r;
}								t_gui_color;

# define GUI_COLOR_WHITE		(t_gui_color){255, 255, 255, 255}
# define GUI_COLOR_BLACK		(t_gui_color){0, 0, 0, 0}
# define GUI_COLOR_RED			(t_gui_color){255, 0, 0, 255}

t_gui_color						gui_color_set(int r, int g, int b);

t_gui_color						gui_color_mul(t_gui_color color, float k);
t_gui_color						gui_color_blend(
	t_gui_color left, t_gui_color right, float alpha);

Uint32							gui_color_to_sdl(t_gui_color color);

#endif
