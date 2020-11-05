/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_render_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:07:47 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:07:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_map_x.h"

void				gui_map_render_front(t_gui_map *map)
{
	gui_buffer_copy_limited(map->back_buffer,
		g_settings.buffer_first, map->surface->min, map->surface->max);
}
