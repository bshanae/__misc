/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_buffer_main.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:35:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:36:07 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_BUFFER_MAIN_H
# define FTP_BUFFER_MAIN_H

# include "libft_standart.h"
# include "ftp_buffer_definition.h"

int						buffer_init
	(t_ftp_buffer *me, const char *extern_begin);

void					buffer_reset
	(t_ftp_buffer *me, const char *extern_begin);

#endif
