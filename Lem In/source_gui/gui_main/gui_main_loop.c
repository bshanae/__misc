/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:54:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:54:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_main.h"

void				gui_main_loop(t_gui_main *main)
{
	gui_main_render(main);
	while (1)
	{
		if (main->menu.timer_render_request)
		{
			gui_main_render(main);
			main->menu.timer_render_request = global_false;
		}
		if (!SDL_PollEvent(&main->sdl.event))
			continue ;
		gui_event_update(&g_settings.event);
		if (g_settings.event.type == gui_event_type_quit)
			break ;
		else if (gui_system_run_event(&g_system))
		{
			gui_sdl_prepare(&main->sdl);
			gui_sdl_render(&main->sdl);
		}
	}
	gui_sdl_timer_stop(&main->sdl);
}
