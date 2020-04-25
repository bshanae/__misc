/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_buffer_copy_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:57:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:57:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_buffer.h"

void				gui_buffer_copy(
	t_gui_buffer *source, t_gui_buffer *destination)
{
	SDL_BlitSurface(source->source, NULL, destination->source, NULL);
}

void				gui_buffer_copy_limited(
	t_gui_buffer *source, t_gui_buffer *destination,
	t_gui_object_point_i min, t_gui_object_point_i max)
{
	SDL_Rect		rectangle;

	rectangle.x = min.x;
	rectangle.y = min.y;
	rectangle.w = max.x - min.x;
	rectangle.h = max.y - min.y;
	SDL_BlitSurface(source->source,
		&rectangle, destination->source, &rectangle);
}
