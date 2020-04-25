/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_room.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:57:41 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_ROOM_H
# define GLOBAL_ROOM_H

# include "global_range.h"

# include "libft_standart.h"
# include "libft_vector.h"
# include "libft_ft_printf.h"

typedef struct		s_global_room
{
	char			name[64];
	int				x;
	int				y;
	t_vector		links;
	void			*plugin;
}					t_global_room;

t_global_room		global_room_create(t_global_range name, int x, int y);
void				global_room_destroy(t_global_room *room);

void				global_room_info(t_global_room *room);

#endif
