/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:38:06 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:45:16 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void				open_cl_load_host
	(t_open_cl *me, t_camera *camera,
	t_object *object, t_scene *scene)
{
	me->host.camera = camera;
	me->host.object = object;
	me->host.scene = scene;
	me->host.counter = 0;
}

void				open_cl_load_device(t_open_cl *me, int mod)
{
	int				error;

	error = 0;
	if (mod == MOD_3D)
	{
		error = clEnqueueWriteBuffer(me->queue, me->device.camera, CL_TRUE,
			0, me->size.camera, me->host.camera, 0, NULL, NULL);
		error += clEnqueueWriteBuffer(me->queue, me->device.object, CL_TRUE,
			0, me->size.object, me->host.object, 0, NULL, NULL);
		error += clEnqueueWriteBuffer(me->queue, me->device.scene, CL_TRUE,
			0, me->size.scene, me->host.scene, 0, NULL, NULL);
		error += clEnqueueWriteBuffer(me->queue, me->device.width, CL_TRUE,
			0, me->size.width, &me->host.width, 0, NULL, NULL);
		error += clEnqueueWriteBuffer(me->queue, me->device.height, CL_TRUE,
			0, me->size.height, &me->host.height, 0, NULL, NULL);
		error += clEnqueueWriteBuffer(me->queue, me->device.counter, CL_TRUE,
			0, me->size.counter, &me->host.counter, 0, NULL, NULL);
	}
	else if (mod == MOD_EASY)
		error = clEnqueueWriteBuffer(me->easy_queue, me->device.easy, CL_TRUE,
			0, me->size.easy, me->host.easy, 0, NULL, NULL);
	else if (mod == MOD_IKIDO)
		error = clEnqueueWriteBuffer(me->ikido_queue, me->device.ikido, CL_TRUE,
			0, me->size.ikido, me->host.ikido, 0, NULL, NULL);
	error_check(__LINE__, __FUNCTION__, error);
}

static int			run_3d(t_open_cl *me, int mod)
{
	int				error;

	if (mod == MOD_3D)
	{
		error = clEnqueueNDRangeKernel(me->queue, me->kernel, 1, NULL,
			&me->total_size, NULL, 0, NULL, NULL);
		error_check(__LINE__, __FUNCTION__, error);
		error = clEnqueueReadBuffer(me->queue, me->device.image_gpu, CL_TRUE,
			0, me->size.image, me->host.image, 0, NULL, NULL);
		error_check(__LINE__, __FUNCTION__, error);
	}
	return (mod == MOD_3D);
}

static void			run_2d(t_open_cl *me, int mod)
{
	int				error;

	if (mod == MOD_EASY)
	{
		error = clEnqueueNDRangeKernel(me->easy_queue, me->easy_kernel, 1, NULL,
			&me->total_size, NULL, 0, NULL, NULL);
		error_check(__LINE__, __FUNCTION__, error);
		error = clEnqueueReadBuffer(me->easy_queue, me->device.image_gpu,
				CL_TRUE, 0, me->size.image, me->host.image, 0, NULL, NULL);
		error_check(__LINE__, __FUNCTION__, error);
	}
	else if (mod == MOD_IKIDO)
	{
		clEnqueueFillBuffer(me->ikido_queue,
			me->device.image_cpu, &me->zero, 4, 0, me->total_size * 4, 0, 0, 0);
		error = clEnqueueNDRangeKernel(me->ikido_queue, me->ikido_kernel, 1,
				NULL, &me->ikido_total_size, NULL, 0, NULL, NULL);
		error_check(__LINE__, __FUNCTION__, error);
		error = clEnqueueReadBuffer(me->ikido_queue, me->device.image_cpu,
				CL_TRUE, 0, me->size.image, me->host.image, 0, NULL, NULL);
		error_check(__LINE__, __FUNCTION__, error);
	}
}

void				open_cl_run(t_open_cl *me, int mod)
{
	if (run_3d(me, mod))
		;
	else
		run_2d(me, mod);
}
