/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_give_whole.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:50:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/21 18:02:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_FORMAT_OUT_WHOLE_H
# define FTP_FORMAT_OUT_WHOLE_H

# include "ftp_buffer_main.h"
# include "ftp_buffer_functions.h"
# include "ftp_control_definition.h"
# include "ftp_whitespaces.h"

typedef struct			s_whole_params
{
	unsigned long long	copy;
	int					base;
	int					is_upper;
	char				spec_char[3];
	int					spec_len;
	int					num_len;
}						t_ftp_whole_params;

void					ftp_format_out_whole(t_ftp_control *ctrl);

void					ftp_format_out_whole_init
	(t_ftp_whole_params *whole, t_ftp_control *ctrl);

void					ftp_format_out_whole_process
	(t_ftp_control *ctrl, t_ftp_whole_params *whole);

void					ftp_format_out_whole_out
	(t_ftp_whole_params *whole, t_ftp_control *ctrl);

#endif
