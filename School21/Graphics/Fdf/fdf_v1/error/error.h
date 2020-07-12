/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:51:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 17:51:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"

# include <stdio.h>

void					raise_error(char err_code);

int						raise_warning(char warning_code);

# define WARN_CHAR		11
# define WARN_FILE		12
# define WARN_GNL		13
# define WARN_STRUCT	14

# define ERR_INV_ARG	20
# define ERR_ALLOC		21

#endif
