/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:41:26 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_info.h"

void				lem_in_print_path(t_vector *vector, t_global_bool prefix)
{
	t_global_room	*room;
	int				i;

	if (prefix)
		ft_printf("[Lem-In Path] : ");
	ft_printf("{");
	i = (int)vector->length - 1;
	while (i >= 0)
	{
		room = *(t_global_room **)vector_at(vector, i--);
		ft_printf("'%s'", room->name);
		if (i >= 0)
			ft_printf(" -> ");
	}
	ft_printf("}\n");
}

void				lem_in_print_path2(t_vector *path2, t_global_bool prefix)
{
	int				i;
	t_vector		*path;

	if (prefix)
		ft_printf("[Lem-In Path2] :\n");
	ft_printf("{\n");
	i = 0;
	while ((path = vector_at(path2, i++)))
	{
		ft_printf("\t");
		lem_in_print_path(path, global_false);
	}
	ft_printf("}\n");
}

char				*lem_in_print_state(t_lem_in_state state)
{
	if (state == lem_in_not_seen)
		return ("lem_in_not_seen");
	else if (state == lem_in_seen)
		return ("lem_in_seen");
	else if (state == lem_in_visited)
		return ("lem_in_visited");
	global_raise_warning("Lem-In : Print, Unknown state");
	return (NULL);
}

void				lem_in_print_room(t_global_room *room)
{
	t_lem_in_plugin	*plugin;

	plugin = room->plugin;
	global_room_info(room);
	ft_printf("[Lem-In Plugin] : ");
	ft_printf("state = %s, ", lem_in_print_state(plugin->state));
	ft_printf("current parent = '%s'\n", plugin->parent_current ?
			plugin->parent_current->name : NULL);
	ft_printf("best parent = '%s'\n", plugin->parent_best ?
			plugin->parent_best->name : NULL);
}

void				lem_in_print_eval(t_lem_in_eval *eval, t_global_bool prefix)
{
	int				i;
	int				*value;

	if (prefix)
		ft_printf("[lem-In Eval] : ");
	ft_printf("cost = %d, distribution = {", eval->cost);
	i = 0;
	while ((value = vector_at(&eval->distribution, i++)))
	{
		ft_printf("%d", *value);
		if (i != eval->distribution.length)
			ft_printf(", ");
	}
	ft_printf("}\n");
}
