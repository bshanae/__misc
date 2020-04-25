/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_surface.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:31:19 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:31:36 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SURFACE_H
# define GUI_SURFACE_H

# include "gui_object.h"
# include "gui_widget_x.h"

typedef enum				e_gui_surface_signal
{
	gui_surface_signal_move = gui_widget_signal_end,
	gui_surface_signal_drag,
	gui_surface_signal_scroll,
	gui_surface_signal_end
}							t_gui_surface_signal;

typedef struct				s_gui_surface
{
	t_gui_class_info		info;
	t_gui_widget			*parent;
	t_gui_ptr				child;
	t_gui_object_point_i	min;
	t_gui_object_point_i	max;
}							t_gui_surface;

t_gui_surface				*gui_surface_new(
	t_gui_object_point_i min, t_gui_object_point_i max);

t_global_bool				gui_surface_test(
	t_gui_widget *widget, t_gui_object_point_i *cursor);
t_global_bool				gui_surface_test_move(
	t_gui_widget *widget, t_gui_event *event);
t_global_bool				gui_surface_test_drag(
	t_gui_widget *widget, t_gui_event *event);
t_global_bool				gui_surface_test_scroll(
	t_gui_widget *widget, t_gui_event *event);

t_global_bool				gui_surface_render(
	t_gui_widget *widget, void *ptr);

#endif
