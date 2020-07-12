/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:44:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:44:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_FORMAT_DATA_H
# define FTP_FORMAT_DATA_H

# include "ftp_control_definition.h"

/*
********************************************************************************
**				MAIN
********************************************************************************
*/

void			ftp_format_data(t_ftp_control *ctrl);

void			ftp_format_data_abs(long long value, t_ftp_control *ctrl);

/*
********************************************************************************
**				DEFAULT
********************************************************************************
*/

int				ftp_format_data_in_default(t_ftp_control *ctrl);

/*
********************************************************************************
**				SHORT
********************************************************************************
*/

int				ftp_format_data_in_short(t_ftp_control *ctrl);

int				ftp_format_data_in_s_short(t_ftp_control *ctrl);

/*
********************************************************************************
**				LONG
********************************************************************************
*/

int				ftp_format_data_in_long(t_ftp_control *ctrl);

int				ftp_format_data_in_l_long(t_ftp_control *ctrl);

int				ftp_format_data_in_l_double(t_ftp_control *ctrl);

#endif
