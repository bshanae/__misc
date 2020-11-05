#include <stdlib.h>
#include <stdio.h>

#define IS_SPACE(c)	(c == ' ' || c == '\n' || c == '\t')
#define IS_BEGIN(s, i) ((!i && !IS_SPACE(s[i])) || (i && IS_SPACE(s[i - 1]) && !IS_SPACE(s[i])))
#define IS_END(s, i) (!s[i] || (i && !IS_SPACE(s[i - 1]) && IS_SPACE(s[i])))

int					count(char *s)
{
	int				begin;
	int				end;
	int				count;
	int				i;
	
	begin = 0;
	end = 0;
	count = 0;
	i = 0;
	do
	{
		if (IS_BEGIN(s, i))
			begin = 1;
		else if (IS_END(s, i))
			end = 1;
		if (begin && end)
		{
			count++;
			begin = 0;
			end = 0;
		}
		i++;
	} while (s[i]);
	return (count);
}

void				find(const char *s, int *begin , int *end)
{
	while (s[*begin] && !IS_BEGIN(s, *begin))
	{
		//printf("\ns = [%c] : %d\n", s[*begin], !IS_BEGIN(s, *begin));
		(*begin)++;
	}
	*end = *begin;
	
	printf("\ns = [%c] : %d\n", s[*begin], IS_BEGIN(s, *begin));
	
	while (!IS_END(s, *end))
		(*end)++;
	printf("\ne = [%c] : %d\n", s[*end], IS_END(s, *end));
}

void				allocate(char **target, const char *begin , const char *end)
{
	int				i;
	
	i = 0;
	while (begin + i <= end)
		i++;
	printf("\nword length = %d\n", i);
	*target = (char *)malloc(i);
	i = 0;
	while (begin + i < end)
	{
		(*target)[i] = begin[i];
		printf("coping %c\n", begin[i]);
		i++;
	}
	(*target)[i] = '\0';
}
	
char				**ft_split(char *s)
{
	char			**ss;
	int				ss_i;
	int				ss_max;
	int				begin;
	int				end;
	
	ss_max = count(s) + 1;
	ss = (char **)malloc(sizeof(char *) * ss_max);
	ss_i = 0;
	begin = 0;
	end = 0;
	printf("str = {%s}\n", s);
	do
	{
		find(s, &begin, &end);
		
		printf("{");
		for (int i = 0; begin + i != end; i++)
			printf("%c", s[begin + i]);
		printf("}\n");
		
		allocate(ss + ss_i++, s + begin, s + end);
		begin = end;
	} while (s[begin]);
	ss[ss_i] = NULL;
	return (ss);
}
	

int					main(int argc, char **argv)
{
	char			**ss;
	
	if (argc != 2)
		return (1);
	ss = ft_split(argv[1]);
	for (int i = 0; ss[i]; i++)
		printf("%d : {%s}\n", i, ss[i]);
}
