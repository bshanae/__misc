/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:49:02 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

void				global_map_destroy(t_global_map *map)
{
	int				i;

	i = 0;
	while (i < (int)map->data.length)
		global_room_destroy(vector_at(&map->data, i++));
	vector_destroy(&map->data);
	global_buffer_delete(&map->buffer);
	global_map_temp_delete((t_global_map_temp **)&map->temp);
}
