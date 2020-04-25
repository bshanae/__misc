/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_trace_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:59:46 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_trace.h"

static void			static_create_data(t_global_trace *trace)
{
	int				i;
	t_vector		*ptr;

	trace->number_of_cycles = 0;
	trace->data = vector_create(sizeof(t_vector));
	vector_resize(&trace->data, trace->number_of_ants, NULL);
	i = 0;
	while ((ptr = vector_at(&trace->data, i++)))
	{
		*ptr = vector_create(sizeof(t_global_room *));
		vector_push(ptr, &trace->map->start);
	}
}

t_global_trace		global_trace_create(t_global_map *map)
{
	t_global_trace	trace;

	trace.number_of_ants = map->number_of_ants;
	trace.map = map;
	static_create_data(&trace);
	return (trace);
}
