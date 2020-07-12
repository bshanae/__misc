/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_system_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:34:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:34:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_system.h"

void				gui_system_remove(t_gui_system *system, int index)
{
	t_gui_widget	**widget;

	if (index < 0 || index >= system->data.length)
		return ;
	widget = vector_at(&system->data, index);
	gui_widget_delete(widget);
	vector_erase(&system->data, index);
}
