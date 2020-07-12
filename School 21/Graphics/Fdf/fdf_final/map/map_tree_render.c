/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tree_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/08 18:12:00 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void					map_tree_functor(void *m)
{
	t_tree_point		*tp;
	t_point_2d			me;
	t_point_2d			neighbor;

	tp = (t_tree_point *)m;
	me = map_tree_point(tp->map, tp->i);
	map_tree_neighbor(tp, TP_N_LOWER, &me, &neighbor);
	map_tree_neighbor(tp, TP_N_UPPER, &me, &neighbor);
	map_tree_neighbor(tp, TP_N_LEFT, &me, &neighbor);
	map_tree_neighbor(tp, TP_N_RIGHT, &me, &neighbor);
}

static void					map_tree_load(t_map *map)
{
	int						map_i;

	map_i = 0;
	btree_clean(&map->tree, NULL);
	while (map_i < map->data_len)
		map_tree_insert(map, map_i++);
}

static void					map_tree_refresh(t_btree *root)
{
	if (!root)
		return ;
	ft_bzero(((t_tree_point *)root->content)->neighbors, 4);
	map_tree_refresh(root->left);
	map_tree_refresh(root->right);
}

void						map_tree_insert(t_map *map, int i)
{
	t_tree_point			tp;
	t_btree					*ptr;

	tp.map = map;
	tp.i = i;
	ft_bzero(&tp.neighbors, 4);
	ptr = btree_insert(&map->tree, &tp, sizeof(t_tree_point), map_tree_cmp);
	if (!ptr)
		raise_error(ERR_ALLOC);
	map->data[i].ptr = ptr->content;
}

void						map_tree_render(t_map *map)
{
	if (!map->tree)
		map_tree_load(map);
	else if (!map->tree_is_fresh)
	{
		map->tree_is_fresh = 1;
		map_tree_refresh(map->tree);
	}
	ft_bzero(map->img, sizeof(int) * map->img_wid * map->img_high);
	btree_prefix(map->tree, map_tree_functor);
	map->tree_is_fresh = 0;
}
