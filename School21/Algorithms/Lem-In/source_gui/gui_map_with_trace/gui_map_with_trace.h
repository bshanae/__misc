/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_with_trace.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:08:34 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:08:34 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_MAP_WITH_TRACE_H
# define GUI_MAP_WITH_TRACE_H

# include "gui_map.h"
# include "gui_trace.h"

typedef struct				s_gui_map_with_trace
{
	t_gui_map				*map;
	t_gui_trace				*trace;
	t_gui_object_point_i	shift_summed;
}							t_gui_map_with_trace;

#endif
