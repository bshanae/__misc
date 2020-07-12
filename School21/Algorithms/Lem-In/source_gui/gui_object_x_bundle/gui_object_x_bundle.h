/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_x_bundle.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:14:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:14:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_OBJECT_X_BUNDLE_H
# define GUI_OBJECT_X_BUNDLE_H

# include "global_bool.h"
# include "gui_color.h"
# include "gui_buffer.h"
# include "gui_font.h"
# include "gui_object_x.h"
# include "gui_object_type.h"

# include <stdarg.h>

# define GUI_OBJECT_BUNDLE_MAX	64

/*
********************************************************************************
**								POINT_I
********************************************************************************
*/

typedef struct					s_gui_object_point_i_bundle
{
	t_gui_buffer				*buffer;
	t_gui_object_point_i		point;
	t_gui_color					color;
	float						alpha;
	t_global_bool				blend;
}								t_gui_object_point_i_bundle;

t_gui_object_point_i_bundle		*gui_object_point_i_bundle_build(
	t_gui_object_point_i_bundle *target, ...);
t_gui_object_point_i_bundle		*gui_object_point_i_bundle_build_v(
	t_gui_object_point_i_bundle *target, va_list args);

/*
********************************************************************************
**								POINT_F
********************************************************************************
*/

typedef struct					s_gui_object_point_f_bundle
{
	t_gui_buffer				*buffer;
	t_gui_object_point_f		point;
	t_gui_color					color;
	float						alpha;
	t_global_bool				blend;
}								t_gui_object_point_f_bundle;

t_gui_object_point_f_bundle		*gui_object_point_f_bundle_build(
	t_gui_object_point_f_bundle *target, ...);
t_gui_object_point_f_bundle		*gui_object_point_f_bundle_build_v(
	t_gui_object_point_f_bundle *target, va_list args);

/*
********************************************************************************
**								LINE
********************************************************************************
*/

typedef struct					s_gui_object_line_bundle
{
	t_gui_buffer				*buffer;
	t_gui_object_point_i		from;
	t_gui_object_point_i		to;
	t_global_bool				aa;
	t_gui_color					color;
	t_global_bool				blend;
}								t_gui_object_line_bundle;

t_gui_object_line_bundle		*gui_object_line_bundle_build(
	t_gui_object_line_bundle *target, ...);
t_gui_object_line_bundle		*gui_object_line_bundle_build_v(
	t_gui_object_line_bundle *target, va_list args);

/*
********************************************************************************
**								CIRCLE
********************************************************************************
*/

typedef struct					s_gui_object_circle_bundle
{
	t_gui_buffer				*buffer;
	t_gui_object_point_i		position;
	int							radius;
	t_gui_color					color;
	t_global_bool				is_filled;
}								t_gui_object_circle_bundle;

t_gui_object_circle_bundle		*gui_object_circle_bundle_build(
	t_gui_object_circle_bundle *target, ...);
t_gui_object_circle_bundle		*gui_object_circle_bundle_build_v(
	t_gui_object_circle_bundle *target, va_list args);

/*
********************************************************************************
**								RECTANGLE
********************************************************************************
*/

typedef struct					s_gui_object_rectangle_bundle
{
	t_gui_buffer				*buffer;
	t_gui_object_point_i		min;
	t_gui_object_point_i		max;
	t_gui_color					color;
	t_global_bool				is_filled;
}								t_gui_object_rectangle_bundle;

t_gui_object_rectangle_bundle	*gui_object_rectangle_bundle_build(
	t_gui_object_rectangle_bundle *target, ...);
t_gui_object_rectangle_bundle	*gui_object_rectangle_bundle_build_v(
	t_gui_object_rectangle_bundle *target, va_list args);

/*
********************************************************************************
**								HINT
********************************************************************************
*/

typedef struct					s_gui_object_hint_bundle
{
	t_gui_buffer				*buffer;
	t_gui_font					*font;
	t_gui_object_point_i		lower_point;
	CHAR_REF					name;
}								t_gui_object_hint_bundle;

t_gui_object_hint_bundle		*gui_object_hint_bundle_build(
	t_gui_object_hint_bundle *target, ...);
t_gui_object_hint_bundle		*gui_object_hint_bundle_build_v(
	t_gui_object_hint_bundle *target, va_list args);

#endif
