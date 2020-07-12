/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:54:07 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:53:57 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm.h"

static void			set_mlx(t_rm *me)
{
	int				temp[3];

	me->mlx_ptr = mlx_init();
	me->win_ptr = mlx_new_window(me->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "RM");
	me->img_ptr = mlx_new_image(me->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	temp[0] = 8 * 4;
	temp[1] = WIN_WIDTH * 4;
	temp[2] = 0;
	me->img_data =
			(int *)mlx_get_data_addr(me->img_ptr, temp, temp + 1, temp + 2);
}

t_rm				*rm_new(void)
{
	t_rm			*new;

	if (!(new = (t_rm *)malloc(sizeof(t_rm))))
		exit(21);
	set_mlx(new);
	new->camera = camera_new(WIN_WIDTH / (tan((M_PI / 3.) / 2.)));
	new->scene = scene_new();
	new->object = object_new();
	new->easy = easy_new(WIN_WIDTH, WIN_HEIGHT);
	new->ikido = ikido_new(WIN_WIDTH, WIN_HEIGHT);
	new->mod = MOD_EASY;
	new->open_cl = open_cl_new(new->img_data, new->easy, new->ikido);
	open_cl_load_host(new->open_cl, new->camera, new->object, new->scene);
	open_cl_alloc_device(new->open_cl);
	open_cl_set_args(new->open_cl);
	new->shift_hold = 0;
	new->option_hold = 0;
	ikido_rng(new->ikido);
	return (new);
}

void				rm_delete(t_rm **me)
{
	camera_delete(&(*me)->camera);
	scene_delete(&(*me)->scene);
	object_delete(&(*me)->object);
	open_cl_delete(&(*me)->open_cl);
	easy_delete(&(*me)->easy);
	ikido_delete(&(*me)->ikido);
	mlx_destroy_image((*me)->mlx_ptr, (*me)->img_ptr);
	mlx_destroy_window((*me)->mlx_ptr, (*me)->win_ptr);
	free(*me);
	*me = NULL;
}

void				rm_set_camera
	(t_rm *me, t_vector3 position, t_vector3 angles)
{
	me->camera->position = position;
	me->camera->angles = angles;
	camera_recalculate(me->camera);
}

void				rm_render(t_rm *rm)
{
	open_cl_load_device(rm->open_cl, rm->mod);
	open_cl_run(rm->open_cl, rm->mod);
	mlx_put_image_to_window(rm->mlx_ptr, rm->win_ptr, rm->img_ptr, 0, 0);
}
