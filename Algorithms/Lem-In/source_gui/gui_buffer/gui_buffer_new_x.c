/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_buffer_new_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:57:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:57:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_buffer.h"

t_gui_buffer		*gui_buffer_new(int width, int height)
{
	t_gui_buffer	*buffer;

	buffer = global_malloc(sizeof(t_gui_buffer));
	buffer->source = SDL_CreateRGBSurfaceWithFormat(0, width, height,
		32, SDL_PIXELFORMAT_RGBA8888);
	buffer->width = width;
	buffer->height = height;
	buffer->data = buffer->source->pixels;
	return (buffer);
}

t_gui_buffer		*gui_buffer_new_from_source(SDL_Surface *source)
{
	t_gui_buffer	*buffer;

	buffer = global_malloc(sizeof(t_gui_buffer));
	buffer->source = source;
	buffer->data = source->pixels;
	buffer->width = source->w;
	buffer->height = source->h;
	return (buffer);
}
