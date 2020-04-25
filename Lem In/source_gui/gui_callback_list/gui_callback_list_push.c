/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback_list_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:31:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:31:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_callback_list.h"

void				gui_callback_list_push(
	t_gui_callback_list *list, t_gui_callback callback)
{
	if (!list)
		return ;
	list_push(&list->data, &callback);
}
