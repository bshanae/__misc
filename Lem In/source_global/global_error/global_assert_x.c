/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_assert_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:45:29 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_error.h"

void				global_assert(int statement, CHAR_REF message)
{
	if (!statement)
		global_raise_warning(message);
}

void				global_assert_critical(int statement, CHAR_REF message)
{
	if (!statement)
		global_raise_error(message);
}
