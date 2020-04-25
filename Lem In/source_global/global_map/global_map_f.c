/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_map_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:49:20 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_map.h"

int						global_map_f_insert(
	t_vector_iter *left_iter, t_vector_iter *right_iter)
{
	const t_global_room	*left_room = vector_iter_ptr(left_iter);
	const t_global_room	*right_room = vector_iter_ptr(right_iter);

	return (ft_strcmp(left_room->name, right_room->name));
}

int						global_map_f_find(t_vector_iter *iter, char *name)
{
	const t_global_room	*room = vector_iter_ptr(iter);

	return (ft_strcmp(room->name, name));
}
