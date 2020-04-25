/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:23:16 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_main_x.h"
#include "lem_in_work.h"

int					main(int argc, char **argv)
{
	t_lem_in_main	*main;

	main = lem_in_main_new();
	lem_in_main_load(main, argc, argv);
	lem_in_work(main);
	lem_in_main_delete(&main);
	return (0);
}
