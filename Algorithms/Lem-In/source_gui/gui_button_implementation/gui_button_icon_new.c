/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_icon_new.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:05:12 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:20:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button_implementation.h"

static SDL_Surface			*helper_grey_surface(SDL_Surface *source)
{
	SDL_Surface				*result;
	int						x;
	int						y;
	SDL_Color				*color_source;
	SDL_Color				*color_result;

	result = SDL_CreateRGBSurfaceWithFormat(0,
		source->w, source->h, 32, source->format->format);
	SDL_BlitSurface(source, NULL, result, NULL);
	global_assert_critical(result != NULL, "GUI, SDL : Surface is NULL");
	x = 0;
	while (x < source->w)
	{
		y = 0;
		while (y < source->h)
		{
			color_source = (SDL_Color *)source->pixels + y * source->w + x;
			color_result = (SDL_Color *)result->pixels + y++ * result->w + x;
			*color_result = (SDL_Color){color_source->r * GUI_BUTTON_ICON_GREY,
				color_source->g * GUI_BUTTON_ICON_GREY,
				color_source->b * GUI_BUTTON_ICON_GREY, color_source->a};
		}
		x++;
	}
	return (result);
}

static void					helper_init_icons(
	t_gui_button_icon *data,
	CHAR_REF source_free, CHAR_REF source_pressed)
{
	if (!(data->surface_free = IMG_Load(source_free)))
		return (global_raise_warning("GUI, Icon button : Can't load icon"));
	data->surface_greyed = helper_grey_surface(data->surface_free);
	if (!source_pressed)
		data->surface_pressed = data->surface_free;
	else if (!(data->surface_pressed = IMG_Load(source_pressed)))
		return (global_raise_warning("GUI, Icon button : Can't load icon"));
}

static void					helper_init_rectangle(
	t_gui_button_icon *data,
	t_gui_object_point_i position,
	t_gui_object_point_i size)
{
	float					scale[2];

	scale[0] = (float)size.x / (float)data->surface_free->w;
	scale[1] = (float)size.y / (float)data->surface_free->h;
	if (scale[1] < scale[0])
		scale[0] = scale[1];
	size.x = (int)((float)data->surface_free->w * scale[0]);
	size.y = (int)((float)data->surface_free->h * scale[0]);
	data->rectangle_main.x = position.x - size.x / 2;
	data->rectangle_main.y = position.y - size.y / 2;
	data->rectangle_main.w = size.x;
	data->rectangle_main.h = size.y;
	data->rectangle_little.w = (int)((float)size.x * GUI_BUTTON_ICON_COMPRESS);
	data->rectangle_little.h = (int)((float)size.y * GUI_BUTTON_ICON_COMPRESS);
	data->rectangle_little.x = position.x - data->rectangle_little.w / 2;
	data->rectangle_little.y = position.y - data->rectangle_little.h / 2;
}

static void					helper_release(t_gui_button_icon *data)
{
	if (data->surface_free != data->surface_pressed)
		SDL_FreeSurface(data->surface_pressed);
	SDL_FreeSurface(data->surface_free);
	free(data);
}

t_gui_button_icon			*gui_button_icon_new(
	t_gui_object_point_i position, t_gui_object_point_i size,
	CHAR_REF source_free, CHAR_REF source_pressed)
{
	t_gui_widget			*widget;
	t_gui_button_rectangle	*rectangle;
	t_gui_button_icon		*icon;
	t_gui_callback			callback;

	rectangle = gui_button_rectangle_new(position, size);
	widget = gui_class_cast(rectangle, gui_class_type_widget);
	icon = global_malloc(sizeof(t_gui_button_icon));
	callback = gui_callback_set(gui_button_icon_render, NULL, NULL);
	gui_widget_callback_push(widget, gui_widget_signal_render, callback);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	gui_widget_callback_push(widget, gui_button_signal_press, callback);
	rectangle->child = gui_ptr_set(icon, (t_gui_ptr_release)helper_release);
	icon->info = gui_class_info_set(gui_class_type_button_icon);
	icon->parent = rectangle;
	helper_init_icons(icon, source_free, source_pressed);
	helper_init_rectangle(icon, position, size);
	return (icon);
}
