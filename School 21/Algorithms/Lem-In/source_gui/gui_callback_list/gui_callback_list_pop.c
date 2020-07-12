/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback_list_pop.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:30:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:30:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_callback_list.h"

t_global_bool		gui_callback_list_pop(t_gui_callback_list *list)
{
	return ((t_global_bool)list_pop(&list->data));
}
