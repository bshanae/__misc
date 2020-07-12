/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_room_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:58:06 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <global_bool.h>
#include "global_room.h"

t_global_room			global_room_create(t_global_range name, int x, int y)
{
	t_global_room		room;

	ft_bzero(room.name, 64);
	ft_strncpy(room.name, name.begin, name.end - name.begin);
	room.x = x;
	room.y = y;
	room.links = vector_create(sizeof(t_global_room *));
	room.plugin = NULL;
	return (room);
}

void					global_room_destroy(t_global_room *room)
{
	vector_destroy(&room->links);
	free(room->plugin);
}

void					global_room_info(t_global_room *room)
{
	int					i;
	t_global_room		**neighbor;

	i = 0;
	ft_printf("[Global room] : name = '%s', position = {%d, %d}, links = {",
		room->name, room->x, room->y);
	while (i < (int)room->links.length)
	{
		neighbor = vector_at(&room->links, i++);
		ft_printf("'%s'", (*neighbor)->name);
		if (i != (int)room->links.length)
			ft_printf(", ");
	}
	ft_printf("}\n");
}
