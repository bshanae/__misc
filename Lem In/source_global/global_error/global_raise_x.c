/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_raise_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:47:16 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_error.h"

void				global_raise_warning(CHAR_REF message)
{
	if (GLOBAL_ERROR_PRINT)
		global_print_warning(message);
	if (GLOBAL_ERROR_W_ERROR)
		exit(2);
}

void				global_raise_error(CHAR_REF message)
{
	if (GLOBAL_ERROR_PRINT)
		global_print_error(message);
	exit(1);
}
