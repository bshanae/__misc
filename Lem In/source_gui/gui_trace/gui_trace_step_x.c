/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_trace_step_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:37:32 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:37:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_trace_x.h"

t_global_bool				gui_trace_step_forward(t_gui_trace *trace)
{
	if (trace->render_cycle == trace->data.number_of_cycles)
		return (global_false);
	trace->render_cycle++;
	trace->render_progress = 0.f;
	return (global_true);
}

t_global_bool				gui_trace_step_back(t_gui_trace *trace)
{
	if (trace->render_cycle == 1)
		return (global_false);
	trace->render_cycle--;
	trace->render_progress = 0.f;
	return (global_true);
}
