/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback_list_delete.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:31:32 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:31:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_callback_list.h"

void				gui_callback_list_delete(t_gui_callback_list **list)
{
	t_list_item		*iter;
	t_list_item		*next;
	t_gui_callback	*callback;

	if (*list == NULL)
		return ;
	iter = (*list)->data.begin;
	while (iter)
	{
		next = iter->next;
		callback = iter->data;
		gui_callback_release(callback);
		iter = next;
	}
	list_destroy(&(*list)->data);
	free(*list);
	*list = NULL;
}
