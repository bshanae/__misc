/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:28:10 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 14:28:13 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char				*extract_directory(const char *begin)
{
	char			*end;
	char			*result;

	end = ft_strrchr(begin, '/');
	if (!end)
		return (ft_strdup(""));
	result = ft_strnew(++end - begin);
	ft_strncpy(result, begin, end - begin);
	return (result);
}
