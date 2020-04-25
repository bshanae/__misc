/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_parse_part_x.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:50:26 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

void					global_map_parse_part_head(t_global_map *map, int fd)
{
	char				*line;

	global_gnl(fd, &line);
	global_map_verify_number_of_ants(line);
	global_buffer_concat(map->buffer, line);
	global_buffer_concat(map->buffer, "\n");
	map->number_of_ants = ft_atoi(line);
	free(line);
}

static void				helper_symbol(
	t_global_map *map, char *line, t_global_bool *at_least_one_link)
{
	global_buffer_concat(map->buffer, line);
	global_buffer_concat(map->buffer, "\n");
	if (global_parser_is_comment(line))
		;
	else if (global_parser_is_room(line))
		global_map_parse_room(map, line);
	else if (global_parser_is_command(line))
	{
		global_assert_critical(*at_least_one_link,
			"Global Map : Incorrect map");
		global_map_parse_command(map, line);
	}
	else if (global_parser_is_link(line))
	{
		*at_least_one_link = global_false;
		global_map_parse_link(map, line);
	}
	else
		global_raise_error("Global Map : Unknown pattern");
	free(line);
}

void					global_map_parse_part_body(t_global_map *map, int fd)
{
	char				*line;
	t_global_bool		at_least_one_link;

	at_least_one_link = global_true;
	map->temp = global_map_temp_new();
	while (global_gnl(fd, &line) && ft_strlen(line))
		helper_symbol(map, line, &at_least_one_link);
	global_assert_critical(!at_least_one_link, "Global Map : No links");
	global_map_temp_work(map->temp, map);
}
