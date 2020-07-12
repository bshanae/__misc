/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 10:40:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/28 20:19:49 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_CONTROL_DEFINITION_H
# define FTP_CONTROL_DEFINITION_H

# include "libft_standart.h"
# include "libft_vector.h"
# include "utils.h"
# include "ftp_buffer_main.h"
# include "ftp_buffer_functions.h"

# include <stdarg.h>

# define FTP_ERR_ALLOC		-1
# define FTP_ERR_FORMAT		-2
# define FTP_ERR_INTERNAL	-3

# define FTP_STR_NUM_SIZE	30

# define FTP_RED			"\x1B[31m"
# define FTP_GREEN			"\x1B[32m"
# define FTP_YELLOW			"\x1B[33m"
# define FTP_BLUE			"\x1B[34m"
# define FTP_MAGENTA		"\x1B[35m"
# define FTP_CYAN			"\x1B[36m"
# define FTP_PURPLE			"\033[35m"
# define FTP_BOLD			"\033[1m"
# define FTP_UNDERLINE		"\033[4m"
# define FTP_RESET			"\x1B[0m"

typedef enum				e_ftp_size
{
	ftp_size_undef,
	ftp_size_hh,
	ftp_size_h,
	ftp_size_default,
	ftp_size_l,
	ftp_size_ll,
	ftp_size_L
}							t_ftp_size;

typedef enum				e_ftp_type
{
	ftp_type_undef,
	ftp_type_d,
	ftp_type_i,
	ftp_type_b,
	ftp_type_u,
	ftp_type_o,
	ftp_type_x,
	ftp_type_X,
	ftp_type_p,
	ftp_type_f,
	ftp_type_c,
	ftp_type_s,
	ftp_type_other
}							t_ftp_type;

typedef struct				s_ftp_flags
{
	int						minus;
	int						plus;
	int						space;
	int						zero;
	int						hash;
}							t_ftp_flags;

typedef struct				s_ftp_data
{
	unsigned long long		whole;
	int						whole_sign;
	char					whole_str[FTP_STR_NUM_SIZE];
	long double				real;
}							t_ftp_data;

typedef struct				s_ftp_format
{
	t_ftp_flags				flags;
	int						width;
	int						precision;
	t_ftp_size				size;
	t_ftp_type				type;
	t_ftp_data				data;
}							t_ftp_format;

typedef struct				s_ftp_functor
{
	char 					name[20];
	void 					(*func)(va_list);
}							t_ftp_functor;

typedef struct				s_ftp_special
{
	char					color_str[10];
	int						color_is_const;
	t_vector				functor_data;
}							t_ftp_special;

typedef struct				s_ftp_control
{
	t_ftp_buffer			buffer;
	va_list					*arg_ptr;
	t_ftp_format			format;
	t_ftp_special			special;
}							t_ftp_control;

#endif
