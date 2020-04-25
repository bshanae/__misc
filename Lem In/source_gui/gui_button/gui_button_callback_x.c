/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_callback_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:59:19 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:59:19 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button.h"

t_global_bool		gui_button_callback_press(t_gui_widget *widget, void *ptr)
{
	t_gui_button	*button;

	button = gui_class_cast(widget, gui_class_type_button);
	button->state_pressed = global_true;
	button->count_press++;
	return (global_true);
}

t_global_bool		gui_button_callback_release(t_gui_widget *widget, void *ptr)
{
	t_gui_button	*button;

	button = gui_class_cast(widget, gui_class_type_button);
	button->state_pressed = global_false;
	return (global_true);
}
