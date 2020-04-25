/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main_x.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:33:41 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_MAIN_X_H
# define LEM_IN_MAIN_X_H

# include "lem_in_main.h"
# include "lem_in_flags.h"

# include <limits.h>

t_lem_in_main		*lem_in_main_new(void);
void				lem_in_main_delete(t_lem_in_main **data);

void				lem_in_main_load(t_lem_in_main *main, int ac, char **av);

#endif
