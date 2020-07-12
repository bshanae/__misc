/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:41:06 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:24:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/*
********************************************************************************
**					MEMORY
********************************************************************************
*/

void				*ft_memset(void *str, int c, size_t n);

void				*ft_memcpy(void *str1, const void *str2, size_t n);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memchr(const void *str, int value, size_t n);

int					ft_memcmp(const void *str1, const void *str2, size_t n);

void				ft_bzero(void *str, size_t n);

void				*ft_realloc(void **m, size_t old_size, size_t new_size);

/*
********************************************************************************
**					NUMERIC
********************************************************************************
*/

int					ft_max(int a, int b);

int					ft_min(int a, int b);

int					ft_abs(int a);

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

/*
********************************************************************************
**					STRING
********************************************************************************
*/

int					ft_atoi(const char *str);

int					ft_atoi_base(const char *str, int base);

char				*ft_itoa(int n);

size_t				ft_strlen(const char *str);

char				*ft_strdup (const char *src);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dest, const char *src, size_t n);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strncat(char *dest, const char *src, size_t n);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

char				*ft_strchr(const char *str, int value);

char				*ft_strrchr(const char *str, int value);

char				*ft_strstr(const char *str, const char *to_find);

char				*ft_strnstr(const char *str, const char *to_find, size_t n);

int					ft_strcmp(const char *str1, const char *str2);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

/*
********************************************************************************
**					PUT
********************************************************************************
*/

void				ft_putchar(char c);

void				ft_putstr(char const *s);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

/*
********************************************************************************
**					LIST
********************************************************************************
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*list_alloc(void const *content, size_t content_size);

void				list_free(t_list **alst, void (*del)(void *));

void				list_clean(t_list **alst, void (*del)(void *));

t_list				*list_push_front(t_list **alst, t_list *new);

t_list				*list_push_back(t_list **alst, t_list *new);

t_list				*list_emplace_front
	(t_list **alst, void const *content, size_t content_size);

t_list				*list_emplace_back
	(t_list **alst, void const *content, size_t content_size);

t_list				*list_delete
	(t_list **alst, const void *content,
	int (*cmp)(const void *, const void *), void (*del)(void *));

t_list				*list_find
	(t_list **alst, const void *content,
	int (*cmp)(const void *, const void *));

void				list_iter(t_list *lst, void (*f)(t_list *elem));

void				list_print
(t_list **alst, void (*print)(const void *content));

t_list				*list_last(t_list **lst);

int					list_len(t_list **lst);

/*
********************************************************************************
**					BTREE
********************************************************************************
*/

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*content;
}					t_btree;

t_btree				*btree_alloc(const void *content, size_t content_size);

void				btree_clean(t_btree **root, void (*del)(void *));

t_btree				*btree_insert
	(t_btree **root, const void *content, size_t content_size,
	int (*cmpf)(const void *, const void *));

t_btree				*btree_delete
	(t_btree **root, const void *content,
	int (*cmpf)(const void *, const void *), void (*del)(void *));

t_btree				*btree_find
					(t_btree **root, const void *content,
					int (*cmpf)(const void *, const void *));

int					btree_depth(t_btree **root);

int					btree_verify
	(t_btree **root, int (*cmpf)(const void *, const void *));

void				btree_prefix(t_btree *root, void (*f)(void *));

void				btree_infix(t_btree *root, void (*f)(void *));

void				btree_suffix(t_btree *root, void (*f)(void *));

/*
********************************************************************************
**					GET NEXT LINE
********************************************************************************
*/

# define SB_UNEXPECTED -4
# define SB_ERR_ALLOC -3
# define SB_ERR_FILE -2
# define SB_ERR_LAUNCH -1

# define SB_OUT_EOF 0
# define SB_OUT_MID 1

# define SB_IN_EOF 10
# define SB_IN_MID 11

# define SB_DEFAULT 20

# define SB_INIT 20
# define SB_MULT 3

typedef struct		s_sb
{
	int				fd;
	int				size;
	char			*begin;
	char			*end;
	char			*out_begin;
	char			*out_end;
	char			*in;
	char			**target;
}					t_sb;

t_sb				*sb_alloc(int fd, int size, char **target);

void				sb_free(void *m);

int					sb_realloc(t_sb *sb, int new_size);

void				sb_reset(t_sb *sb);

int					sb_in(t_sb *sb, int bs);

int					sb_out(t_sb *sb);

void				sb_set_target(t_sb *sb, char **target);

int					sb_fd_cmp(const void *m1, const void *m2);

# define BUFF_SIZE 20

int					get_next_line(int fd, char **line);

#endif
