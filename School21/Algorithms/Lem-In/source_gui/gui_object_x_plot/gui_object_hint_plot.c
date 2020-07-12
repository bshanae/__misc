/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_hint_plot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:20:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:20:10 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

static void					helper_text_load(t_gui_object_hint_data *data)
{
	data->text_surface = TTF_RenderText_Blended(data->text_font->data,
		data->text_name, data->text_font->color);
	global_assert_critical(data->text_surface != NULL,
		"GUI, Hint : Can't render text");
	data->width =
		ft_max(data->text_surface->w, GUI_OBJECT_HINT_RECT_WIDTH_MIN) + 6;
}

static void					helper_text_copy(t_gui_object_hint_data *data)
{
	SDL_Rect				rectangle;

	rectangle.w = data->text_surface->w;
	rectangle.h = data->text_surface->h;
	rectangle.x = data->lower_point.x - rectangle.w / 2;
	rectangle.y = data->lower_point.y - GUI_OBJECT_HINT_TRI_HEIGHT
		- GUI_OBJECT_HINT_RECT_HEIGHT / 2 - rectangle.h / 2;
	SDL_BlitSurface(data->text_surface, NULL, data->buffer->source, &rectangle);
	SDL_FreeSurface(data->text_surface);
}

void						gui_object_hint_plot(
	const t_gui_object_hint_bundle *bundle)
{
	t_gui_object_hint_data	data;

	data.buffer = bundle->buffer;
	data.lower_point = bundle->lower_point;
	data.text_font = bundle->font;
	data.text_name = bundle->name;
	data.text_surface = NULL;
	helper_text_load(&data);
	gui_object_hint_helper_corners(&data);
	gui_object_hint_helper_rectangle(&data);
	gui_object_hint_helper_triangle(&data);
	gui_object_hint_helper_borders(&data);
	helper_text_copy(&data);
}
