/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:42:10 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_BUFFER_H
# define GLOBAL_BUFFER_H

# include "global_error.h"

# include "libft_standart.h"

# define GLOBAL_BUFFER_INIT		100
# define GLOBAL_BUFFER_MULT		5

typedef struct		s_global_buffer
{
	char			*data;
	int				length;
	int				capacity;
}					t_global_buffer;

t_global_buffer		*global_buffer_new();
void				global_buffer_delete(t_global_buffer **buffer);

void				global_buffer_concat(t_global_buffer *buffer, CHAR_REF str);

#endif
