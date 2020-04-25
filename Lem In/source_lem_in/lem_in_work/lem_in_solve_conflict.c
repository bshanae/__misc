/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_solve_conflict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:39:18 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_work.h"

void				lem_in_solve_conflict(t_lem_in_main *main)
{
	int				i;
	t_global_room	*room;
	int				length;

	i = 0;
	vector_clear(&main->bhandari_length_array_test);
	while (i < main->bhandari_paths.length)
	{
		room = *(t_global_room **)vector_at(&main->bhandari_paths, i++);
		length = lem_in_backtrack(main, room);
		vector_push(&main->bhandari_length_array_test, &length);
	}
}
