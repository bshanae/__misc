/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_lock_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:47:47 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_work.h"

void				lem_in_lock_clear(t_lem_in_main *main)
{
	t_vector_iter	iter;
	t_global_room	*room;
	t_lem_in_plugin	*plugin;
	t_global_bool	value;

	iter = vector_iter_set(&main->map.data, 0);
	value = global_false;
	while (1)
	{
		room = vector_iter_ptr(&iter);
		plugin = room->plugin;
		vector_set(&plugin->lock, 0, -1, &value);
		if (!vector_iter_next(&iter))
			break ;
	}
}

t_global_bool		lem_in_lock_link(t_global_room *from, t_global_room *to)
{
	t_lem_in_plugin	*from_plugin;
	int				i;
	t_global_room	*iter;

	if (!from || !to)
		return (global_false);
	from_plugin = from->plugin;
	i = 0;
	while (i < from_plugin->lock.length)
	{
		iter = *(t_global_room **)vector_at(&from->links, i);
		if (iter == to)
		{
			*(t_global_bool *)vector_at(&from_plugin->lock, i) = global_true;
			return (global_true);
		}
		i++;
	}
	return (global_false);
}

void				lem_in_lock_path(t_lem_in_main *main, t_global_room *start)
{
	t_global_room	*current;
	t_global_room	*next;
	t_lem_in_plugin	*next_plugin;

	current = main->map.end;
	next = start;
	while (1)
	{
		if (!lem_in_lock_link(next, current))
			global_raise_warning("Lem-Im Lock path : Can't lock a link");
		if (next == main->map.start)
			break ;
		current = next;
		next_plugin = next->plugin;
		next = next_plugin->parent_current ?
			next_plugin->parent_current : next_plugin->parent_best;
		global_assert_critical(current != NULL,
			"Lem-In, BFS : A node has no parent");
	}
}

void				lem_in_lock_path_last(t_lem_in_main *main)
{
	lem_in_lock_path(main,
		*(t_global_room **)vector_back(&main->bhandari_paths));
}

void				lem_in_lock_path_all(t_lem_in_main *main)
{
	int				i;
	t_global_room	*iter;

	lem_in_lock_clear(main);
	i = 0;
	while (i < main->bhandari_paths.length)
	{
		iter = *(t_global_room **)vector_at(&main->bhandari_paths, i++);
		lem_in_lock_path(main, iter);
	}
}
