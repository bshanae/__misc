/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_info_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:41:03 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_info.h"

void				lem_in_info_map(t_lem_in_main *main)
{
	int				i;
	t_global_room	*room;

	i = 0;
	ft_printf("[Lem-In Map] : ");
	while ((room = vector_at(&main->map.data, i++)))
		lem_in_print_room(room);
}
