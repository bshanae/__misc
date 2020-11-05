/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_backtrack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:44:53 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_work.h"

static void			helper_step(
	t_lem_in_main *main, t_global_bool *confirm_intersection,
	t_global_room **iter, t_lem_in_plugin *plugin)
{
	if (main->bhandari_intersection == *iter)
		*confirm_intersection = global_true;
	if (main->bhandari_state == lem_in_bfs_confirmed_intersection &&
		!plugin->ignore_best_parent)
		*iter = plugin->parent_best ?
			plugin->parent_best : plugin->parent_current;
	else
		*iter = plugin->parent_current;
}

int					lem_in_backtrack(t_lem_in_main *main, t_global_room *start)
{
	t_global_bool	confirm_intersection;
	int				count;
	t_global_room	*iter;
	t_lem_in_plugin	*plugin;

	confirm_intersection = global_false;
	count = 1;
	iter = start ?
		start : *(t_global_room **)vector_back(&main->bhandari_paths);
	while (1)
	{
		plugin = iter->plugin;
		count++;
		if (iter == main->map.start)
			break ;
		plugin->is_parent_important = global_true;
		helper_step(main, &confirm_intersection, &iter, plugin);
		global_assert_critical(iter != NULL,
			"Lem-In, BFS : A node has no parent");
	}
	if (main->bhandari_state == lem_in_bfs_intersection)
		main->bhandari_state = confirm_intersection ?
			lem_in_bfs_confirmed_intersection : lem_in_bfs_normal;
	return (count);
}
