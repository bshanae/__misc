/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_buffer_defintion.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:36:05 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:36:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_BUFFER_DEFINITION_H
# define FTP_BUFFER_DEFINITION_H

typedef struct			s_ftp_buffer
{
	const char			*extern_begin;
	const char			*extern_end;
	char				*begin;
	char				*end;
	char				*iter;
	int					chars_read;
	int					fd;
}						t_ftp_buffer;

# define FTP_BUFF_SIZE	32000

#endif
