/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:16:00 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 19:11:15 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void					map_zoom(t_map *map, int mod_sign)
{
	int					map_i;

	map_i = 0;
	if (map->mod == MAP_MOD_ISO)
	{
		map->iso_zoom *= 1 + mod_sign * map->zoom_step;
		return ;
	}
	btree_clean(&map->tree, NULL);
	while (map_i < map->data_len)
	{
		map->data[map_i].qtr.i *= 1 + mod_sign * map->zoom_step;
		map->data[map_i].qtr.j *= 1 + mod_sign * map->zoom_step;
		map->data[map_i].qtr.k *= 1 + mod_sign * map->zoom_step;
		map_tree_insert(map, map_i);
		map_i++;
	}
}

void					map_shift(t_map *map, int mod_axis, int mod_sign)
{
	t_point_2d			*object;
	int					map_i;

	object = (map->mod == MAP_MOD_ISO) ? &map->iso_offset : &map->offset;
	if (mod_axis == MOD_AXIS_X)
		object->x += mod_sign * map->offset_step;
	else if (mod_axis == MOD_AXIS_Y)
		object->y += mod_sign * map->offset_step;
	if (map->mod == MAP_MOD_FREE)
	{
		map_i = 0;
		btree_clean(&map->tree, NULL);
		while (map_i < map->data_len)
			map_tree_insert(map, map_i++);
	}
}

void					map_rotate(t_map *map, int mod_axis, int mod_sign)
{
	int				map_i;
	t_quaternion	rot;
	t_quaternion	inv;

	map_i = 0;
	btree_clean(&map->tree, NULL);
	rot = quaternion_generate_rotation(mod_axis, mod_sign * map->rotation_step);
	inv = quaternion_inverse(&rot);
	while (map_i < map->data_len)
	{
		map->data[map_i].qtr = quaternion_multiply(&map->data[map_i].qtr, &inv);
		map->data[map_i].qtr = quaternion_multiply(&rot, &map->data[map_i].qtr);
		map_tree_insert(map, map_i++);
	}
}

int						map_palette_set(t_map *map, int is_switch)
{
	t_point_3d			*obj;
	t_palette			**iter;
	int					map_i;

	if (map->color_change == MAP_C_FORBID)
		return (0);
	obj = map->mod == MAP_MOD_ISO ?
		map->original : map->data;
	iter = map->mod == MAP_MOD_ISO ?
		&map->palette_iter_iso : &map->palette_iter_tree;
	map_i = 0;
	while (map_i < map->data_len)
	{
		obj[map_i].color = (*iter)->data[obj[map_i].color_type];
		map_i++;
	}
	if (is_switch)
		*iter = (*iter)->next ? (*iter)->next : map->palette_head;
	map->palette_clean = 0;
	return (0);
}
