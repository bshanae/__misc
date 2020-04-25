/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:33:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:45:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

t_open_cl			*open_cl_new(int *image, t_easy *easy, t_ikido *ikido)
{
	t_open_cl		*new;

	if (!(new = (t_open_cl *)malloc(sizeof(t_open_cl))))
		exit(21);
	new->total_size = easy->width * easy->height;
	new->ikido_total_size = IKIDO_POINTS;
	open_cl_init(new);
	new->host.image = image;
	new->host.width = easy->width;
	new->host.height = easy->height;
	new->host.easy = easy;
	new->host.ikido = ikido;
	open_cl_set_size(new, easy->width, easy->height);
	new->zero = 0;
	return (new);
}

void				open_cl_delete(t_open_cl **me)
{
	clReleaseMemObject((*me)->device.image_gpu);
	clReleaseMemObject((*me)->device.image_cpu);
	clReleaseMemObject((*me)->device.camera);
	clReleaseMemObject((*me)->device.object);
	clReleaseMemObject((*me)->device.scene);
	clReleaseMemObject((*me)->device.width);
	clReleaseMemObject((*me)->device.height);
	clReleaseMemObject((*me)->device.counter);
	clReleaseMemObject((*me)->device.easy);
	clReleaseMemObject((*me)->device.ikido);
	clReleaseDevice((*me)->gpu);
	clReleaseContext((*me)->context_gpu);
	clReleaseProgram((*me)->program);
	clReleaseDevice((*me)->cpu);
	clReleaseContext((*me)->context_cpu);
	clReleaseCommandQueue((*me)->queue);
	clReleaseKernel((*me)->kernel);
	clReleaseProgram((*me)->easy_program);
	clReleaseCommandQueue((*me)->easy_queue);
	clReleaseKernel((*me)->easy_kernel);
	clReleaseProgram((*me)->ikido_program);
	clReleaseCommandQueue((*me)->ikido_queue);
	clReleaseKernel((*me)->ikido_kernel);
	free(*me);
	*me = NULL;
}

void				open_cl_set_size(t_open_cl *me, int width, int height)
{
	me->size.image = width * height * sizeof(int);
	me->size.camera = sizeof(t_camera);
	me->size.object = sizeof(t_object);
	me->size.scene = sizeof(t_scene);
	me->size.width = sizeof(int);
	me->size.height = sizeof(int);
	me->size.counter = sizeof(int);
	me->size.easy = sizeof(t_easy);
	me->size.ikido = sizeof(t_ikido);
}

void				open_cl_alloc_device(t_open_cl *me)
{
	int				error;

	me->device.image_gpu = clCreateBuffer(me->context_gpu,
		CL_MEM_WRITE_ONLY, me->size.image, NULL, &error);
	me->device.image_cpu = clCreateBuffer(me->context_cpu,
		CL_MEM_WRITE_ONLY, me->size.image, NULL, &error);
	me->device.camera = clCreateBuffer(me->context_gpu,
		CL_MEM_READ_ONLY, me->size.camera, NULL, &error);
	me->device.object = clCreateBuffer(me->context_gpu,
		CL_MEM_READ_ONLY, me->size.object, NULL, &error);
	me->device.scene = clCreateBuffer(me->context_gpu,
		CL_MEM_READ_ONLY, me->size.scene, NULL, &error);
	me->device.width = clCreateBuffer(me->context_gpu,
		CL_MEM_READ_ONLY, me->size.width, NULL, &error);
	me->device.height = clCreateBuffer(me->context_gpu,
		CL_MEM_READ_ONLY, me->size.height, NULL, &error);
	me->device.counter = clCreateBuffer(me->context_gpu,
		CL_MEM_READ_WRITE, me->size.counter, NULL, &error);
	me->device.easy = clCreateBuffer(me->context_gpu,
		CL_MEM_READ_ONLY, me->size.easy, NULL, &error);
	me->device.ikido = clCreateBuffer(me->context_cpu,
		CL_MEM_READ_ONLY, me->size.ikido, NULL, &error);
	error_check(__LINE__, __FUNCTION__, error);
}

void				open_cl_set_args(t_open_cl *me)
{
	int				error;

	error = clSetKernelArg(me->kernel, 0,
		sizeof(cl_mem), &me->device.image_gpu);
	error += clSetKernelArg(me->kernel, 1, sizeof(cl_mem), &me->device.camera);
	error += clSetKernelArg(me->kernel, 2, sizeof(cl_mem), &me->device.object);
	error += clSetKernelArg(me->kernel, 3, sizeof(cl_mem), &me->device.scene);
	error += clSetKernelArg(me->kernel, 4, sizeof(cl_mem), &me->device.width);
	error += clSetKernelArg(me->kernel, 5, sizeof(cl_mem), &me->device.height);
	error += clSetKernelArg(me->kernel, 6, sizeof(cl_mem), &me->device.counter);
	error += clSetKernelArg(me->easy_kernel, 0,
		sizeof(cl_mem), &me->device.image_gpu);
	error += clSetKernelArg(me->easy_kernel, 1,
		sizeof(cl_mem), &me->device.easy);
	error += clSetKernelArg(me->ikido_kernel, 0,
		sizeof(cl_mem), &me->device.image_cpu);
	error += clSetKernelArg(me->ikido_kernel, 1,
		sizeof(cl_mem), &me->device.ikido);
	error_check(__LINE__, __FUNCTION__, error);
}
