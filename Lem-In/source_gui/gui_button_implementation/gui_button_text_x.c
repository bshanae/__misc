/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_text_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:22:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:22:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button_implementation.h"

t_gui_button_text			*gui_button_text_new(
	t_gui_object_point_i position, t_gui_object_point_i size, CHAR_REF str)
{
	t_gui_widget			*widget;
	t_gui_button_rectangle	*rectangle;
	t_gui_button_text		*text;
	t_gui_callback			callback;

	rectangle = gui_button_rectangle_new(position, size);
	widget = gui_class_cast(rectangle, gui_class_type_widget);
	text = global_malloc(sizeof(t_gui_button_text));
	callback = gui_callback_set(gui_button_text_render, NULL, NULL);
	gui_widget_callback_push(widget, gui_widget_signal_render, callback);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	rectangle->child = gui_ptr_set(text, free);
	text->info = gui_class_info_set(gui_class_type_button_text);
	text->parent = rectangle;
	text->font_default = g_settings.font_sans15;
	text->font_selected = g_settings.font_sans15_bold;
	ft_strcpy(text->buffer, str);
	return (text);
}

static void					helper_print(
	t_gui_widget *widget, t_gui_button_rectangle *button_rectangle,
	t_gui_button_text *button_text, t_gui_font *font)
{
	SDL_Surface				*surface;
	SDL_Rect				rectangle;

	surface = TTF_RenderText_Blended(font->data,
		button_text->buffer, font->color);
	global_assert_critical(surface != NULL,
		"GUI, Text button : Can't render text");
	rectangle.w = button_rectangle->size.x;
	rectangle.h = button_rectangle->size.y;
	rectangle.x = button_rectangle->position.x - button_rectangle->size.x / 2;
	rectangle.y = button_rectangle->position.y - button_rectangle->size.y / 2;
	SDL_FillRect(widget->render_buffer->source,
		&rectangle, gui_color_to_sdl(widget->render_background));
	rectangle.x += GUI_LIST_TEXT_INDENT;
	SDL_BlitSurface(surface, NULL, widget->render_buffer->source, &rectangle);
	SDL_FreeSurface(surface);
}

t_global_bool				gui_button_text_render(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button			*button;
	t_gui_button_rectangle	*button_rectangle;
	t_gui_button_text		*button_text;

	button = gui_class_cast(widget, gui_class_type_button);
	button_rectangle = gui_class_cast(button, gui_class_type_button_rectangle);
	button_text = gui_class_cast(button_rectangle, gui_class_type_button_text);
	helper_print(widget, button_rectangle, button_text,
		button->count_press % 2 ?
		button_text->font_selected : button_text->font_default);
	gui_object_plot(gui_object_rectangle,
		widget->render_buffer, global_true,
		button_rectangle->position, button_rectangle->size,
		button->count_press % 2 ?
		gui_color_set(GUI_LIST_ITEM_COLOR_SELECTED) :
		gui_color_set(GUI_LIST_ITEM_COLOR),
	global_false);
	return (global_true);
}
