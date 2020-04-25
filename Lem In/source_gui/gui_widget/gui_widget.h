/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_widget.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:38:07 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:38:49 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_WIDGET_H
# define GUI_WIDGET_H

# include "gui_ptr.h"
# include "gui_object_x.h"
# include "gui_callback_list.h"
# include "gui_class.h"

typedef enum					e_gui_widget_signal
{
	gui_widget_signal_render = 0,
	gui_widget_signal_end
}								t_gui_widget_signal;

typedef enum					e_gui_widget_callback_flag
{
	gui_widget_callback_flag_none = 0,
	gui_widget_callback_flag_ignore_sensitive = 0x1,
	gui_widget_callback_flag_ignore_block = 0x10,
	gui_widget_callback_flag_no_test = 0x100
}								t_gui_widget_callback_flag;

struct s_gui_widget;

typedef t_global_bool			(*t_gui_widget_surface_test)(
	struct s_gui_widget *widget, t_gui_object_point_i *cursor);

typedef struct					s_gui_widget
{
	t_gui_class_info			info;
	t_gui_ptr					child;
	t_gui_widget_surface_test	surface_test;
	t_gui_buffer				*render_buffer;
	t_gui_color					render_background;
	t_vector					callback_store;
	t_global_bool				state_blocked;
	t_global_bool				state_sensitive;
}								t_gui_widget;

#endif
