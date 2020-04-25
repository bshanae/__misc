/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:46:26 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_error.h"

int					global_gnl(int fd, char **line)
{
	int				result;

	result = gnl(fd, line);
	if (result < 0)
		global_raise_error("GNL error");
	return (result);
}
