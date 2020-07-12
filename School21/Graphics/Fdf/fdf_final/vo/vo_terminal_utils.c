/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vo_terminal_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:56:00 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:58:34 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vo.h"

void				vo_term_get(t_vo *vo, int key)
{
	char str[2];

	if (vo->term_message)
	{
		vo_term_display(vo);
		vo->term_message = 0;
		return ;
	}
	if (key == KEY_ESC)
		vo_term_close(vo);
	else if (key == KEY_ENTER)
	{
		vo->term_buffer[vo->term_i] = '\0';
		vo_term_do(vo);
	}
	else if (key == KEY_DEL)
		vo_term_erase(vo);
	else
	{
		str[0] = vo_term_translate(vo, key);
		str[1] = '\0';
		vo->term_buffer[vo->term_i] = str[0];
		mlx_string_put(vo->mlx_ptr, vo->win_ptr,
			100 + vo->term_i++ * 10, 690, WHITE, str);
	}
}

void				vo_term_erase(t_vo *vo)
{
	if (!vo->term_i)
		vo_term_close(vo);
	else
	{
		vo->term_buffer[--vo->term_i] = '\0';
		vo_term_display(vo);
	}
}

void				vo_term_clear(t_vo *vo)
{
	vo->term_i = 0;
	ft_bzero(vo->term_buffer, 64);
	vo_render(vo);
	vo_term_display(vo);
}

void				vo_term_display(t_vo *vo)
{
	t_point_2d		a;
	t_point_2d		b;
	char			str[2];

	a = (t_point_2d){.x = 0, .y = VO_WIN_HIGH - 40,
			.color.mix = WHITE};
	b = (t_point_2d){.x = VO_WIN_WID, .y = VO_WIN_HIGH - 40,
			.color.mix = WHITE};
	ft_strcpy(str, ":");
	map_wu(&vo->map, &a, &b);
	mlx_put_image_to_window(vo->mlx_ptr, vo->win_ptr, vo->img_ptr, 0, 0);
	mlx_string_put(vo->mlx_ptr, vo->win_ptr,
		90, VO_WIN_HIGH - 30, WHITE, str);
	mlx_string_put(vo->mlx_ptr, vo->win_ptr,
		100, VO_WIN_HIGH - 30, WHITE, vo->term_buffer);
}

void				vo_term_message(t_vo *vo, char *message)
{
	vo->term_message = 1;
	vo_term_clear(vo);
	mlx_string_put(vo->mlx_ptr, vo->win_ptr,
		100, VO_WIN_HIGH - 30, WHITE, message);
}
