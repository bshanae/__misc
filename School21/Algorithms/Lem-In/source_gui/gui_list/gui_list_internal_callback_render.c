/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_internal_callback_render.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:46:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:46:42 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_list_internal_x.h"

static void					helper_window_a(t_gui_list *list)
{
	t_gui_widget			*widget;

	widget = gui_class_cast(list, gui_class_type_widget);
	gui_object_plot(gui_object_rectangle,
		widget->render_buffer, global_false,
		list->settings.window_min, list->settings.window_max,
		widget->render_background, global_true);
}

static void					helper_window_b(t_gui_list *list)
{
	t_gui_widget			*widget;
	int						i;

	widget = gui_class_cast(list, gui_class_type_widget);
	i = 0;
	while (i < list->settings.window_border.x)
	{
		gui_object_plot(gui_object_line,
			widget->render_buffer,
			(t_gui_object_point_i){list->settings.window_min.x,
				list->settings.window_min.y + i},
			(t_gui_object_point_i){list->settings.window_max.x,
				list->settings.window_min.y + i},
			global_true, GUI_COLOR_WHITE, global_false);
		gui_object_plot(gui_object_line,
			widget->render_buffer,
			(t_gui_object_point_i){list->settings.window_min.x,
				list->settings.window_max.y - i},
			(t_gui_object_point_i){list->settings.window_max.x,
				list->settings.window_max.y - i},
			global_true, GUI_COLOR_WHITE, global_false);
		i++;
	}
}

static void					helper_window_c(t_gui_list *list)
{
	t_gui_widget			*widget;
	int						i;

	widget = gui_class_cast(list, gui_class_type_widget);
	i = 0;
	while (i < list->settings.window_border.y)
	{
		gui_object_plot(gui_object_line,
			widget->render_buffer,
			(t_gui_object_point_i){list->settings.window_min.x + i,
				list->settings.window_min.y},
			(t_gui_object_point_i){list->settings.window_min.x + i,
				list->settings.window_max.y},
			global_true, GUI_COLOR_WHITE, global_false);
		gui_object_plot(gui_object_line,
			widget->render_buffer,
			(t_gui_object_point_i){list->settings.window_max.x - i,
				list->settings.window_min.y},
			(t_gui_object_point_i){list->settings.window_max.x - i,
				list->settings.window_max.y},
			global_true, GUI_COLOR_WHITE, global_false);
		i++;
	}
}

static void					helper_buttons(t_gui_list *list)
{
	int						i;
	t_gui_widget			**widget;

	i = 0;
	while ((widget = vector_at(&list->data.buttons, i++)))
		gui_widget_callback_run(*widget, gui_widget_signal_render,
			NULL, gui_widget_callback_flag_no_test);
}

t_global_bool				gui_list_internal_callback_render(
	t_gui_widget *widget, void *ptr)
{
	t_gui_list				*list;

	list = gui_class_cast(widget, gui_class_type_list);
	helper_window_a(list);
	helper_window_b(list);
	helper_window_c(list);
	helper_buttons(list);
	return (global_true);
}
