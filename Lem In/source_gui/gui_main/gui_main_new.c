/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_main_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:55:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:57:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_main.h"

static void				helper_list(t_gui_main *main, char *buffer)
{
	t_gui_widget		*list_widget;
	int					ant_i;
	t_gui_widget		**ant_ptr;
	char				*temp;
	t_gui_callback		callback;

	buffer[0] = 'L';
	ant_i = 1;
	list_widget = gui_class_cast(main->list, gui_class_type_widget);
	while (ant_i <= main->map->map->data.number_of_ants)
	{
		if (!(ant_ptr = vector_at(&main->map->trace->widgets, ant_i - 1)))
			global_raise_error("GUI, Main : Ant error");
		temp = ft_itoa(ant_i++);
		ft_strcpy(buffer + 1, temp);
		free(temp);
		gui_list_push(main->list, buffer, gui_ptr_set(*ant_ptr, NULL));
	}
	callback = gui_callback_set(gui_main_callback_list_select, NULL, NULL);
	gui_widget_callback_push(list_widget, gui_list_signal_select, callback);
	callback = gui_callback_set(gui_main_callback_list_unselect, NULL, NULL);
	gui_widget_callback_push(list_widget, gui_list_signal_unselect, callback);
	gui_widget_callback_run(list_widget,
		gui_widget_signal_render, NULL, gui_widget_callback_flag_no_test);
}

static void				helper_menu_middle(t_gui_main *main)
{
	t_gui_button_icon	*button;
	t_gui_widget		*widget;
	t_gui_callback		callback;

	gui_object_plot(gui_object_rectangle,
		g_settings.buffer_first, global_false,
		GUI_MENU_MIN, GUI_MENU_MAX,
		gui_color_set(GUI_MENU_COLOR), global_true);
	button = gui_button_icon_new(
		GUI_MENU_MIDDLE_POSITION, GUI_MENU_MIDDLE_SIZE,
		GUI_SOURCE_PLAY, GUI_SOURCE_PAUSE);
	widget = gui_class_cast(button, gui_class_type_widget);
	widget->render_background = gui_color_set(GUI_MENU_COLOR);
	callback = gui_callback_set(gui_main_callback_menu_middle, main, NULL);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	gui_widget_callback_run(widget, gui_widget_signal_render,
		NULL, gui_widget_callback_flag_no_test);
	main->menu.menu_middle = widget;
}

static void				helper_menu_left(t_gui_main *main)
{
	t_gui_button_icon	*button;
	t_gui_widget		*widget;
	t_gui_callback		callback;

	button = gui_button_icon_new(
		GUI_MENU_LEFT_POSITION, GUI_MENU_LEFT_SIZE,
		GUI_SOURCE_LEFT, NULL);
	widget = gui_class_cast(button, gui_class_type_widget);
	widget->render_background = gui_color_set(GUI_MENU_COLOR);
	callback = gui_callback_set(gui_main_callback_menu_left, main, NULL);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	gui_widget_callback_run(widget, gui_widget_signal_render,
		NULL, gui_widget_callback_flag_no_test);
}

static void				helper_menu_right(t_gui_main *main)
{
	t_gui_button_icon	*button;
	t_gui_widget		*widget;
	t_gui_callback		callback;

	button = gui_button_icon_new(
		GUI_MENU_RIGHT_POSITION, GUI_MENU_RIGHT_SIZE,
		GUI_SOURCE_RIGHT, NULL);
	widget = gui_class_cast(button, gui_class_type_widget);
	widget->render_background = gui_color_set(GUI_MENU_COLOR);
	callback = gui_callback_set(gui_main_callback_menu_right, main, NULL);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	gui_widget_callback_run(widget, gui_widget_signal_render,
		NULL, gui_widget_callback_flag_no_test);
}

void					*gui_main_new(int fd)
{
	t_gui_main			*main;
	t_gui_list_settings	list_settings;
	char				buffer[16];

	main = global_malloc(sizeof(t_gui_main));
	main->sdl = gui_sdl_create(GUI_WIDTH, GUI_HEIGHT);
	g_settings = gui_settings_create();
	gui_settings_set_buffers(&g_settings,
		main->sdl.buffer_first, main->sdl.buffer_second);
	gui_settings_set_fonts(&g_settings, &main->sdl.font_sans14,
		&main->sdl.font_sans15, &main->sdl.font_sans15_bold);
	gui_settings_set_event(&g_settings, &main->sdl.event);
	g_system = gui_system_create();
	list_settings = gui_list_settings_build(GUI_LIST_MIN, GUI_LIST_MAX);
	list_settings.window_border = (t_gui_object_point_i){0, 0};
	list_settings.window_color = gui_color_set(GUI_LIST_BACKGROUND);
	main->list = gui_list_new(list_settings);
	main->map = gui_map_with_trace_new(fd, main->list);
	helper_list(main, buffer);
	helper_menu_middle(main);
	helper_menu_left(main);
	helper_menu_right(main);
	main->menu.timer_is_started = global_false;
	return (main);
}
