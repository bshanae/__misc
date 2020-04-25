/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:34:36 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_main_x.h"

void				lem_in_main_delete(t_lem_in_main **main)
{
	int				i;
	t_global_room	*room;
	t_lem_in_plugin	*plugin;

	i = 0;
	if ((*main)->fd != 0)
		close((*main)->fd);
	while ((room = vector_at(&(*main)->map.data, i++)))
	{
		plugin = room->plugin;
		vector_destroy(&plugin->lock);
	}
	global_map_destroy(&(*main)->map);
	queue_destroy(&(*main)->bfs_queue);
	vector_destroy(&(*main)->bhandari_length_array);
	vector_destroy(&(*main)->bhandari_length_array_test);
	vector_destroy(&(*main)->bhandari_paths);
	lem_in_eval_destroy(&(*main)->bhandari_eval);
	free(*main);
	*main = NULL;
}
