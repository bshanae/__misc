/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:46:48 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_error.h"

void				*global_malloc(u_long size)
{
	void			*ptr;

	ptr = malloc(size);
	global_assert_critical(ptr != NULL, "Global : Malloc error");
	return (ptr);
}
