/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parent_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:35:41 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_work.h"

void				lem_in_parent_restore(t_lem_in_main *main)
{
	int				i;
	t_global_room	*room;
	t_lem_in_plugin	*plugin;

	i = 0;
	while ((room = vector_at(&main->map.data, i++)))
	{
		plugin = room->plugin;
		plugin->parent_current = plugin->parent_best;
	}
	vector_pop(&main->bhandari_paths);
}

static void			helper_error(t_lem_in_main *main, t_lem_in_plugin *plugin)
{
	if (main->bhandari_state != lem_in_bfs_confirmed_intersection &&
		plugin->parent_best && plugin->parent_current &&
		plugin->parent_best != plugin->parent_current)
		global_raise_error("Lem-In Parent : Node already has best parent");
}

void				lem_in_parent_save(t_lem_in_main *main)
{
	int				i;
	t_global_room	*room;
	t_lem_in_plugin	*plugin;

	i = 0;
	while ((room = vector_at(&main->map.data, i++)))
	{
		plugin = room->plugin;
		if (plugin->is_parent_important)
		{
			if (main->bhandari_state == lem_in_bfs_confirmed_intersection &&
				!plugin->ignore_best_parent)
				plugin->parent_best = plugin->parent_best ?
					plugin->parent_best : plugin->parent_current;
			else
				plugin->parent_best = plugin->parent_current;
		}
		else
			plugin->parent_current = NULL;
		plugin->is_parent_important = global_false;
	}
}
