/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_main.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:53:20 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:53:20 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_MAIN_H
# define GUI_MAIN_H

# include "global_error.h"
# include "global_map.h"
# include "global_trace.h"
# include "gui_defines.h"
# include "g_settings.h"
# include "g_system.h"
# include "gui_sdl.h"
# include "gui_buffer.h"
# include "gui_font.h"
# include "gui_map_with_trace_x.h"
# include "gui_event.h"
# include "gui_system.h"
# include "gui_list_x.h"

typedef struct				s_gui_main_menu
{
	t_gui_widget			*menu_middle;
	t_global_bool			timer_is_started;
	t_global_bool			timer_render_request;
}							t_gui_main_menu;

typedef struct				s_gui_main
{
	t_gui_sdl				sdl;
	t_gui_map_with_trace	*map;
	t_gui_list				*list;
	t_gui_main_menu			menu;
}							t_gui_main;

void						*gui_main_new(int fd);
void						gui_main_delete(t_gui_main **data);

void						gui_main_render(t_gui_main *main);
void						gui_main_loop(t_gui_main *data);

Uint32						gui_main_callback_render(
	Uint32 interval, t_gui_main *main);
t_global_bool				gui_main_callback_list_select(
	t_gui_widget *widget, void *ptr);
t_global_bool				gui_main_callback_list_unselect(
	t_gui_widget *widget, void *ptr);
t_global_bool				gui_main_callback_menu_left(
	t_gui_widget *widget, void *ptr);
t_global_bool				gui_main_callback_menu_right(
	t_gui_widget *widget, void *ptr);
t_global_bool				gui_main_callback_menu_middle(
	t_gui_widget *widget, void *ptr);

#endif
