/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:23:45 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_main.h"

int					main(int argc, char **argv)
{
	t_gui_main		*data;
	int				fd;

	fd = argc > 1 ? open(argv[1], O_RDONLY) : 0;
	data = gui_main_new(fd);
	gui_main_loop(data);
	gui_main_delete(&data);
	close(fd);
	exit(0);
}
