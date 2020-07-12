/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:35:27 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_main_x.h"

void				lem_in_main_load(t_lem_in_main *main, int ac, char **av)
{
	int				i;
	t_global_room	*room;
	t_lem_in_plugin	*plugin;
	t_global_bool	bool_default;

	lem_in_flags(main, ac, av);
	global_map_parse(&main->map, main->fd);
	i = 0;
	bool_default = global_false;
	while ((room = vector_at(&main->map.data, i++)))
	{
		room->plugin = global_malloc(sizeof(t_lem_in_plugin));
		plugin = room->plugin;
		plugin->state = lem_in_not_seen;
		plugin->parent_current = NULL;
		plugin->parent_best = NULL;
		plugin->is_parent_important = global_false;
		plugin->lock = vector_create(sizeof(t_global_bool));
		vector_resize(&plugin->lock, room->links.length, &bool_default);
		plugin->ant = 0;
	}
}
