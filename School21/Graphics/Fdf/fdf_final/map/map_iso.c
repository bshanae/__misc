/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:39:40 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:39:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void				map_iso_adjust(t_map *map)
{
	int				map_i;
	int				y_temp;
	int				y_min;
	int				y_max;

	map_i = 0;
	y_min = INT_MAX;
	y_max = INT_MIN;
	while (map_i < map->data_len)
	{
		y_temp =
			(int)(((map->original[map_i].qtr.i + map->original[map_i].qtr.j) *
			sin(0.523599)) - map->original[map_i].qtr.k) + map->offset.y;
		y_min = ft_min(y_temp, y_min);
		y_max = ft_max(y_temp, y_max);
		map_i++;
	}
	if (map->offset.y - y_min > y_max - map->offset.y)
		map->iso_zoom = (0.43 * map->img_high) / (map->offset.y - y_min);
	else
		map->iso_zoom = (0.43 * map->img_high) / (y_max - map->offset.y);
	map->iso_offset = map->offset;
}

t_point_2d			map_iso_point(t_map *map, t_point_3d *p)
{
	t_point_2d		res;

	res.x = (int)((p->qtr.i * map->iso_zoom - p->qtr.j * map->iso_zoom)
			* cos(0.523599)) + map->iso_offset.x;
	res.y =
			(int)(((p->qtr.i * map->iso_zoom + p->qtr.j * map->iso_zoom)
			* sin(0.523599)) - p->qtr.k * map->iso_zoom)
			+ map->iso_offset.y;
	res.color = p->color;
	return (res);
}

void				map_iso_render(t_map *map)
{
	int				map_i;
	t_point_2d		a;
	t_point_2d		b;

	map_i = 0;
	ft_bzero(map->img, sizeof(int) * map->img_wid * map->img_high);
	while (map_i + 1 < map->data_len)
	{
		a = map_iso_point(map, &map->original[map_i]);
		if ((map_i + 1) % map->data_wid)
		{
			b = map_iso_point(map, &map->original[map_i + 1]);
			map_wu(map, &a, &b);
		}
		if (map_i + map->data_wid < map->data_len)
		{
			b = map_iso_point(map, &map->original[map_i + map->data_wid]);
			map_wu(map, &a, &b);
		}
		map_i++;
	}
}
