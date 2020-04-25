/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:05:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:05:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_MAP_H
# define GUI_MAP_H

# include "global_map.h"
# include "gui_defines.h"
# include "g_settings.h"
# include "gui_plugin.h"
# include "gui_color.h"
# include "gui_buffer.h"
# include "gui_font.h"
# include "gui_object.h"
# include "gui_surface.h"
# include "gui_system.h"

# include "libft_queue.h"

typedef struct				s_gui_map
{
	t_gui_surface			*surface;
	t_gui_widget			*surface_widget;
	t_gui_buffer			*back_buffer;
	t_global_map			data;
	t_vector				widgets;
	t_vector				widgets_rendered;
	t_gui_object_point_i	min;
	t_gui_object_point_i	max;
}							t_gui_map;

typedef enum				e_gui_state
{
	gui_state_not_visited,
	gui_state_visited
}							t_gui_state;

#endif
