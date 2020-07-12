/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:30:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:30:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SETTINGS_H
# define GUI_SETTINGS_H

# include "gui_buffer.h"
# include "gui_font.h"
# include "gui_event.h"

typedef struct		s_gui_settings
{
	t_gui_buffer	*buffer_first;
	t_gui_buffer	*buffer_second;
	t_gui_font		*font_sans14;
	t_gui_font		*font_sans15;
	t_gui_font		*font_sans15_bold;
	t_gui_event		event;
}					t_gui_settings;

t_gui_settings		gui_settings_create(void);
void				gui_settings_destroy(t_gui_settings *settings);

void				gui_settings_set_buffers(t_gui_settings *settings, ...);
void				gui_settings_set_fonts(t_gui_settings *settings, ...);
void				gui_settings_set_event(
	t_gui_settings *settings, SDL_Event *sdl);

#endif
