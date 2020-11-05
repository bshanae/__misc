/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:31:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:31:10 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ftp_buffer_main.h"
# include "ftp_buffer_functions.h"
# include "ftp_control_definition.h"
# include "ftp_control_functions.h"

int					ft_printf(const char *format, ...);

#endif
