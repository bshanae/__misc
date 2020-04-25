/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:54:13 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 19:21:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vo.h"

int				main(int argc, char **argv)
{
	t_vo		*vo;

	vo = vo_init();
	if (argc > 1 && !map_read(&vo->map, argv[1]))
		vo_render(vo);
	mlx_hook(vo->win_ptr, 2, 1L << 0, vo_key_press, vo);
	mlx_hook(vo->win_ptr, 3, 1L << 0, vo_key_release, vo);
	mlx_loop(vo->mlx_ptr);
	return (1);
}
