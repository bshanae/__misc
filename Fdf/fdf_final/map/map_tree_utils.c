/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tree_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:34:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:35:09 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int				inverse_neighbor(int n)
{
	if (n == TP_N_LOWER)
		return (TP_N_UPPER);
	if (n == TP_N_UPPER)
		return (TP_N_LOWER);
	if (n == TP_N_LEFT)
		return (TP_N_RIGHT);
	if (n == TP_N_RIGHT)
		return (TP_N_LEFT);
	return (INT_MAX);
}

static int				find_neighbor(t_map *map, int n)
{
	if (n == TP_N_LOWER)
		return (-1 * map->data_wid);
	if (n == TP_N_UPPER)
		return (map->data_wid);
	if (n == TP_N_LEFT)
		return (-1);
	if (n == TP_N_RIGHT)
		return (1);
	return (INT_MAX);
}

t_point_2d				map_tree_point(t_map *map, int i)
{
	t_point_2d			res;

	res.x = (int)map->data[i].qtr.i + map->offset.x;
	res.y = (int)map->data[i].qtr.j + map->offset.y;
	res.color = map->data[i].color;
	return (res);
}

int						map_tree_cmp(const void *m1, const void *m2)
{
	t_tree_point		*tp1;
	t_tree_point		*tp2;

	tp1 = (t_tree_point *)m1;
	tp2 = (t_tree_point *)m2;
	return ((int)(tp1->map->data[tp1->i].qtr.k - tp2->map->data[tp2->i].qtr.k));
}

void					map_tree_neighbor
	(t_tree_point *tp, int n, t_point_2d *me, t_point_2d *neighbor_p)
{
	int					n_position;
	t_tree_point		*neighbor_tp;

	if (tp->neighbors[n] == TP_DRAWN)
		return ;
	tp->neighbors[n] = TP_DRAWN;
	if (n == TP_N_LOWER && tp->i - tp->map->data_wid < 0)
		return ;
	if (n == TP_N_UPPER && tp->i + tp->map->data_wid >= tp->map->data_len)
		return ;
	if (n == TP_N_LEFT && (tp->i - 1 < 0 || !(tp->i % tp->map->data_wid)))
		return ;
	if (n == TP_N_RIGHT &&
		(tp->i + 1 >= tp->map->data_len || !((tp->i + 1) % tp->map->data_wid)))
		return ;
	n_position = find_neighbor(tp->map, n);
	neighbor_tp = (t_tree_point *)tp->map->data[tp->i + n_position].ptr;
	neighbor_tp->neighbors[inverse_neighbor(n)] = TP_DRAWN;
	*neighbor_p = map_tree_point(tp->map, tp->i + n_position);
	map_wu(tp->map, me, neighbor_p);
}
