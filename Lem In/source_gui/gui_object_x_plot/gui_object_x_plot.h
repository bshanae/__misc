/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_x_plot.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:25:03 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:25:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_OBJECT_X_PLOT_H
# define GUI_OBJECT_X_PLOT_H

# include "global_bool.h"
# include "gui_defines.h"
# include "gui_math.h"
# include "gui_buffer.h"
# include "gui_object_x.h"
# include "gui_object_x_bundle.h"

/*
********************************************************************************
**							POINT_I
********************************************************************************
*/

struct s_gui_object_point_f	gui_object_point_i_to_f(t_gui_object_point_i point);

void						gui_object_point_i_plot(
	const t_gui_object_point_i_bundle *bundle);

/*
********************************************************************************
**							POINT_F
********************************************************************************
*/

t_gui_object_point_i		gui_object_point_f_to_i(t_gui_object_point_f point);

void						gui_object_point_f_plot(
	const t_gui_object_point_f_bundle *bundle);

/*
********************************************************************************
**							LINE
********************************************************************************
*/

typedef struct				s_gui_object_line_naa_data
{
	t_gui_buffer			*buffer;
	t_gui_object_point_i	from;
	t_gui_object_point_i	to;
	t_gui_color				color;
	t_global_bool			blend;
}							t_gui_object_line_naa_data;

typedef struct				s_gui_object_line_aa_data
{
	t_gui_buffer			*buffer;
	t_global_bool			is_steep;
	t_gui_object_point_f	delta;
	float					gradient;
	t_gui_object_point_f	from;
	t_gui_object_point_f	to;
	t_gui_color				color;
	t_global_bool			blend;
	t_gui_object_point_f	l1;
	t_gui_object_point_f	l2;
	float					inter;
}							t_gui_object_line_aa_data;

void						gui_object_line_plot(
	const t_gui_object_line_bundle *bundle);

void						gui_object_line_plot_naa(
	const t_gui_object_line_bundle *bundle);
void						gui_object_line_plot_aa(
	const t_gui_object_line_bundle *bundle);

/*
********************************************************************************
**							CIRCLE
********************************************************************************
*/

typedef struct				s_gui_object_circle_data
{
	t_gui_buffer			*buffer;
	t_gui_object_point_i	position;
	float					radius;
	float					radius2;
	float					quarter;
	t_gui_color				color;
	t_global_bool			is_filled;
}							t_gui_object_circle_data;

void						gui_object_circle_plot(
	const t_gui_object_circle_bundle *bundle);

/*
********************************************************************************
**							RECTANGLE
********************************************************************************
*/

void						gui_object_rectangle_plot(
	const t_gui_object_rectangle_bundle *bundle);

/*
********************************************************************************
**							HINT
********************************************************************************
*/

typedef struct				s_gui_object_hint_data
{
	t_gui_buffer			*buffer;
	int						width;
	t_gui_object_point_i	lower_point;
	t_gui_object_point_i	circle_1;
	t_gui_object_point_i	circle_2;
	t_gui_object_point_i	circle_3;
	t_gui_object_point_i	circle_4;
	t_gui_font				*text_font;
	CHAR_REF				text_name;
	SDL_Surface				*text_surface;
}							t_gui_object_hint_data;

void						gui_object_hint_helper_corners(
	t_gui_object_hint_data *data);
void						gui_object_hint_helper_rectangle(
	t_gui_object_hint_data *data);
void						gui_object_hint_helper_triangle(
	t_gui_object_hint_data *data);
void						gui_object_hint_helper_borders(
	t_gui_object_hint_data *data);
void						gui_object_hint_plot(
	const t_gui_object_hint_bundle *bundle);

#endif
