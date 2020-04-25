/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_class_cast_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:33:16 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:42:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_class.h"

#define IDK							gui_class_cast_directed

void								*gui_class_cast_directed(
	void *object, int direction, t_gui_class_type target_type)
{
	t_gui_class_info				*info;

	if (!object)
		return (NULL);
	info = object;
	if (info->type == target_type)
		return (object);
	if (info->pattern == gui_class_pattern_normal)
		return (gui_class_cast_normal(object, direction, target_type));
	if (info->pattern == gui_class_pattern_no_parent)
		return (gui_class_cast_no_parent(object, direction, target_type));
	if (info->pattern == gui_class_pattern_no_child)
		return (gui_class_cast_no_child(object, direction, target_type));
	return (NULL);
}

void								*gui_class_cast_normal(
	void *object, int direction, t_gui_class_type target_type)
{
	t_gui_class_pattern_normal		*class;

	class = object;
	if (class->info.type == target_type)
		return (object);
	if (direction < 0 && target_type < class->info.type)
		return (IDK(class->parent, direction, target_type));
	if (direction > 0 && target_type > class->info.type)
		return (IDK(class->child.ptr, direction, target_type));
	return (NULL);
}

void								*gui_class_cast_no_parent(
	void *object, int direction, t_gui_class_type target_type)
{
	t_gui_class_pattern_no_parent	*class;

	class = object;
	if (class->info.type == target_type)
		return (object);
	if (direction > 0 && target_type > class->info.type)
		return (IDK(class->child.ptr, direction, target_type));
	return (NULL);
}

void								*gui_class_cast_no_child(
	void *object, int direction, t_gui_class_type target_type)
{
	t_gui_class_pattern_no_child	*class;

	class = object;
	if (class->info.type == target_type)
		return (object);
	if (direction < 0 && target_type < class->info.type)
		return (gui_class_cast_directed(class->parent, direction, target_type));
	return (NULL);
}
