/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:30:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/03 17:36:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*(str))
	{
		ft_putchar(*(str++));
	}
}

void	swap_str(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	sort_matr(int size, char **arr)
{
	int limit;
	int i;

	limit = size - 1;
	while (limit != 1)
	{
		i = 0;
		while (i < limit)
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
				swap_str(arr + i, arr + i + 1);
			i++;
		}
		limit--;
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		return (1);
	sort_matr(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		ft_putchar('\n');
	}
	return (0);
}
