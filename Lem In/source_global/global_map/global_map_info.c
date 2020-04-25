/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:49:55 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

void				global_map_info(t_global_map *map)
{
	int				i;
	t_global_room	*room;

	ft_printf("[Global Map] : Number of ants = %d\n", map->number_of_ants);
	ft_printf("[Global Map] : Start = '%s', end = '%s'\n",
		map->start->name, map->end->name);
	ft_printf("[Global Map] : Map :\n{\n");
	i = 0;
	while (i < (int)map->data.length)
	{
		room = vector_at(&map->data, i++);
		ft_printf("\t");
		global_room_info(room);
	}
	ft_printf("}\n");
}
