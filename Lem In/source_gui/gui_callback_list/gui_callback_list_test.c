/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback_list_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:31:20 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:31:20 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_callback_list.h"

t_global_bool		gui_callback_list_test(
	t_gui_callback_list *list, void *widget, t_gui_event *event)
{
	if (!event || !list->test)
		return (global_false);
	if (!list->test(widget, event))
		return (global_false);
	return (global_true);
}
