/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_temp_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:51:11 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 17:22:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

t_global_map_temp		*global_map_temp_new(void)
{
	t_global_map_temp	*new;

	new = global_malloc(sizeof(t_global_map_temp));
	new->names = btree_create(sizeof(t_vector_iter),
		(t_btree_f_cmp)global_map_f_insert);
	new->command = global_command_none;
	new->start_iter = vector_iter_set(NULL, -1);
	new->end_iter = vector_iter_set(NULL, -1);
	return (new);
}

void					global_map_temp_delete(t_global_map_temp **temp)
{
	btree_destroy(&(*temp)->names);
	free(*temp);
	*temp = NULL;
}

void					global_map_temp_read_room(t_global_map_temp *temp,
		t_vector_iter iter)
{
	if (temp->command == global_command_start)
	{
		if (temp->start_iter.vector)
			global_raise_error("Global Map Temp : Two start rooms");
		temp->start_iter = iter;
	}
	if (temp->command == global_command_end)
	{
		if (temp->end_iter.vector)
			global_raise_error("Global Map Temp : Two end rooms");
		temp->end_iter = iter;
	}
	temp->command = global_command_none;
	btree_insert(&temp->names, &iter);
}

void					global_map_temp_work(
	t_global_map_temp *temp, t_global_map *map)
{
	map->start = vector_iter_ptr(&temp->start_iter);
	map->end = vector_iter_ptr(&temp->end_iter);
}
