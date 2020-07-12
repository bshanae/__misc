/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_test_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:59:08 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:59:08 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button.h"

t_global_bool			gui_button_test_press(
	t_gui_widget *widget, t_gui_event *event)
{
	return (event->type == gui_event_type_press);
}

t_global_bool			gui_button_test_release(
	t_gui_widget *widget, t_gui_event *event)
{
	return (event->type == gui_event_type_release);
}
