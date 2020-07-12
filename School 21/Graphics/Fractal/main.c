/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:08:44 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/30 11:09:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm.h"

int					main(void)
{
	t_rm			*rm;

	rm = rm_new();
	rm->object->iter = SDF_I_TETRAHEDRON;
	rm_set_camera(rm, (t_vector3){0., 0., 7.}, (t_vector3){0., 0., 0.});
	scene_push_light(rm->scene, (t_vector3) {-5., 3., -5.}, 1.4);
	scene_push_light(rm->scene, (t_vector3) {.0, -1., 0.}, 1.4);
	scene_push_light(rm->scene, (t_vector3) {-5., -5., -5.}, 1.4);
	scene_push_light(rm->scene, (t_vector3) {.0, 0., -1.}, .4);
	rm_render(rm);
	mlx_hook(rm->win_ptr, 2, 1, rm_key_press, rm);
	mlx_hook(rm->win_ptr, 3, 1, rm_key_release, rm);
	mlx_hook(rm->win_ptr, 4, 1, rm_mouse_scroll, rm);
	mlx_hook(rm->win_ptr, 6, 6, rm_mouse_move, rm);
	mlx_hook(rm->win_ptr, 17u >> 1u, 1, rm_exit, rm);
	mlx_loop(rm->mlx_ptr);
}
