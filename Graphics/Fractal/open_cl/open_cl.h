/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:14:26 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:39:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_CL_H
# define OPEN_CL_H

# define CL_SILENCE_DEPRECATION

# include <OpenCL/CL.h>

# include "libft_ft_printf.h"

# include "camera.h"
# include "object.h"
# include "scene.h"
# include "easy.h"
# include "ikido.h"

# define CL_SOURCE			"../open_cl/program.cl"
# define CL_FUNCTION		"render"

# define CL_EASY_SOURCE		"../open_cl/easy_program.cl"
# define CL_EASY_FUNCTION	"easy"

# define CL_IKIDO_SOURCE	"../open_cl/ikido_program.cl"
# define CL_IKIDO_FUNCTION	"ikido"
# define CL_IKIDO_INCL		"-I ../vector2/ -I ../ikido/ -I ../color"

# define OCL_BUFF_INIT		1000
# define OCL_BUFF_MULT		5

# define MOD_EASY			0
# define MOD_IKIDO			1
# define MOD_3D				2

typedef struct				s_host_data
{
	int						*image;
	t_camera				*camera;
	t_object				*object;
	t_scene					*scene;
	int						width;
	int						height;
	int						counter;
	t_easy					*easy;
	t_ikido					*ikido;
}							t_host_data;

typedef struct				s_device_data
{
	cl_mem					image_gpu;
	cl_mem					image_cpu;
	cl_mem					camera;
	cl_mem					object;
	cl_mem					scene;
	cl_mem					width;
	cl_mem					height;
	cl_mem					counter;
	cl_mem					easy;
	cl_mem					ikido;
}							t_device_data;

typedef struct				s_data_size
{
	u_long					image;
	u_long					camera;
	u_long					object;
	u_long					scene;
	u_long					width;
	u_long					height;
	u_long					counter;
	u_long					easy;
	u_long					ikido;
}							t_data_size;

typedef struct				s_open_cl
{
	cl_device_id			gpu;
	cl_context				context_gpu;
	cl_device_id			cpu;
	cl_context				context_cpu;
	cl_program				program;
	cl_kernel				kernel;
	cl_command_queue		queue;
	u_long					total_size;
	cl_kernel				easy_kernel;
	cl_command_queue		easy_queue;
	cl_program				easy_program;
	cl_kernel				ikido_kernel;
	cl_command_queue		ikido_queue;
	cl_program				ikido_program;
	u_long					ikido_total_size;
	t_data_size				size;
	t_host_data				host;
	t_device_data			device;
	int						zero;
}							t_open_cl;

t_open_cl					*open_cl_new
							(int *image, t_easy *easy, t_ikido *ikido);

void						open_cl_delete(t_open_cl **me);

void						error_raise
							(int line, const char *function_name, int error);

void						error_check
							(int line, const char *function_name, int error);

void						error_log
							(t_open_cl *me, cl_program *program, int error);

void						open_cl_set_size
							(t_open_cl *me, int width, int height);

void						open_cl_init(t_open_cl *me);

void						open_cl_create_context(t_open_cl *me);

cl_program					open_cl_create_program
							(t_open_cl *me,
							const char *file_name,
							const char *options,
							cl_context *context);

void						open_cl_alloc_device(t_open_cl *me);

void						open_cl_set_args(t_open_cl *me);

void						open_cl_load_host
							(t_open_cl *me,
							t_camera *camera,
							t_object *object,
							t_scene *scene);

void						open_cl_load_device(t_open_cl *me, int mod);

void						open_cl_run(t_open_cl *me, int mod);

#endif
