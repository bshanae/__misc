/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback_list_run.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:31:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:31:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_callback_list.h"

t_global_bool		gui_callback_list_run(
	t_gui_callback_list *list, void *widget)
{
	t_list_item		*item;
	t_gui_callback	*callback;

	item = list->data.begin;
	while (item)
	{
		callback = item->data;
		if (!callback->functor(widget, callback->ptr.ptr))
			return (global_false);
		item = item->next;
	}
	return (global_true);
}
