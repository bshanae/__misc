/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:31:03 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/06 13:31:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				list_iter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst && f)
	{
		f(lst);
		lst = lst->next;
	}
}