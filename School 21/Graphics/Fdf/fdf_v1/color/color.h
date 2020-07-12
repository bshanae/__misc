/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:42:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 17:49:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "error.h"

typedef struct			s_rgb
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
	unsigned char		a;
}						t_rgb;

typedef union			u_color
{
	int					mix;
	t_rgb				rgb;
}						t_color;

typedef struct			s_palette
{
	int					num;
	t_color				data[3];
	struct s_palette	*next;
}						t_palette;

# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define BLUE			0x0000FF

t_color					color_adjust(int original, double rate);

void					color_palette_build(t_palette **palette);

void					color_palette_destroy(t_palette **palette);

#endif
