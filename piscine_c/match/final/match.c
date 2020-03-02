/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:19:14 by bshanae           #+#    #+#             */
/*   Updated: 2019/02/10 21:21:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (*s2 != '*')
	{
		if (*s1 == 0)
			return (*s1 == *s2);
		else
			return (*s1 == *s2) ? (match(s1 + 1, s2 + 1)) : (0);
	}
	else
	{
		if (*s1 == 0)
			return (match(s1, s2 + 1));
		else
			return (match(s1, s2 + 1) || match(s1 + 1, s2));
	}
}
