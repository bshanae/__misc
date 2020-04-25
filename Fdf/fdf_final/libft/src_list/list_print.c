/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:31:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:31:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				list_print
	(t_list **alst, void (*print)(const void *content))
{
	const t_list	*iter;

	if (!alst || !print)
		return ;
	if (!*alst)
	{
		ft_putstr("List is empty\n");
		return ;
	}
	iter = *alst;
	while (iter)
	{
		print(iter->content);
		if (iter->next)
			ft_putstr(" -> ");
		iter = iter->next;
	}
	ft_putstr("\n");
}
