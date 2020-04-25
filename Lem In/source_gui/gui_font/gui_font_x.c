/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_font_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:44:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:44:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_font.h"

t_gui_font			gui_font_create(
	CHAR_REF source, int size, int style, t_gui_color color)
{
	t_gui_font font;

	font.data = TTF_OpenFont(source, size);
	global_assert(font.data != NULL, "GUI, Font : Source not found");
	TTF_SetFontStyle(font.data, style);
	font.color = (SDL_Color){color.r, color.g, color.b, 255};
	return (font);
}

void				gui_font_destroy(t_gui_font *font)
{
	TTF_CloseFont(font->data);
}
