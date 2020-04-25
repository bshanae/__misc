/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_print_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:44:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:45:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_error.h"

void				ft_print_warning(t_error_config *config, CHAR_REF message)
{
	ft_printf("\033[0;31m");
	if (config)
	{
		ft_printf("%s", config->warning_prefix);
		if (config->message_print)
			ft_printf(" : %s", message);
	}
	else
		ft_printf("Warning : %s", message);
	ft_printf("\n");
	ft_printf("\033[0m");
}

void				ft_print_error(t_error_config *config, CHAR_REF message)
{
	ft_printf("\033[0;31m");
	if (config)
	{
		ft_printf("%s", config->error_prefix);
		if (config->message_print)
			ft_printf(" : %s", message);
	}
	else
		ft_printf("Error : %s", message);
	ft_printf("\n");
	ft_printf("\033[0m");
}
