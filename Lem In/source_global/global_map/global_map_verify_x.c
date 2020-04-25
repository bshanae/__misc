/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_verify_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:51:35 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

void				global_map_verify_map(t_global_map *map)
{
	global_assert_critical(map->number_of_ants > 0,
		"Global Map : Invalid number of ants");
	global_assert_critical(map->start != NULL,
		"Global Map : No start room");
	global_assert_critical(map->end != NULL,
		"Global Map : No end room");
	global_assert_critical(map->end->links.length != 0,
		"Global Map : End room is not accessible");
}

void				global_map_verify_number_of_ants(char *str)
{
	while (*str)
	{
		if (!is_dec(str))
			global_raise_error("Global Map : Unexpected symbol");
		str++;
	}
}

void				global_map_verify_room(t_global_map *map,
		t_global_room *room)
{
	t_vector_iter	iter;
	t_global_room	*ptr;

	iter = vector_iter_set(&map->data, 0);
	while (1)
	{
		if (!(ptr = vector_iter_ptr(&iter)))
			break ;
		if (ptr->x == room->x && ptr->y == room->y)
			global_raise_error("Global Map : Two rooms have same coordinates");
		if (!ft_strcmp(room->name, ptr->name))
			global_raise_error("Global Map : Two rooms have same names");
		if (!vector_iter_next(&iter))
			break ;
	}
}

void				global_map_verify_link(t_global_room *from,
		t_global_room *to)
{
	t_vector_iter	iter;
	t_global_room	**ptr2;

	if (from == to)
		global_raise_error("Global Map : Invalid link");
	iter = vector_iter_set(&from->links, 0);
	while (1)
	{
		if (!(ptr2 = vector_iter_ptr(&iter)))
			break ;
		if (*ptr2 == to)
			global_raise_error("Global Map : Link is repeated");
		if (!vector_iter_next(&iter))
			break ;
	}
}
