/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback_list_new.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:31:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:31:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_callback_list.h"

t_gui_callback_list		*gui_callback_list_new(t_gui_callback_list_test test)
{
	t_gui_callback_list	*list;

	list = global_malloc(sizeof(t_gui_callback_list));
	list->test = test;
	list->data = list_create(sizeof(t_gui_callback));
	return (list);
}
