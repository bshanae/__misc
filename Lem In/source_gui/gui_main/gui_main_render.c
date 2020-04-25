/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_main_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:57:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:57:57 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_main.h"

void				gui_main_render(t_gui_main *main)
{
	gui_map_with_trace_render(main->map);
	gui_sdl_prepare(&main->sdl);
	gui_sdl_render(&main->sdl);
}
