/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_trace_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:35:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:35:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_trace_x.h"

void				gui_trace_delete(t_gui_trace **trace)
{
	vector_destroy(&(*trace)->widgets);
	global_trace_destroy(&(*trace)->data);
	free(*trace);
	*trace = NULL;
}
