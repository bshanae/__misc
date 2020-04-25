/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:48:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:29:06 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

static void				list_add(t_list_item **item, VOID_REF data, size_t size)
{
	t_list_item			*iter;

	if (!*item)
	{
		*item = list_item_new(data, size);
		return ;
	}
	iter = *item;
	while (iter->next)
		iter = iter->next;
	iter->next = list_item_new(data, size);
}

static	t_str			*search_fd(t_list_item **begin, const int fd)
{
	t_list_item			*ptr;
	t_str				elem;

	ptr = *begin;
	while (ptr != NULL)
	{
		if (((t_str *)(ptr->data))->fd == fd)
			return ((t_str *)(ptr->data));
		ptr = ptr->next;
	}
	elem.fd = fd;
	elem.s = ft_strnew(0);
	list_add(begin, &elem, sizeof(t_str));
	return ((t_str *)((*begin)->data));
}

static int				rec_line(t_str *elem, char **line)
{
	char				*t;
	char				*tmp;

	if (*(elem->s) == '\0')
		return (0);
	if ((t = ft_strchr(elem->s, '\n')) != NULL)
	{
		*t = '\0';
		if (!(*line = ft_strdup(elem->s)))
			return (-1);
		if (!(tmp = ft_strdup(t + 1)))
			return (-1);
		free(elem->s);
		if (!(elem->s = ft_strdup(tmp)))
			return (-1);
		free(tmp);
		return (1);
	}
	if (!(*line = ft_strdup(elem->s)))
		return (-1);
	free(elem->s);
	elem->s = ft_strnew(0);
	if (elem->s == NULL)
		return (-1);
	return (1);
}

int						gnl(const int fd, char **line)
{
	static t_list_item	*begin;
	t_str				*elem;
	size_t				ret;
	char				buf[BUFF_SIZE + 1];
	char				*tmp;

	if (!line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	elem = search_fd(&begin, fd);
	if (!(elem->s))
		return (-1);
	while (ft_strchr(elem->s, '\n') == NULL && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = elem->s;
		if (!(elem->s = ft_strjoin(elem->s, buf)))
			return (-1);
		free(tmp);
	}
	return (rec_line(elem, line));
}
