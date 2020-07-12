/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:52:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 17:22:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RM_H
# define RM_H

# include "libft_ft_printf.h"

# include "mlx.h"
# include "mlx_keys.h"
# include "camera.h"
# include "scene.h"
# include "object.h"
# include "open_cl.h"
# include "easy.h"
# include "ikido.h"

# define MACBOOK

# ifdef MACBOOK
#  define WIN_WIDTH			1440
#  define WIN_HEIGHT		900
# endif

# ifdef HD
#  define WIN_WIDTH			720
#  define WIN_HEIGHT		480
# endif

# ifdef MADLAD
#  define WIN_WIDTH			2560
#  define WIN_HEIGHT		1440
# endif

# define CAMERA_POS_STEP	0.25
# define CAMERA_DIR_STEP	0.05
# define JULIA_STEP			0.1

# define EASY_MAX_ITER		1500

typedef	struct				s_rm
{
	int						mod;
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	int						*img_data;
	t_camera				*camera;
	t_scene					*scene;
	t_object				*object;
	t_open_cl				*open_cl;
	t_easy					*easy;
	t_ikido					*ikido;
	int						shift_hold;
	int						option_hold;
}							t_rm;

t_rm						*rm_new(void);

void						rm_delete(t_rm **me);

void						rm_set_camera
							(t_rm *me,
							t_vector3 position,
							t_vector3 angles);

void						rm_render(t_rm *me);

int							rm_key_press(int key, void *ptr);

int							rm_key_release(int key, void *ptr);

int							rm_mouse_move(int x, int y, t_rm *rm);

int							rm_mouse_scroll(int button, int x, int y, t_rm *rm);

int							rm_exit(void *ptr);

int							rm_ctrl_camera_position(t_rm *me, int key);

int							rm_ctrl_camera_direction(t_rm *me, int key);

int							rm_ctrl_julia(t_rm *me, int key);

int							rm_ctrl_object_iter(t_rm *me, int key);

int							rm_ctrl_easy(t_rm *me, int key);

int							rm_ctrl_ikido(t_rm *me, int key);

int							rm_ctrl_easy_mandelbrot(t_rm *me, int key);

int							rm_ctrl_easy_julia(t_rm *me, int key);

#endif
