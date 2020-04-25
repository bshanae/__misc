/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_control_functions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:19:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:40:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_CONTROL_FUNCTIONS_H
# define FTP_CONTROL_FUNCTIONS_H

# include "ftp_format_in.h"
# include "ftp_format_data.h"
# include "ftp_format_out.h"

int					ftp_control_init
		(t_ftp_control *me, const char *extern_begin, va_list *arg_ptr);

void				ftp_control_format_reset(t_ftp_control *me);

int					ftp_control_format_run(t_ftp_control *me);

void				ftp_control_style(t_ftp_control *me);

void				ftp_control_style_clean(t_ftp_control *me);

#endif
