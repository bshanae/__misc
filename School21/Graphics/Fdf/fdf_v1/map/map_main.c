/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:15:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:38:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map					map_init(int wid, int high, int mod)
{
	t_map				new;

	new.img = NULL;
	new.img_wid = wid;
	new.img_high = high;
	new.mod = mod;
	new.offset_step = 20;
	new.rotation_step = 0.07;
	new.tree = NULL;
	new.tree_is_fresh = 0;
	new.data = NULL;
	new.data_wid = 0;
	new.data_len = 0;
	new.data_real_len = 0;
	new.zoom_step = 0.1;
	new.offset = (t_point_2d){.x = 0, .y = 0};
	new.original = NULL;
	new.iso_zoom = 1;
	new.iso_offset = (t_point_2d){.x = 0, .y = 0};
	new.color_change = MAP_C_ALLOW;
	new.palette_clean = 1;
	color_palette_build(&new.palette_head);
	new.palette_iter_tree = new.palette_head;
	new.palette_iter_iso = new.palette_head;
	return (new);
}

void					map_close(t_map *map)
{
	free(map->data);
	free(map->original);
	btree_clean(&map->tree, NULL);
	color_palette_destroy(&map->palette_head);
}

void					map_reset(t_map *map)
{
	int					map_i;

	ft_memcpy(map->data, map->original, sizeof(t_point_3d) * map->data_len);
	map->mod = MAP_MOD_ISO;
	btree_clean(&map->tree, NULL);
	map->zoom_step = 0.1;
	map->offset.x = (int)((map->img_wid / 2.0));
	map->offset.y = (int)((map->img_high / 2.0));
	map_iso_adjust(map);
	map_i = 0;
	while (map->color_change == MAP_C_ALLOW && map_i < map->data_len)
	{
		map->data[map_i].color.mix = WHITE;
		map->original[map_i].color.mix = WHITE;
		map_i++;
	}
	map->palette_clean = 1;
	map->palette_iter_tree = map->palette_head;
	map->palette_iter_iso = map->palette_head;
}

void					map_adjust(t_map *map)
{
	int				map_i;
	double			temp_x;
	double			temp_y;
	double			zoom;

	temp_x = (map->img_wid * 0.6) / map->data_wid;
	temp_y = (map->img_high * 0.6) / (((double)map->data_len / map->data_wid));
	zoom = temp_x < temp_y ? temp_x : temp_y;
	temp_x = (map->data_wid / 2.0 - 0.5) * zoom;
	temp_y = (((double)map->data_len / map->data_wid - 0.5) / 2.0) * zoom;
	map_i = 0;
	while (map_i < map->data_len)
	{
		map->original[map_i].qtr.i =
			map->original[map_i].qtr.i * zoom - temp_x;
		map->original[map_i].qtr.j =
			map->original[map_i].qtr.j * zoom - temp_y;
		map->original[map_i].qtr.k *= zoom;
		map_i++;
	}
	map->offset.x = (int)((map->img_wid / 2.0));
	map->offset.y = (int)((map->img_high / 2.0));
}

void					map_point_set
	(t_map *map, const int *x, const int *y, const t_color *color)
{
	if (*x < 0 || *y < 0 || *x >= map->img_wid || *y >= map->img_high)
		return ;
	map->img[(*y * map->img_wid) + *x] = color->mix;
}
