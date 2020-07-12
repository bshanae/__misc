/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_main_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:54:04 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:54:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_main.h"

void				gui_main_delete(t_gui_main **main)
{
	gui_sdl_destroy(&(*main)->sdl);
	gui_settings_destroy(&g_settings);
	gui_system_destroy(&g_system);
	gui_map_with_trace_delete(&(*main)->map);
	free(*main);
	*main = NULL;
}
