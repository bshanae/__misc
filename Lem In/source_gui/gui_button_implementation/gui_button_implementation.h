/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_implementation.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:02:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:02:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_BUTTON_IMPLEMENTATION_H
# define GUI_BUTTON_IMPLEMENTATION_H

# include "global_bool.h"
# include "gui_defines.h"
# include "g_settings.h"
# include "gui_button.h"
# include "gui_map.h"
# include "gui_trace.h"
# include "gui_list.h"
# include "gui_list_x.h"

# include "SDL_image.h"

/*
********************************************************************************
**							CIRCLE BUTTON
********************************************************************************
*/

typedef struct				s_gui_button_circle
{
	t_gui_class_info		info;
	t_gui_button			*parent;
	t_gui_ptr				child;
	t_gui_object_point_i	position;
	int						radius;
}							t_gui_button_circle;

t_gui_button_circle			*gui_button_circle_new(
	t_gui_object_point_i position, int radius);
t_global_bool				gui_button_circle_test(
	t_gui_widget *widget, t_gui_object_point_i *cursor);
t_global_bool				gui_button_circle_render(
	t_gui_widget *widget, void *ptr);

/*
********************************************************************************
**							RECTANGLE BUTTON
********************************************************************************
*/

typedef struct				s_gui_button_rectangle
{
	t_gui_class_info		info;
	t_gui_button			*parent;
	t_gui_ptr				child;
	t_gui_object_point_i	position;
	t_gui_object_point_i	size;
}							t_gui_button_rectangle;

t_gui_button_rectangle		*gui_button_rectangle_new(
	t_gui_object_point_i position, t_gui_object_point_i size);
t_global_bool				gui_button_rectangle_test(
	t_gui_widget *widget, t_gui_object_point_i *cursor);
t_global_bool				gui_button_rectangle_render(
	t_gui_widget *widget, void *ptr);

/*
********************************************************************************
**							ROOM BUTTON
********************************************************************************
*/

typedef struct				s_gui_button_room
{
	t_gui_class_info		info;
	t_gui_button_circle		*parent;
	t_gui_map				*map;
	t_global_room			*room;
	t_gui_color				color;
}							t_gui_button_room;

t_gui_button_room			*gui_button_room_new(
	t_gui_object_point_i position, t_gui_map *map, t_global_room *room_ptr);
t_global_bool				gui_button_room_test(
	t_gui_widget *widget, t_gui_object_point_i *cursor);
t_global_bool				gui_button_room_render(
	t_gui_widget *widget, void *ptr);
t_global_bool				gui_button_room_press(
	t_gui_widget *widget, void *ptr);
t_global_bool				gui_button_room_release(
	t_gui_widget *widget, void *ptr);

/*
********************************************************************************
**							ANT BUTTON
********************************************************************************
*/

typedef struct				s_gui_button_ant
{
	t_gui_class_info		info;
	t_gui_button_circle		*parent;
	t_gui_trace				*trace;
	t_vector				*path;
	t_gui_list				*list;
	int						index;
	int						last_cycle;
	float					last_progress;
}							t_gui_button_ant;

t_gui_button_ant			*gui_button_ant_new(
	t_gui_object_point_i position, t_gui_trace *trace,
	t_gui_list *list, int index);
t_global_bool				gui_button_ant_render(
	t_gui_widget *widget, void *ptr);
t_global_bool				gui_button_ant_press(
	t_gui_widget *widget, void *ptr);
t_global_bool				gui_button_ant_release(
	t_gui_widget *widget, void *ptr);

/*
********************************************************************************
**							TEXT BUTTON
********************************************************************************
*/

typedef struct				s_gui_button_text
{
	t_gui_class_info		info;
	t_gui_button_rectangle	*parent;
	t_gui_ptr				child;
	char					buffer[64];
	t_gui_font				*font_default;
	t_gui_font				*font_selected;
}							t_gui_button_text;

t_gui_button_text			*gui_button_text_new(
	t_gui_object_point_i position, t_gui_object_point_i size, CHAR_REF str);
t_global_bool				gui_button_text_render(
	t_gui_widget *widget, void *ptr);

/*
********************************************************************************
**							LIST BUTTON
********************************************************************************
*/

typedef struct				s_gui_button_list
{
	t_gui_class_info		info;
	t_gui_button_text		*parent;
	t_gui_list				*list;
	t_gui_ptr				ptr;
}							t_gui_button_list;

t_gui_button_list			*gui_button_list_new(
	t_gui_object_point_i position, t_gui_object_point_i size,
	CHAR_REF str, t_gui_ptr ptr);
t_global_bool				gui_button_list_release(
	t_gui_widget *widget, void *ptr);

/*
********************************************************************************
**							ICON BUTTON
********************************************************************************
*/

typedef struct				s_gui_button_icon
{
	t_gui_class_info		info;
	t_gui_button_rectangle	*parent;
	SDL_Surface				*surface_free;
	SDL_Surface				*surface_pressed;
	SDL_Surface				*surface_greyed;
	SDL_Rect				rectangle_main;
	SDL_Rect				rectangle_little;
}							t_gui_button_icon;

t_gui_button_icon			*gui_button_icon_new(
	t_gui_object_point_i position, t_gui_object_point_i size,
	CHAR_REF source_free, CHAR_REF source_pressed);
t_global_bool				gui_button_icon_render(
	t_gui_widget *widget, void *ptr);

#endif
