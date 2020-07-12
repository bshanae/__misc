/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:45:49 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_ERROR_H
# define GLOBAL_ERROR_H

# include "libft_standart.h"
# include "libft_gnl.h"
# include "libft_ft_printf.h"

# define GLOBAL_ERROR_PRINT		1
# define GLOBAL_ERROR_W_ERROR	1

# define GLOBAL_ERROR_RED		"\033[0;31m"
# define GLOBAL_ERROR_BLACK		"\033[0m"

void					global_print_warning(CHAR_REF message);
void					global_print_error(CHAR_REF message);

void					global_raise_warning(CHAR_REF message);
void					global_raise_error(CHAR_REF message);

void					global_assert(int statement, CHAR_REF message);
void					global_assert_critical(int statement, CHAR_REF message);

void					*global_malloc(u_long size);
int						global_gnl(int fd, char **line);

#endif
