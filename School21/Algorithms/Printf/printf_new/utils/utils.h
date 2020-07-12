/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:02:52 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/21 18:03:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft_standart.h"

int							is_digit(const char *c);

void						print_bits
	(unsigned long long value, u_int len, int endl);

double						safe_atof(const char *str);

char						get_digit(int i, int is_upper);

void						fast_char_out(int fd, char c, int len);

#endif
