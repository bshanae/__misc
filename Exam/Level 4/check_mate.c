#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void			ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*(dest++) = *(src++);
}

void			make_board(char ***board, int ac, char **av)
{
	int			board_i;
	int			arg_i;

	*board = (char **)malloc(sizeof(char *) * (ac - 1));
	board_i = 0;
	arg_i = 1;
	while (board_i < ac - 1)
	{
		(*board)[board_i] = (char *)malloc(ac - 1);
		ft_strcpy((*board)[board_i], av[arg_i]);
		board_i++;
		arg_i++;
	}
}

void			delete_board(char ***board, const int *length)
{
	int			i;
	
	i = 0;
	while (i < *length)
		free((*board)[i++]);
	free(*board);
	*board = NULL;
}

int				check_king
				(const char **board, const int *length,
				const int i, const int j)
{
	if (i < 0 || i >= *length)
		return (-1);
	if (j < 0 || j >= *length)
		return (-1);
	return (board[i][j] == 'K');
}

int				check_piece
				(const char **board, const int *length,
				const int *i, const int *j)
{
	int			ii;
	int			jj;
	int			check;

	switch (board[*i][*j])
	{
		case 'K' :
			return (0);
		case 'P' :
		{
			if (check_king(board, length, *i - 1, *j - 1) == 1)
				return (1);
			if (check_king(board, length, *i - 1, *j + 1) == 1)
				return (1);
			return (0);
		}
		case 'B' :
		{
			for (ii = *i, jj = *j; (check = check_king(board, length, ii, jj)) != -1; ii++, jj++)
				if (check == 1)
					return (1);
			for (ii = *i, jj = *j; (check = check_king(board, length, ii, jj)) != -1; ii++, jj--)
				if (check == 1)
					return (1);
			for (ii = *i, jj = *j; (check = check_king(board, length, ii, jj)) != -1; ii--, jj++)
				if (check == 1)
					return (1);
			for (ii = *i, jj = *j; (check = check_king(board, length, ii, jj)) != -1; ii--, jj--)
				if (check == 1)
					return (1);
			return (0);
		}
		case 'R' :
		{
			for (ii = *i; (check = check_king(board, length, ii, *j)) != -1; ii--)
				if (check == 1)
					return (1);
			for (ii = *i; (check = check_king(board, length, ii, *j)) != -1; ii++)
				if (check == 1)
					return (1);
			for (jj = *j; (check = check_king(board, length, *i, jj)) != -1; jj--)
				if (check == 1)
					return (1);
			for (jj = *j; (check = check_king(board, length, *i, jj)) != -1; jj++)
				if (check == 1)
					return (1);
			return (0);
		}
		case 'Q' :
		{
			if (check_king(board, length, *i + 1, *j + 1) == 1)
				return (1);
			if (check_king(board, length, *i + 1, *j + 0) == 1)
				return (1);
			if (check_king(board, length, *i + 0, *j + 1) == 1)
				return (1);
			if (check_king(board, length, *i + 0, *j + 0) == 1)
				return (1);
			for (ii = *i, jj = *j; (check = check_king(board, length, ii, jj)) != -1; ii++, jj++)
				if (check == 1)
					return (1);
			for (ii = *i, jj = *j; (check = check_king(board, length, ii, jj)) != -1; ii++, jj--)
				if (check == 1)
					return (1);
			for (ii = *i, jj = *j; (check = check_king(board, length, ii, jj)) != -1; ii--, jj++)
				if (check == 1)
					return (1);
			for (ii = *i, jj = *j; (check = check_king(board, length, ii, jj)) != -1; ii--, jj--)
				if (check == 1)
					return (1);
			return (0);

		}
		default :
			return (0);
	}
	return (0);
}

void			check_mate(int ac, char **av)
{
	char		**board;
	int			length;
	int			result;

	make_board(&board, ac, av);
	length = ac - 1;

	result = 0;
	for (int i = 0; i < length && !result; i++)
		for (int j = 0; j < length && !result; j++)
			if (check_piece((const char **)board, &length, &i, &j))
				result = 1;

	if (result)
		write(1, "Success", 7);
	else
		write(1, "Fail", 4);


	delete_board(&board, &length);	
}

int				main(int argc, char **argv)
{
	if (argc > 1)
		check_mate(argc, argv);
	write(1, "\n", 1);
}
