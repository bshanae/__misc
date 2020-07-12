/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:35:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:41:20 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

static void			read_program
	(const char *file_name, char **target, u_long *length)
{
	int				fd;
	char			*buffer;
	u_long			buffer_capacity;
	u_long			buffer_unit;
	u_long			buffer_length;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_raise(__LINE__, __FUNCTION__, 0);
	buffer = (char *)malloc(OCL_BUFF_INIT);
	buffer_capacity = OCL_BUFF_INIT;
	buffer_length = 0;
	while ((buffer_unit = read(fd, buffer + buffer_length, 64)) > 0)
	{
		buffer_length += buffer_unit;
		if (buffer_length + 64 > buffer_capacity)
		{
			ft_realloc((void **)&buffer,
				buffer_capacity, buffer_capacity * OCL_BUFF_MULT);
			buffer_capacity *= OCL_BUFF_MULT;
		}
	}
	*target = buffer;
	*length = buffer_length;
}

void				open_cl_init(t_open_cl *me)
{
	int				error;

	open_cl_create_context(me);
	error_check(__LINE__, __FUNCTION__, error);
	me->program = open_cl_create_program(me, CL_SOURCE, NULL, &me->context_gpu);
	me->queue = clCreateCommandQueue(me->context_gpu, me->gpu, 0, &error);
	error_check(__LINE__, __FUNCTION__, error);
	me->kernel = clCreateKernel(me->program, CL_FUNCTION, &error);
	error_check(__LINE__, __FUNCTION__, error);
	me->easy_program = open_cl_create_program(me,
		CL_EASY_SOURCE, NULL, &me->context_gpu);
	me->easy_queue =
		clCreateCommandQueue(me->context_gpu, me->gpu, 0, &error);
	error_check(__LINE__, __FUNCTION__, error);
	me->easy_kernel =
		clCreateKernel(me->easy_program, CL_EASY_FUNCTION, &error);
	error_check(__LINE__, __FUNCTION__, error);
	me->ikido_program = open_cl_create_program(me,
		CL_IKIDO_SOURCE, CL_IKIDO_INCL, &me->context_cpu);
	me->ikido_queue =
			clCreateCommandQueue(me->context_cpu, me->cpu, 0, &error);
	error_check(__LINE__, __FUNCTION__, error);
	me->ikido_kernel =
			clCreateKernel(me->ikido_program, CL_IKIDO_FUNCTION, &error);
	error_check(__LINE__, __FUNCTION__, error);
}

void				open_cl_create_context(t_open_cl *me)
{
	cl_platform_id	platform;
	int				error;

	error = clGetPlatformIDs(1, &platform, NULL);
	error_check(__LINE__, __FUNCTION__, error);
	error = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &me->gpu, NULL);
	error_check(__LINE__, __FUNCTION__, error);
	me->context_gpu = clCreateContext(NULL, 1, &me->gpu, 0, 0, &error);
	error_check(__LINE__, __FUNCTION__, error);
	error = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &me->cpu, NULL);
	error_check(__LINE__, __FUNCTION__, error);
	me->context_cpu = clCreateContext(NULL, 1, &me->cpu, 0, 0, &error);
	error_check(__LINE__, __FUNCTION__, error);
}

cl_program			open_cl_create_program
	(t_open_cl *me, const char *file_name,
	const char *options, cl_context *context)
{
	int				error;
	char			*buffer;
	u_long			length;
	cl_program		program;

	read_program(file_name, &buffer, &length);
	program = clCreateProgramWithSource(*context, 1,
		(const char **)&buffer, &length, &error);
	free(buffer);
	error_check(__LINE__, __FUNCTION__, error);
	error = clBuildProgram(program, 0, NULL, options, NULL, NULL);
	if (error < 0)
		error_log(me, &program, error);
	return (program);
}
