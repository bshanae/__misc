/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:58:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:59:10 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_BUTTON_H
# define GUI_BUTTON_H

# include "gui_widget_x.h"

typedef enum			e_gui_button_signal
{
	gui_button_signal_press = gui_widget_signal_end,
	gui_button_signal_release,
}						t_gui_button_signal;

typedef struct			s_gui_button
{
	t_gui_class_info	info;
	t_gui_widget		*parent;
	t_gui_ptr			child;
	t_global_bool		state_pressed;
	int					count_press;
}						t_gui_button;

t_gui_button			*gui_button_new(void);

t_global_bool			gui_button_callback_press(
	t_gui_widget *widget, void *ptr);
t_global_bool			gui_button_callback_release(
	t_gui_widget *widget, void *ptr);

t_global_bool			gui_button_test_press(
	t_gui_widget *widget, t_gui_event *event);
t_global_bool			gui_button_test_release(
	t_gui_widget *widget, t_gui_event *event);

#endif
