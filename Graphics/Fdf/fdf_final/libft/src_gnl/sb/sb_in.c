/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:37:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/26 21:55:09 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				sb_in(t_sb *sb, int bs)
{
	int			read_num;

	read_num = 0;
	sb->out_end = NULL;
	while (1)
	{
		if (sb->in + bs >= sb->end)
			sb_reset(sb);
		while (sb->in - sb->out_begin + bs > sb->size)
			if (sb_realloc(sb, sb->size * SB_MULT) == SB_ERR_ALLOC)
				return (SB_ERR_ALLOC);
		read_num = read(sb->fd, sb->in, bs);
		if (read_num == -1)
			return (SB_ERR_FILE);
		sb->in += read_num;
		if (sb->in + 1 != sb->out_begin)
			sb->out_end = ft_memchr(sb->out_begin + read_num,
									'\n',
									sb->in - sb->out_begin - read_num);
		if (read_num == 0)
			return (SB_IN_EOF);
	}
	return (SB_IN_MID);
}
