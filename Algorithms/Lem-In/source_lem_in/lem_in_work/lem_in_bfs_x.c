/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_bfs_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:46:13 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_work.h"

void				lem_in_bfs_prepare(t_lem_in_main *main)
{
	int				i;
	t_global_room	*room;
	t_lem_in_plugin	*plugin;

	queue_clear(&main->bfs_queue);
	main->bfs_current_room = NULL;
	main->bfs_current_plugin = NULL;
	i = 0;
	while (i < main->map.data.length)
	{
		room = vector_at(&main->map.data, i++);
		plugin = room->plugin;
		plugin->state = lem_in_not_seen;
		plugin->parent_current = NULL;
		plugin->ignore_best_parent = global_false;
		plugin->is_parent_important = global_false;
	}
}

void				lem_in_bfs_see(t_lem_in_main *main, t_global_room *room)
{
	t_lem_in_plugin	*plugin;

	plugin = room->plugin;
	queue_push(&main->bfs_queue, &room);
	plugin->state = lem_in_seen;
}

t_global_room		*lem_in_bfs_visit(t_lem_in_main *main)
{
	t_global_room	**ptr2;
	t_global_room	*ptr;

	if (!(ptr2 = queue_front(&main->bfs_queue)))
		return (NULL);
	ptr = *ptr2;
	queue_pop(&main->bfs_queue);
	((t_lem_in_plugin *)ptr->plugin)->state = lem_in_visited;
	return (ptr);
}

t_global_bool		lem_in_bfs_check_intersection(t_lem_in_main *main)
{
	if (main->bhandari_state == lem_in_bfs_normal &&
		main->bfs_current_plugin->parent_best)
	{
		((t_lem_in_plugin *)main->bfs_current_plugin->parent_best->plugin)
			->parent_current = main->bfs_current_room;
		main->bfs_current_plugin->ignore_best_parent = global_true;
		main->bhandari_state = lem_in_bfs_intersection;
		main->bhandari_intersection = main->bfs_current_room;
		lem_in_bfs_see(main, main->bfs_current_plugin->parent_best);
		return (global_true);
	}
	return (global_false);
}

t_global_bool		lem_in_bfs_cycle(t_lem_in_main *main)
{
	int				i;
	t_global_room	*room;
	t_lem_in_plugin	*plugin;
	t_global_bool	*lock;

	i = 0;
	while (i < main->bfs_current_room->links.length)
	{
		room = *(t_global_room **)vector_at(&main->bfs_current_room->links, i);
		plugin = room->plugin;
		lock = vector_at(&main->bfs_current_plugin->lock, i++);
		if (!*lock && plugin->state == lem_in_not_seen)
		{
			lem_in_bfs_see(main, room);
			if (room == main->map.end)
			{
				vector_push(&main->bhandari_paths, &main->bfs_current_room);
				return (global_true);
			}
			else
				plugin->parent_current = main->bfs_current_room;
		}
	}
	return (global_false);
}
