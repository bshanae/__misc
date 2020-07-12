/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:43:03 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 17:48:49 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color					color_adjust(int original, double rate)
{
	t_color		c;

	c.mix = original;
	c.rgb.r = (unsigned char)(c.rgb.r * rate);
	c.rgb.g = (unsigned char)(c.rgb.g * rate);
	c.rgb.b = (unsigned char)(c.rgb.b * rate);
	return (c);
}

static t_palette		*color_alloc_palette(int num, int c0, int c1, int c2)
{
	t_palette			*new;

	if (!(new = (t_palette *)malloc(sizeof(t_palette))))
		raise_error(ERR_ALLOC);
	new->num = num;
	new->data[0].mix = c0;
	new->data[1].mix = c1;
	new->data[2].mix = c2;
	new->next = NULL;
	return (new);
}

static void				color_palette_push_back
	(t_palette **palette, int c0, int c1, int c2)
{
	t_palette			*iter;
	int					count;

	if (!*palette)
	{
		*palette = color_alloc_palette(0, c0, c1, c2);
		return ;
	}
	iter = *palette;
	count = 0;
	while (iter->next)
	{
		iter = iter->next;
		count++;
	}
	iter->next = color_alloc_palette(count, c0, c1, c2);
}

void					color_palette_build(t_palette **palette)
{
	*palette = NULL;
	color_palette_push_back(palette, 0xFE4365, 0xF9CDAD, 0x83AF9B);
	color_palette_push_back(palette, 0x555E7B, 0xB7D968, 0xB576AD);
	color_palette_push_back(palette, 0xECD078, 0xC02942, 0x53777A);
	color_palette_push_back(palette, 0xE97F02, 0xF8CA00, 0x8A9B0F);
	color_palette_push_back(palette, 0xf38181, 0xfad284, 0xa9eec2);
	color_palette_push_back(palette, 0x98ff30, 0x30ffff, 0xff3030);
	color_palette_push_back(palette, 0x51ffee, 0xffa551, 0xff515a);
}

void					color_palette_destroy(t_palette **palette)
{
	t_palette			*iter;
	t_palette			*next;

	iter = *palette;
	while (iter->next)
	{
		next = iter->next;
		free(iter);
		iter = next;
	}
	*palette = NULL;
}
