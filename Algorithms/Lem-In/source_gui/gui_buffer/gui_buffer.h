/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_buffer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:55:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:55:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_BUFFER_H
# define GUI_BUFFER_H

# include "global_error.h"
# include "gui_color.h"
# include "gui_object_x.h"

# include <SDL.h>

typedef struct		s_gui_buffer
{
	SDL_Surface		*source;
	t_gui_color		*data;
	int				width;
	int				height;
}					t_gui_buffer;

t_gui_buffer		*gui_buffer_new(int width, int height);
t_gui_buffer		*gui_buffer_new_from_source(SDL_Surface *source);
void				gui_buffer_delete(t_gui_buffer **buffer);

void				gui_buffer_set(t_gui_buffer *buffer, t_gui_color color);
void				gui_buffer_clear(t_gui_buffer *buffer);

void				gui_buffer_copy(t_gui_buffer *src, t_gui_buffer *dest);
void				gui_buffer_copy_limited(
	t_gui_buffer *src, t_gui_buffer *dest,
	t_gui_object_point_i min, t_gui_object_point_i max);

#endif
