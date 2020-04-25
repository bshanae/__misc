/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:40:20 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:40:20 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void				map_read_num(t_read_set *set)
{
	if (set->map->data_real_len < set->map_i + 1)
		map_realloc(set->map);
	set->map->original[set->map_i++] =
		point_init(set->x++, set->y, ft_atoi(set->line_iter));
	set->num_pass = 1;
	set->next_num = 0;
}

void				map_read_color(t_read_set *set)
{
	set->line_iter += 2;
	set->map->original[set->map_i - 1].color.mix =
		(ft_atoi_base(set->line_iter, 16));
	set->num_pass = 1;
	set->next_color = 0;
	set->map->color_change = MAP_C_FORBID;
}

int					map_read_line(t_read_set *set)
{
	set->line_iter = set->line_ptr;
	map_read_flags(set, 1, 0, 0);
	while (*set->line_iter)
	{
		if (set->warning)
			return (set->warning);
		if (*set->line_iter == ' ')
			map_read_flags(set, 1, -1, 0);
		else if (*set->line_iter == ',')
			map_read_flags(set, -1, 1, 0);
		else if (*set->line_iter == '0' && set->line_iter[1] == 'x' &&
		set->next_color)
			map_read_color(set);
		else if (is_num(set->line_iter) && set->next_num)
			map_read_num(set);
		else if (!set->num_pass)
			map_read_warning(set, WARN_CHAR);
		set->line_iter++;
	}
	if (!set->map->data_wid)
		set->map->data_wid = set->x;
	else if (set->map->data_wid != set->x)
		map_read_warning(set, WARN_STRUCT);
	set->map->data_len += set->x;
	return (0);
}

int					map_read(t_map *map, char *file_name)
{
	t_read_set		set;

	set = map_read_init(map, file_name);
	while (1)
	{
		if (set.warning)
			return (set.warning);
		if ((set.code = get_next_line(set.fd, &set.line_ptr)) < 0)
			map_read_warning(&set, WARN_GNL);
		if (!set.code)
			break ;
		if ((set.code = map_read_line(&set)))
			return (set.warning);
		free(set.line_ptr);
		set.x = 0;
		set.y++;
	}
	map_adjust(map);
	map_iso_adjust(map);
	map->data = (t_point_3d *)malloc(sizeof(t_point_3d) * map->data_len);
	if (!map->data)
		raise_error(ERR_ALLOC);
	ft_memcpy(map->data, map->original, sizeof(t_point_3d) * map->data_len);
	return (0);
}
