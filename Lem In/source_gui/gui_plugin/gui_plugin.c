/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_plugin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:26:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:26:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_plugin.h"

t_gui_plugin		*global_room_plugin_new(t_gui_widget *widget)
{
	t_gui_plugin	*new;

	new = global_malloc(sizeof(t_gui_plugin));
	new->highlight = global_false;
	new->widget = widget;
	return (new);
}
