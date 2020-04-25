/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:48:57 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_work.h"

static void				helper_move(
	t_lem_in_main *main, t_global_room *parent, t_global_room *me)
{
	t_lem_in_plugin		*plugin_parent;
	t_lem_in_plugin		*plugin_me;

	plugin_parent = parent->plugin;
	plugin_me = me->plugin;
	if (main->out_is_first_in_row)
		main->out_is_first_in_row = global_false;
	else
		ft_printf(" ");
	ft_printf("L%d-%s", plugin_me->ant, parent->name);
	plugin_parent->ant = plugin_me->ant;
	plugin_me->ant = LEM_IN_NO_ANT;
}

static t_global_bool	helper_recur(
	t_lem_in_main *main, t_global_room *parent, t_global_room *me)
{
	t_lem_in_plugin		*my_plugin;
	t_global_bool		child_result;

	my_plugin = me->plugin;
	if (me == main->map.start && main->out_ant_current == LEM_IN_NO_ANT)
		return (global_false);
	else if (me == main->map.start && main->out_ant_current != LEM_IN_NO_ANT)
	{
		my_plugin->ant = main->out_ant_current;
		helper_move(main, parent, me);
		return (global_true);
	}
	child_result = my_plugin->ant != LEM_IN_NO_ANT;
	if (my_plugin->ant != LEM_IN_NO_ANT)
		helper_move(main, parent, me);
	return (helper_recur(main, me, my_plugin->parent_best) || child_result);
}

static void				helper_ant_next(
	t_lem_in_main *main, t_vector_iter *iter)
{
	int					*ants_left;

	ants_left = vector_iter_ptr(iter);
	if (*ants_left > 0)
	{
		main->out_ant_current = main->out_ant_next++;
		(*ants_left)--;
	}
	else
		main->out_ant_current = LEM_IN_NO_ANT;
}

void					lem_in_out(t_lem_in_main *main)
{
	t_vector_iter		iter_end;
	t_vector_iter		iter_distribution;
	t_global_bool		is_at_least_one;
	t_global_bool		test;

	while (1)
	{
		is_at_least_one = global_false;
		main->out_is_first_in_row = global_true;
		iter_end = vector_iter_set(&main->bhandari_paths, -1);
		iter_distribution =
			vector_iter_set(&main->bhandari_eval.distribution, -1);
		while (vector_iter_next(&iter_end) &&
				vector_iter_next(&iter_distribution))
		{
			helper_ant_next(main, &iter_distribution);
			test = helper_recur(main, main->map.end,
					*(t_global_room **)vector_iter_ptr(&iter_end));
			is_at_least_one = is_at_least_one || test;
		}
		if (!is_at_least_one)
			break ;
		ft_printf("\n");
	}
}
