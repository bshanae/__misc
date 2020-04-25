/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_settings.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:51:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:51:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_LIST_SETTINGS_H
# define GUI_LIST_SETTINGS_H

# include "gui_defines.h"
# include "gui_object.h"

typedef struct						s_gui_list_settings_static
{
	t_gui_object_point_i			window_min;
	t_gui_object_point_i			window_max;
	t_gui_object_point_i			window_border;
	t_gui_color						window_color;
	int								button_spacing;
	t_gui_object_point_i			button_first;
	t_gui_object_point_i			button_next;
	t_gui_object_point_i			button_size;
}									t_gui_list_settings_static;

typedef struct						s_gui_list_settings
{
	t_gui_object_point_i			window_min;
	t_gui_object_point_i			window_max;
	t_gui_object_point_i			window_border;
	t_gui_color						window_color;
	int								button_spacing;
	int								button_height;
}									t_gui_list_settings;

t_gui_list_settings					gui_list_settings_build(
	t_gui_object_point_i min, t_gui_object_point_i max);
t_gui_list_settings_static			gui_list_settings_parse(
	t_gui_list_settings settings);

#endif
