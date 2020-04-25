/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_widget_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:39:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:39:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_widget_x.h"

void					gui_widget_delete(t_gui_widget **widget)
{
	int					i;
	t_gui_callback_list	**list;

	gui_ptr_release(&(*widget)->child);
	i = 0;
	while ((list = vector_at(&(*widget)->callback_store, i++)))
		gui_callback_list_delete(list);
	free(*widget);
	*widget = NULL;
}
