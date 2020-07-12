/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:39:34 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_flags.h"

void				lem_in_flags(t_lem_in_main *main, int ac, char **av)
{
	int				i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == 'f' && i + 1 < ac)
			{
				main->fd = open(av[i + 1], O_RDONLY);
				global_assert_critical(main->fd != -1,
					"Lem-In : Flags, File error");
			}
			else if (!ft_strcmp(av[i], "print_only"))
				main->print_only = global_true;
		}
		i++;
	}
}
