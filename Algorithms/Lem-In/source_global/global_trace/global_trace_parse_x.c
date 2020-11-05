/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_trace_parse_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:01:51 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_trace.h"

void						global_trace_parse_move(t_global_trace *trace)
{
	int						ant_index;
	t_vector				*trace_one;
	t_global_range			room_range;
	t_global_room			**room_ptr;
	t_global_room			*room_value;

	global_assert_critical(*(trace->temp_line++) == 'L',
		"Global trace, Incorrect pattern");
	ant_index = global_parser_get_int(&trace->temp_line) - 1;
	trace_one = vector_at(&trace->data, ant_index);
	global_assert_critical(*(trace->temp_line++) == '-',
		"Global trace, Incorrect pattern");
	room_ptr = vector_at(trace_one, trace_one->length - 1);
	room_range = global_parser_get_range(&trace->temp_line);
	room_value = global_map_find_room_range(trace->map, room_range);
	*room_ptr = room_value;
}

void						global_trace_parse_group(t_global_trace *trace)
{
	int						i;
	t_vector				*trace_one;
	t_global_room			**room_previous;

	trace->number_of_cycles++;
	i = 0;
	while ((trace_one = vector_at(&trace->data, i++)))
	{
		room_previous = vector_at(trace_one, trace_one->length - 1);
		vector_push(trace_one, room_previous);
	}
	while (1)
	{
		global_trace_parse_move(trace);
		if (!*trace->temp_line)
			break ;
		global_assert_critical(*trace->temp_line++ == ' ',
			"Global trace, Incorrect pattern");
	}
}
