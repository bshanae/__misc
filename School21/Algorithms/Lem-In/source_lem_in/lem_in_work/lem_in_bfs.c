/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:45:34 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_work.h"

t_global_bool		lem_in_bfs(t_lem_in_main *main)
{
	main->bhandari_state = lem_in_bfs_normal;
	main->bhandari_intersection = NULL;
	lem_in_bfs_prepare(main);
	lem_in_bfs_see(main, main->map.start);
	while ((main->bfs_current_room = lem_in_bfs_visit(main)))
	{
		main->bfs_current_plugin = main->bfs_current_room->plugin;
		if (lem_in_bfs_check_intersection(main))
			continue ;
		if (lem_in_bfs_cycle(main))
			return (global_true);
	}
	return (global_false);
}
