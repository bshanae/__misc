/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:48:04 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_MAP_H
# define GLOBAL_MAP_H

# include "global_error.h"
# include "global_buffer.h"
# include "global_parser.h"
# include "global_room.h"

# include "libft_vector.h"
# include "libft_btree.h"

# include <stdarg.h>

typedef struct			s_global_map
{
	int					number_of_ants;
	t_vector			data;
	t_global_buffer		*buffer;
	t_global_room		*start;
	t_global_room		*end;
	void				*temp;
}						t_global_map;

t_global_map			global_map_create(void);
void					global_map_destroy(t_global_map *map);

void					global_map_info(t_global_map *map);

void					global_map_verify_map(t_global_map *map);
void					global_map_verify_number_of_ants(char *str);
void					global_map_verify_room(
	t_global_map *map, t_global_room *room);
void					global_map_verify_link(
	t_global_room *from, t_global_room *to);

t_global_room			*global_map_find_room_str(
	t_global_map *map, char *name);
t_global_room			*global_map_find_room_range(
	t_global_map *map, t_global_range name);

void					global_map_parse_room(
	t_global_map *map, char *line);
void					global_map_parse_link(
	t_global_map *map, char *line);
void					global_map_parse_command(
	t_global_map *map, char *line);

void					global_map_parse_part_head(t_global_map *map, int fd);
void					global_map_parse_part_body(t_global_map *map, int fd);

void					global_map_parse(t_global_map *map, int fd);

typedef struct			s_global_map_temp
{
	t_btree				names;
	t_global_command	command;
	t_vector_iter		start_iter;
	t_vector_iter		end_iter;
}						t_global_map_temp;

int						global_map_f_insert(
	t_vector_iter *left_iter, t_vector_iter *right_iter);
int						global_map_f_find(
	t_vector_iter *iter, char *name);

t_global_map_temp		*global_map_temp_new(void);
void					global_map_temp_delete(t_global_map_temp **temp);

void					global_map_temp_read_room(
	t_global_map_temp *temp, t_vector_iter iter);
void					global_map_temp_work(
	t_global_map_temp *temp, t_global_map *map);

#endif
