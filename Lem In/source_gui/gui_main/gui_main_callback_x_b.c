/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_main_callback_x_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:53:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:53:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_main.h"

t_global_bool			gui_main_callback_menu_left(
	t_gui_widget *widget, void *ptr)
{
	t_gui_main			*main;

	main = ptr;
	main->map->trace->work_block = global_true;
	gui_trace_step_back(main->map->trace);
	gui_main_render(main);
	main->map->trace->work_block = global_false;
	return (global_true);
}

t_global_bool			gui_main_callback_menu_right(
	t_gui_widget *widget, void *ptr)
{
	t_gui_main			*main;

	main = ptr;
	main->map->trace->work_block = global_true;
	gui_trace_step_forward(main->map->trace);
	gui_main_render(main);
	main->map->trace->work_block = global_false;
	return (global_true);
}

t_global_bool			gui_main_callback_menu_middle(
	t_gui_widget *widget, void *ptr)
{
	t_gui_main			*main;

	main = ptr;
	main->map->trace->work_block = global_true;
	if (!main->menu.timer_is_started)
	{
		gui_sdl_timer_start(&main->sdl, GUI_RENDER_RATE,
			(SDL_TimerCallback)gui_main_callback_render, main);
		main->menu.timer_is_started = global_true;
		main->map->trace->work_block = global_false;
		return (global_true);
	}
	main->map->trace->render_state =
		main->map->trace->render_state == gui_trace_rendering ?
		gui_trace_paused : gui_trace_rendering;
	gui_main_render(main);
	main->map->trace->work_block = global_false;
	return (global_true);
}
