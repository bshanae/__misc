/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_parse_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:50:52 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

void					global_map_parse_room(t_global_map *map, char *line)
{
	t_global_range		range;
	int					value[2];
	t_global_room		room;
	t_vector_iter		iter;

	range = global_parser_get_range(&line);
	line++;
	value[0] = global_parser_get_int(&line);
	line++;
	value[1] = global_parser_get_int(&line);
	line++;
	room = global_room_create(range, value[0], value[1]);
	global_map_verify_room(map, &room);
	iter = vector_push(&map->data, &room);
	global_map_temp_read_room(map->temp, iter);
}

void					global_map_parse_link(t_global_map *map, char *line)
{
	t_global_range		range[2];
	t_global_room		*room[2];

	range[0] = global_parser_get_range(&line);
	line++;
	range[1] = global_parser_get_range(&line);
	room[0] = global_map_find_room_range(map, range[0]);
	room[1] = global_map_find_room_range(map, range[1]);
	global_map_verify_link(room[0], room[1]);
	vector_push(&room[0]->links, room + 1);
	vector_push(&room[1]->links, room + 0);
}

void					global_map_parse_command(t_global_map *map, char *line)
{
	t_global_map_temp	*temp;

	temp = map->temp;
	temp->command = global_parser_get_command(&line);
	global_assert_critical(temp->command != global_command_none,
		"Global Map : Unknown command");
}
