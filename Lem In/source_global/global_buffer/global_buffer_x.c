/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_buffer_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:42:50 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_buffer.h"

t_global_buffer		*global_buffer_new(void)
{
	t_global_buffer	*new;

	new = global_malloc(sizeof(t_ftp_buffer));
	new->data = global_malloc(GLOBAL_BUFFER_INIT);
	new->length = 0;
	new->capacity = GLOBAL_BUFFER_INIT;
	return (new);
}

void				global_buffer_delete(t_global_buffer **buffer)
{
	free((*buffer)->data);
	free(*buffer);
	*buffer = NULL;
}

void				global_buffer_concat(t_global_buffer *buffer, CHAR_REF str)
{
	int				new_length;

	new_length = buffer->length + (int)ft_strlen(str);
	if (new_length >= buffer->capacity)
	{
		ft_realloc((void **)&buffer->data,
			buffer->capacity, buffer->capacity * GLOBAL_BUFFER_MULT);
		buffer->capacity *= GLOBAL_BUFFER_MULT;
	}
	buffer->length = new_length;
	ft_strcat(buffer->data, str);
}
