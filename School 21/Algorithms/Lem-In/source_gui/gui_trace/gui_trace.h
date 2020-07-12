/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_trace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:34:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:35:26 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_TRACE_H
# define GUI_TRACE_H

# include "global_trace.h"
# include "gui_defines.h"
# include "gui_map.h"
# include "gui_system.h"

typedef enum				e_gui_trace_state
{
	gui_trace_rendering,
	gui_trace_paused
}							t_gui_trace_state;

typedef struct				s_gui_trace
{
	t_global_trace			data;
	t_gui_map				*map;
	t_vector				widgets;
	int						render_cycle;
	float					render_progress;
	t_gui_trace_state		render_state;
	t_global_bool			work_block;
	t_vector				*selected_path;
}							t_gui_trace;

#endif
