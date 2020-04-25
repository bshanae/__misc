/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:51:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 17:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void					raise_error(char err_code)
{
	if (err_code == ERR_INV_ARG)
		ft_putendl("Error : invalid number of arguments");
	else if (err_code == ERR_ALLOC)
		ft_putendl("Error : allocation failed\n");
	exit(err_code);
}

int						raise_warning(char warning_code)
{
	if (warning_code == WARN_CHAR)
		ft_putendl("Warning : invalid file content\n");
	else if (warning_code == WARN_STRUCT)
		ft_putendl("Warning : invalid file structure\n");
	else if (warning_code == WARN_FILE)
		perror("Warning ");
	else if (warning_code == WARN_GNL)
		ft_putendl("Warning : can't read file\n");
	return (warning_code);
}
