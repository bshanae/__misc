/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_real.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:14:35 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:14:37 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_FORMAT_OUT_REAL_H
# define FTP_FORMAT_OUT_REAL_H

# include "long.h"
# include "ftp_control_definition.h"
# include "ftp_whitespaces.h"

typedef enum			e_round_type
{
	round_down,
	round_up,
	round_to_even
}						t_round_type;

typedef struct			s_real_memory
{
	u_long				mantissa : 64;
	u_int				exponent : 15;
	u_int				sign : 1;
}						t_real_memory;

typedef union			u_real_represent
{
	long double			real;
	t_real_memory		memory;
}						t_real_represent;

typedef struct			s_real_exception
{
	int					is_present;
	char				data[5];
	int					length;
}						t_real_exception;

typedef struct			s_real_long
{
	t_long				data;
	int					length;
}						t_real_long;

typedef struct			s_real_sign
{
	char				data[2];
	int					length;
}						t_real_sign;

typedef struct			s_params_real
{
	t_real_represent	represent;
	int					extract_exponent;
	t_real_sign			sign;
	int					force_point;
	t_real_long			whole;
	t_real_long			fract;
	t_real_exception	exception;
}						t_real_params;

int						ftp_format_out_real(t_ftp_control *ctrl);

int						ftp_format_out_real_init
	(t_real_params *real, t_ftp_control *ctrl, t_ftp_whitespaces *ws);

void					ftp_format_out_real_exceptions(t_real_params *real);

void					ftp_format_out_real_convert(t_real_params *real);

int						ftp_format_out_real_out
	(t_ftp_buffer *buff, t_real_params *real, int fract_limit);

void					ftp_format_out_real_round
	(t_real_params *real, int fract_limit);

#endif
