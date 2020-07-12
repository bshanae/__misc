/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vo_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:55:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 19:20:12 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vo.h"

t_vo				*vo_init(void)
{
	t_vo			*new;
	int				temp[3];

	if (!(new = (t_vo *)malloc(sizeof(t_vo))))
		raise_error(ERR_ALLOC);
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr,
		VO_WIN_WID, VO_WIN_HIGH, VO_WIN_TITLE);
	new->img_ptr = mlx_new_image(new->mlx_ptr,
		VO_WIN_WID, VO_WIN_HIGH);
	temp[0] = 8 * 4;
	temp[1] = VO_WIN_WID * 4;
	temp[2] = 0;
	new->img_data =
		(int *)mlx_get_data_addr(new->img_ptr, temp, temp + 1, temp + 2);
	if (!new->img_data)
		raise_error(ERR_ALLOC);
	new->map = map_init(VO_WIN_WID, VO_WIN_HIGH, MAP_MOD_ISO);
	new->map.img = new->img_data;
	new->shift_mod = 0;
	new->term_mod = 0;
	new->term_message = 0;
	new->term_i = 0;
	ft_bzero(new->term_buffer, 64);
	return (new);
}

void				vo_close(t_vo *vo)
{
	mlx_destroy_window(vo->mlx_ptr, vo->win_ptr);
	mlx_destroy_image(vo->mlx_ptr, vo->img_ptr);
	map_close(&vo->map);
	free(vo);
	exit(0);
}

void				vo_render(t_vo *vo)
{
	if (vo->map.mod == MAP_MOD_FREE)
	{
		map_tree_render(&vo->map);
	}
	else
		map_iso_render(&vo->map);
	mlx_put_image_to_window(vo->mlx_ptr, vo->win_ptr, vo->img_ptr, 0, 0);
}
