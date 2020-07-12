/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vo.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:18:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 19:23:29 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VO_H
# define VO_H

# include "mlx.h"
# include "libft.h"
# include "error.h"
# include "color.h"
# include "quaternion.h"
# include "point.h"
# include "some_math.h"
# include "map.h"

/*
********************************************************************************
**						DEFINITION
********************************************************************************
*/

typedef struct			s_vo
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*img_data;
	t_map				map;
	t_map				swap_map;
	int					shift_mod;
	int					term_mod;
	int					term_message;
	char				term_buffer[64];
	int					term_i;
}						t_vo;

# define VO_WIN_WID 	1280
# define VO_WIN_HIGH 	720
# define VO_WIN_TITLE 	"..."

/*
********************************************************************************
**						MAIN
********************************************************************************
*/

t_vo					*vo_init();

void					vo_close(t_vo *vo);

void					vo_render(t_vo *vo);

/*
********************************************************************************
** 						CONTROL
********************************************************************************
*/

int						vo_key_press(int key, void *ptr);

int						vo_key_release(int key, void *ptr);

# define KEY_ESC		53

# define KEY_PLUS_1		24
# define KEY_PLUS_2		69
# define KEY_MINUS_1 	27
# define KEY_MINUS_2	78

# define KEY_LEFT_1		123
# define KEY_LEFT_2		86
# define KEY_RIGHT_1	124
# define KEY_RIGHT_2	88
# define KEY_DOWN_1		125
# define KEY_DOWN_2		84
# define KEY_UP_1		126
# define KEY_UP_2		91

# define KEY_BRACE_L	33
# define KEY_BRACE_R	30

# define KEY_SHIFT		257
# define KEY_COLON		41
# define KEY_ENTER		36
# define KEY_DEL		51
# define KEY_SPACE		49
# define KEY_DOT		47
# define KEY_SLASH		44
# define KEY_TILDA		50

# define KEY_A			0
# define KEY_B			11
# define KEY_C			8
# define KEY_D			2
# define KEY_E			14
# define KEY_F			3
# define KEY_G			5
# define KEY_H			4
# define KEY_I			34
# define KEY_J			38
# define KEY_K			40
# define KEY_L			37
# define KEY_M			46
# define KEY_N			45
# define KEY_O			31
# define KEY_P			35
# define KEY_Q			12
# define KEY_R			15
# define KEY_S			1
# define KEY_T			17
# define KEY_U			32
# define KEY_V			9
# define KEY_W			13
# define KEY_X			7
# define KEY_Y			16
# define KEY_Z			6

# define KEY_0			29
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_5			23
# define KEY_6			22
# define KEY_7			26
# define KEY_8			28
# define KEY_9			25

/*
********************************************************************************
** 						TERMINAL
********************************************************************************
*/

void					vo_term_launch(t_vo *vo);

void					vo_term_close(t_vo *vo);

void					vo_term_do(t_vo *vo);

/*
********************************************************************************
** 						TERMINAL FUNCS
********************************************************************************
*/

int						vo_term_open_file(t_vo *vo);

int						vo_term_palette(t_vo *vo);

void					vo_term_palette_info(t_vo *vo);

/*
********************************************************************************
** 						TERMINAL UTILS
********************************************************************************
*/

void					vo_term_get(t_vo *vo, int key);

void					vo_term_erase(t_vo *vo);

void					vo_term_clear(t_vo *vo);

void					vo_term_message(t_vo *vo, char *message);

void					vo_term_display(t_vo *vo);

/*
********************************************************************************
** 						TERMINAL TRANSLATE
********************************************************************************
*/

char					vo_term_translate(t_vo *vo, int key);

#endif
