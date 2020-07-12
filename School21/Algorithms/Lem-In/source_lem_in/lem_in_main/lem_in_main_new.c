/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:34:10 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_main_x.h"

t_lem_in_main		*lem_in_main_new(void)
{
	t_lem_in_main	*new;

	new = global_malloc(sizeof(t_lem_in_main));
	new->fd = 0;
	new->print_only = global_false;
	new->map = global_map_create();
	new->bfs_queue = queue_create(sizeof(t_global_room *));
	new->bhandari_eval = lem_in_eval_create(NULL, 0);
	new->bhandari_eval.cost = INT_MAX;
	new->bhandari_eval_test = lem_in_eval_create(NULL, 0);
	new->bhandari_length_array = vector_create(sizeof(int));
	new->bhandari_length_array_test = vector_create(sizeof(int));
	new->bhandari_paths = vector_create(sizeof(t_global_room *));
	new->out_ant_current = LEM_IN_NO_ANT;
	new->out_ant_next = 1;
	return (new);
}
