/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vo_terminal_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:55:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 19:19:03 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vo.h"

int					vo_term_open_file(t_vo *vo)
{
	vo->swap_map = map_init(VO_WIN_WID, VO_WIN_HIGH, MAP_MOD_ISO);
	vo->swap_map.img = vo->img_data;
	if (map_read(&vo->swap_map, vo->term_buffer + 5))
	{
		vo_term_message(vo, "error");
		return (1);
	}
	map_close(&vo->map);
	vo->map = vo->swap_map;
	return (0);
}

int					vo_term_palette(t_vo *vo)
{
	int				num;
	t_palette		*palette;

	if (vo->term_buffer[8] < '0' || vo->term_buffer[8] > '9')
	{
		vo_term_message(vo, "incorrect input");
		return (1);
	}
	num = ft_atoi(vo->term_buffer + 8);
	palette = vo->map.palette_head;
	while (palette->next)
		if (palette->num == num)
			break ;
		else
			palette = palette->next;
	if (!palette->next)
	{
		vo_term_message(vo, "no such palette");
		return (1);
	}
	if (vo->map.mod == MAP_MOD_ISO)
		vo->map.palette_iter_iso = palette;
	else
		vo->map.palette_iter_tree = palette;
	return (map_palette_set(&vo->map, 0));
}

void				vo_term_palette_info(t_vo *vo)
{
	char			dest[30];
	char			*str;
	t_palette		*iter;

	if (!vo->map.palette_clean)
	{
		iter = vo->map.mod == MAP_MOD_ISO ?
			vo->map.palette_iter_iso :
			vo->map.palette_iter_tree;
		ft_strcpy(dest, "palette num. ");
		str = ft_itoa(iter->num);
		ft_strcat(dest, str);
		free(str);
	}
	else
		ft_strcpy(dest, "palette is unset");
	vo_term_message(vo, dest);
}
