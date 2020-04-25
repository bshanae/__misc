/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_trace_x.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:37:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:37:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_TRACE_X_H
# define GUI_TRACE_X_H

# include "gui_trace.h"
# include "gui_map_x.h"
# include "gui_settings.h"

t_gui_trace			*gui_trace_new(int fd, t_gui_map *map, void *list);
void				gui_trace_delete(t_gui_trace **trace);

void				gui_trace_render_ants(t_gui_trace *trace);
void				gui_trace_render_path(
	t_gui_trace *trace, t_vector *path, t_global_bool is_selected);

t_global_bool		gui_trace_step_forward(t_gui_trace *trace);
t_global_bool		gui_trace_step_back(t_gui_trace *trace);

#endif
