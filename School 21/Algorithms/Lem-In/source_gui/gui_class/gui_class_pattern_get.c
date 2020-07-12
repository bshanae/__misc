/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_class_pattern_get.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:33:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:33:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_class.h"

static void						helper_init(t_gui_class_pattern *store)
{
	int							i;

	i = 0;
	while (i < gui_class_type_end)
		store[i++] = gui_class_pattern_unknown;
	store[gui_class_type_widget] = gui_class_pattern_no_parent;
	store[gui_class_type_button] = gui_class_pattern_normal;
	store[gui_class_type_surface] = gui_class_pattern_normal;
	store[gui_class_type_list] = gui_class_pattern_no_child;
	store[gui_class_type_button_circle] = gui_class_pattern_normal;
	store[gui_class_type_button_rectangle] = gui_class_pattern_normal;
	store[gui_class_type_button_text] = gui_class_pattern_normal;
	store[gui_class_type_button_room] = gui_class_pattern_no_child;
	store[gui_class_type_button_ant] = gui_class_pattern_no_child;
	store[gui_class_type_button_list] = gui_class_pattern_no_child;
	store[gui_class_type_button_icon] = gui_class_pattern_no_child;
}

t_gui_class_pattern				gui_class_pattern_get(t_gui_class_type type)
{
	static t_global_bool		is_initialized;
	static t_gui_class_pattern	store[gui_class_type_end];

	if (!is_initialized)
	{
		helper_init(store);
		is_initialized = global_true;
	}
	if (type >= gui_class_type_end)
	{
		global_raise_error("GUI, Class : Incorrect type");
		return (gui_class_pattern_unknown);
	}
	return (store[type]);
}
