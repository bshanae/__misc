/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:33:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:37:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int					is_num(const char *c)
{
	return ((*c >= '0' && *c <= '9') ||
			(*c == '-' && c[1] >= '0' && c[1] <= '9') ||
			(*c >= 'a' && *c <= 'f') ||
			(*c >= 'A' && *c <= 'F'));
}

void				map_read_warning(t_read_set *set, int warning)
{
	raise_warning(warning);
	set->warning = warning;
}

void				map_read_flags
	(t_read_set *set, int num, int color, int pass)
{
	if (num != -1)
		set->next_num = num;
	if (color != -1)
		set->next_color = color;
	if (pass != -1)
		set->num_pass = pass;
}

t_read_set			map_read_init(t_map *map, char *file_name)
{
	t_read_set		set;

	set.map = map;
	set.line_ptr = NULL;
	set.line_iter = NULL;
	set.map_i = 0;
	set.x = 0;
	set.y = 0;
	set.next_num = 1;
	set.next_color = 0;
	set.num_pass = 1;
	set.warning = 0;
	if ((set.fd = open(file_name, O_RDONLY)) == -1)
		map_read_warning(&set, WARN_FILE);
	return (set);
}

void				map_realloc(t_map *map)
{
	size_t			old_size;
	size_t			new_size;

	old_size = map->data_real_len;
	if (!map->data_real_len)
		new_size = (ALLOC_INIT);
	else
		new_size = (map->data_real_len * ALLOC_MULT);
	old_size *= sizeof(t_point_3d);
	new_size *= sizeof(t_point_3d);
	if (!ft_realloc((void **)&map->original, old_size, new_size))
		raise_error(ERR_ALLOC);
	else if (!map->data_real_len)
		map->data_real_len = (ALLOC_INIT);
	else
		map->data_real_len = (map->data_real_len * ALLOC_MULT);
}
