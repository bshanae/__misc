/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:52:07 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 19:22:58 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "error.h"
# include "point.h"
# include "some_math.h"

typedef struct			s_map
{
	int					*img;
	int					img_wid;
	int					img_high;
	int					mod;
	t_point_3d			*data;
	t_btree				*tree;
	int					tree_is_fresh;
	int					data_wid;
	int					data_len;
	int					data_real_len;
	t_point_2d			offset;
	int					offset_step;
	double				zoom_step;
	double				rotation_step;
	t_point_3d			*original;
	double				iso_zoom;
	t_point_2d			iso_offset;
	int					color_change;
	int					palette_clean;
	t_palette			*palette_head;
	t_palette			*palette_iter_tree;
	t_palette			*palette_iter_iso;
}						t_map;

# define MAP_MOD_ISO	0
# define MAP_MOD_FREE	1

# define MAP_C_FORBID	0
# define MAP_C_ALLOW	1

/*
********************************************************************************
** 						MAIN
********************************************************************************
*/

t_map					map_init(int wid, int high, int mod);

void					map_close(t_map *map);

void					map_reset(t_map *map);

void					map_adjust(t_map *map);

void					map_point_set
	(t_map *map, const int *x, const int *y, const t_color *color);

/*
********************************************************************************
** 						READ
********************************************************************************
*/

typedef struct			s_read_set
{
	t_map				*map;
	int					map_i;
	int					x;
	int					y;
	int					fd;
	int					code;
	char				*line_ptr;
	char				*line_iter;
	int					next_num;
	int					next_color;
	int					num_pass;
	int					warning;
}						t_read_set;

void					map_read_num(t_read_set *set);

void					map_read_color(t_read_set *set);

int						map_read_line(t_read_set *set);

int						map_read(t_map *map, char *file_name);

/*
********************************************************************************
** 						READ UTILS
********************************************************************************
*/

int						is_num(const char *c);

void					map_read_warning(t_read_set *set, int warning);

void					map_read_flags
	(t_read_set *set, int num, int color, int pass);

t_read_set				map_read_init(t_map *map, char *file_name);

void					map_realloc(t_map *map);

# define ALLOC_INIT 	100
# define ALLOC_MULT 	11

/*
********************************************************************************
** 						FUNCTIONS
********************************************************************************
*/

void					map_zoom(t_map *map, int mod_sign);

void					map_shift(t_map *map, int mod_axis, int mod_sign);

void					map_rotate(t_map *map, int mod_axis, int mod_sign);

int						map_palette_set(t_map *map, int is_switch);

# define MOD_SIGN_MINUS	-1
# define MOD_SIGN_PLUS	1

/*
********************************************************************************
** 						WU
********************************************************************************
*/

typedef struct			s_wu_set
{
	t_map				*map;
	t_point_2d			a;
	t_point_2d			b;
	t_point_2d			delta;
	t_point_2d			end;
	t_point_2d			l1;
	t_point_2d			l2;
	int					steep;
	double				gradient;
	double				intersection;
	double				gap;
}						t_wu_set;

void					map_wu
	(t_map *map, const t_point_2d *a, const t_point_2d *b);

/*
********************************************************************************
** 						ISO
********************************************************************************
*/

void					map_iso_adjust(t_map *map);

t_point_2d				map_iso_point(t_map *map, t_point_3d *p);

void					map_iso_render(t_map *map);

/*
********************************************************************************
** 						TREE_RENDER
********************************************************************************
*/

typedef struct			s_tree_point
{
	t_map				*map;
	int					i;
	char				neighbors[4];
	long long			trash[100];
}						t_tree_point;

# define TP_N_LOWER		0
# define TP_N_UPPER		1
# define TP_N_LEFT		2
# define TP_N_RIGHT		3

# define TP_NOT_DRAWN	0
# define TP_DRAWN		1

void					map_tree_insert(t_map *map, int i);

void					map_tree_render(t_map *map);

/*
********************************************************************************
** 						TREE_UTILS
********************************************************************************
*/

t_point_2d				map_tree_point(t_map *map, int i);

int						map_tree_cmp(const void *m1, const void *m2);

void					map_tree_neighbor
	(t_tree_point *tp, int n, t_point_2d *me, t_point_2d *neighbor_p);

#endif
