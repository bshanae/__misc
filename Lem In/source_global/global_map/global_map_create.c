/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:48:51 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

t_global_map		global_map_create(void)
{
	t_global_map	map;

	map.number_of_ants = -1;
	map.data = vector_create(sizeof(t_global_room));
	map.buffer = global_buffer_new();
	map.start = NULL;
	map.end = NULL;
	map.temp = NULL;
	return (map);
}
