/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:53:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:53:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_FORMAT_OUT_H
# define FTP_FORMAT_OUT_H

# include "ftp_control_definition.h"
# include "ftp_whitespaces.h"
# include "ftp_format_out_whole.h"
# include "ftp_format_out_real.h"

int			ftp_format_out(t_ftp_control *ctrl);

void		ftp_format_out_char(t_ftp_control *ctrl);

void		ftp_format_out_str(t_ftp_control *ctrl);

void		ftp_format_out_ptr(t_ftp_control *ctrl);

#endif
