/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_class.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:32:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:32:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CLASS_H
# define GUI_CLASS_H

# include "global_bool.h"
# include "gui_ptr.h"

typedef enum			e_gui_class_type
{
	gui_class_type_widget = 0,
	gui_class_type_button = 100,
	gui_class_type_surface = 101,
	gui_class_type_list = 200,
	gui_class_type_button_circle = 201,
	gui_class_type_button_rectangle = 202,
	gui_class_type_button_text = 300,
	gui_class_type_button_room = 400,
	gui_class_type_button_ant = 401,
	gui_class_type_button_list = 402,
	gui_class_type_button_icon = 403,
	gui_class_type_end = 1000,
}						t_gui_class_type;

typedef enum			e_gui_class_pattern
{
	gui_class_pattern_normal,
	gui_class_pattern_no_parent,
	gui_class_pattern_no_child,
	gui_class_pattern_unknown
}						t_gui_class_pattern;

t_gui_class_pattern		gui_class_pattern_get(t_gui_class_type type);

typedef struct			s_gui_class_info
{
	t_gui_class_pattern	pattern;
	t_gui_class_type	type;
}						t_gui_class_info;

t_gui_class_info		gui_class_info_set(t_gui_class_type type);

typedef struct			s_gui_class_pattern_normal
{
	t_gui_class_info	info;
	void				*parent;
	t_gui_ptr			child;
}						t_gui_class_pattern_normal;

typedef struct			s_gui_class_pattern_no_parent
{
	t_gui_class_info	info;
	t_gui_ptr			child;
}						t_gui_class_pattern_no_parent;

typedef struct			s_gui_class_pattern_no_child
{
	t_gui_class_info	info;
	void				*parent;
}						t_gui_class_pattern_no_child;

void					*gui_class_cast(
	void *object, t_gui_class_type target_type);

void					*gui_class_cast_directed(
	void *object, int direction, t_gui_class_type target_type);
void					*gui_class_cast_normal(
	void *object, int direction, t_gui_class_type target_type);
void					*gui_class_cast_no_parent(
	void *object, int direction, t_gui_class_type target_type);
void					*gui_class_cast_no_child(
	void *object, int direction, t_gui_class_type target_type);

#endif
