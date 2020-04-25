/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_buffer_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:35:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:36:07 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_BUFFER_FUNCTIONS_H
# define FTP_BUFFER_FUNCTIONS_H

# include "libft_standart.h"
# include "utils.h"
# include "ftp_buffer_definition.h"

void		buffer_out(t_ftp_buffer *me);

void		buffer_extern_in(t_ftp_buffer *me);

void		buffer_custom_in_char(t_ftp_buffer *me, char c, int len);

void		buffer_custom_in_str(t_ftp_buffer *me, char *str);

#endif
