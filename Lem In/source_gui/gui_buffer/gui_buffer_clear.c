/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_buffer_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:58:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:58:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_buffer.h"

void				gui_buffer_clear(t_gui_buffer *buffer)
{
	SDL_FillRect(buffer->source, NULL, 0);
}
