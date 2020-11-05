/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_buffer_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:57:26 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:57:26 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_buffer.h"

void				gui_buffer_delete(t_gui_buffer **buffer)
{
	SDL_FreeSurface((*buffer)->source);
	(*buffer)->data = NULL;
	(*buffer)->width = -1;
	(*buffer)->height = -1;
	free(*buffer);
	*buffer = NULL;
}
