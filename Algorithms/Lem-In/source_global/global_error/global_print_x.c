/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_print_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:47:03 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_error.h"

void				global_print_warning(CHAR_REF message)
{
	ft_printf(GLOBAL_ERROR_RED);
	ft_printf("GLOBAL WARNING : ");
	ft_printf(message);
	ft_printf("\n");
	ft_printf(GLOBAL_ERROR_BLACK);
}

void				global_print_error(CHAR_REF message)
{
	ft_printf(GLOBAL_ERROR_RED);
	ft_printf("GLOBAL ERROR : ");
	ft_printf(message);
	ft_printf("\n");
	ft_printf(GLOBAL_ERROR_BLACK);
}
