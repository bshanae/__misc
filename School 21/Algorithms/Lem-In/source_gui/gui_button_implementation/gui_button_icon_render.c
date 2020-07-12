/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_icon_render.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:00:06 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:00:06 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button_implementation.h"

t_global_bool			gui_button_icon_render(t_gui_widget *widget, void *ptr)
{
	t_gui_button		*button;
	t_gui_button_icon	*button_icon;

	button = gui_class_cast(widget, gui_class_type_button);
	button_icon = gui_class_cast(button, gui_class_type_button_icon);
	SDL_FillRect(widget->render_buffer->source, &button_icon->rectangle_main,
		gui_color_to_sdl(widget->render_background));
	if (!widget->state_sensitive)
		SDL_BlitScaled(button_icon->surface_greyed, NULL,
			widget->render_buffer->source, &button_icon->rectangle_main);
	else if (button->count_press % 2 == 1 && button->state_pressed)
		SDL_BlitScaled(button_icon->surface_free, NULL,
			widget->render_buffer->source, &button_icon->rectangle_little);
	else if (button->count_press % 2 == 1 && !button->state_pressed)
		SDL_BlitScaled(button_icon->surface_pressed, NULL,
			widget->render_buffer->source, &button_icon->rectangle_main);
	else if (button->count_press % 2 == 0 && button->state_pressed)
		SDL_BlitScaled(button_icon->surface_pressed, NULL,
			widget->render_buffer->source, &button_icon->rectangle_little);
	else if (button->count_press % 2 == 0 && !button->state_pressed)
		SDL_BlitScaled(button_icon->surface_free, NULL,
			widget->render_buffer->source, &button_icon->rectangle_main);
	return (global_true);
}
