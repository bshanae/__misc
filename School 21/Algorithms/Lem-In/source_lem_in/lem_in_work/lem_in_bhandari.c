/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_bhandari.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:47:18 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_work.h"

static void			helper_add_length(t_lem_in_main *main)
{
	int				length;

	length = lem_in_backtrack(main, NULL);
	vector_copy(&main->bhandari_length_array_test,
		&main->bhandari_length_array);
	if (main->bhandari_state == lem_in_bfs_normal)
		vector_push(&main->bhandari_length_array_test, &length);
	else if (main->bhandari_state == lem_in_bfs_confirmed_intersection)
		lem_in_solve_conflict(main);
	else
		global_raise_error("Lem-In, Bhandari : Unknown state");
}

static void			helper_lock(t_lem_in_main *main)
{
	if (main->bhandari_state == lem_in_bfs_confirmed_intersection)
		lem_in_lock_path_all(main);
	else
		lem_in_lock_path_last(main);
}

static void			helper_eval(t_lem_in_main *main)
{
	main->bhandari_eval_test = lem_in_eval_create(
		&main->bhandari_length_array_test, main->map.number_of_ants);
	if (main->bhandari_eval_test.cost < main->bhandari_eval.cost)
	{
		lem_in_eval_destroy(&main->bhandari_eval);
		main->bhandari_eval = main->bhandari_eval_test;
		lem_in_parent_save(main);
		vector_copy(&main->bhandari_length_array,
			&main->bhandari_length_array_test);
	}
	else
	{
		lem_in_eval_destroy(&main->bhandari_eval_test);
		lem_in_parent_restore(main);
	}
}

void				lem_in_bhandari(t_lem_in_main *main)
{
	t_global_bool	is_first;

	is_first = global_true;
	while (1)
	{
		if (!lem_in_bfs(main))
		{
			global_assert_critical(!is_first,
				"Lem-In Bhandari : No path leads to end");
			break ;
		}
		is_first = global_false;
		helper_add_length(main);
		helper_lock(main);
		helper_eval(main);
	}
}
