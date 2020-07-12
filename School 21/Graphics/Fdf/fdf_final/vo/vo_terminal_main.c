/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vo_terminal_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:55:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 19:13:12 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vo.h"

void				vo_term_launch(t_vo *vo)
{
	vo->term_mod = 1;
	vo->term_i = 0;
	vo_term_display(vo);
}

void				vo_term_close(t_vo *vo)
{
	vo->term_mod = 0;
	vo->term_i = 0;
	vo->term_message = 0;
	ft_bzero(vo->term_buffer, 64);
	mlx_clear_window(vo->mlx_ptr, vo->win_ptr);
	vo_render(vo);
}

void				vo_term_do(t_vo *vo)
{
	if (!ft_strcmp(vo->term_buffer, "exit"))
		vo_close(vo);
	else if (!ft_strcmp(vo->term_buffer, "reset"))
		map_reset(&vo->map);
	else if (!ft_strcmp(vo->term_buffer, "iso"))
		vo->map.mod = MAP_MOD_ISO;
	else if (!ft_strcmp(vo->term_buffer, "free"))
		vo->map.mod = MAP_MOD_FREE;
	else if (!ft_strncmp(vo->term_buffer, "open ", 5))
	{
		if (vo_term_open_file(vo))
			return ;
	}
	else if (!ft_strncmp(vo->term_buffer, "palette info", 12))
		return (vo_term_palette_info(vo));
	else if (!ft_strncmp(vo->term_buffer, "palette ", 8))
	{
		if (vo_term_palette(vo))
			return ;
	}
	else
		return (vo_term_message(vo, "unknown command"));
	vo_term_close(vo);
}
