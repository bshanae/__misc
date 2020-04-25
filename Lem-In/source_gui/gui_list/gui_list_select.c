/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:50:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:50:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_list_x.h"

void					gui_list_select(t_gui_list *list, int index)
{
	t_gui_widget		**widget2;

	if (!(widget2 = vector_at(&list->data.buttons, index)))
		return ;
	gui_widget_callback_run(*widget2, gui_button_signal_press,
		NULL, gui_widget_callback_flag_no_test);
	gui_widget_callback_run(*widget2, gui_button_signal_release,
		NULL, gui_widget_callback_flag_no_test);
}
