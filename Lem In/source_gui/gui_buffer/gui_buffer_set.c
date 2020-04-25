/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_buffer_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:57:34 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:57:34 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_buffer.h"

void				gui_buffer_set(t_gui_buffer *buffer, t_gui_color color)
{
	SDL_FillRect(buffer->source, NULL, *(Uint32 *)&color);
}
