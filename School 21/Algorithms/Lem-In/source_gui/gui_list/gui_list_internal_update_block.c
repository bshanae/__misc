/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_internal_update_block.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:48:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:48:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_list_internal_x.h"

void						gui_list_internal_update_block(
	t_gui_list *list, t_gui_widget *widget)
{
	t_gui_button_rectangle	*rectangle;

	widget->state_blocked = global_false;
	rectangle = gui_class_cast(widget, gui_class_type_button_rectangle);
	if (rectangle->position.y - rectangle->size.y / 2
		<= list->settings.window_min.y)
		widget->state_blocked = global_true;
	if (rectangle->position.y + rectangle->size.y / 2
		>= list->settings.window_max.y)
		widget->state_blocked = global_true;
}
