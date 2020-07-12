/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:30:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:30:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_settings.h"

t_gui_settings		gui_settings_create(void)
{
	t_gui_settings	settings;

	settings.buffer_first = NULL;
	settings.buffer_second = NULL;
	settings.font_sans14 = NULL;
	settings.font_sans15 = NULL;
	settings.font_sans15_bold = NULL;
	return (settings);
}

void				gui_settings_destroy(t_gui_settings *settings)
{
	settings->buffer_first = NULL;
	settings->buffer_second = NULL;
	settings->font_sans14 = NULL;
	settings->font_sans15 = NULL;
	settings->font_sans15_bold = NULL;
}

void				gui_settings_set_buffers(t_gui_settings *settings, ...)
{
	va_list			args;

	va_start(args, settings);
	settings->buffer_first = va_arg(args, t_gui_buffer *);
	settings->buffer_second = va_arg(args, t_gui_buffer *);
	va_end(args);
}

void				gui_settings_set_fonts(t_gui_settings *settings, ...)
{
	va_list			args;

	va_start(args, settings);
	settings->font_sans14 = va_arg(args, t_gui_font *);
	settings->font_sans15 = va_arg(args, t_gui_font *);
	settings->font_sans15_bold = va_arg(args, t_gui_font *);
	va_end(args);
}

void				gui_settings_set_event(
	t_gui_settings *settings, SDL_Event *sdl)
{
	settings->event = gui_event_set(sdl);
}
