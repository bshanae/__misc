/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_find_room.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:49:38 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

t_global_room			*global_map_find_room_str(
	t_global_map *map, char *name)
{
	t_global_map_temp	*temp;
	t_btree_node		*node;
	t_vector_iter		*iter;

	temp = map->temp;
	node = btree_find_custom(&temp->names, (t_btree_f_cmp)global_map_f_find,
			name);
	if (!node)
	{
		global_raise_error("Global Map : Room not found");
		return (NULL);
	}
	iter = node->data;
	return (vector_iter_ptr(iter));
}

t_global_room			*global_map_find_room_range(
	t_global_map *map, t_global_range name)
{
	char				buffer[64];

	ft_bzero(buffer, 64);
	ft_strncpy(buffer, name.begin, name.end - name.begin);
	return (global_map_find_room_str(map, buffer));
}
