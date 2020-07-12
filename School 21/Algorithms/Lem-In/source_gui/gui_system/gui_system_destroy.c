/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_system_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:33:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:34:01 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_system.h"

void				gui_system_destroy(t_gui_system *system)
{
	int				i;
	t_gui_widget	**widget;

	i = 0;
	while ((widget = vector_at(&system->data, i++)))
		gui_widget_delete(widget);
	vector_destroy(&system->data);
}
