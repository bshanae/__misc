#include "parser.h"

char				*extract_directory(const char *begin)
{
	char			*end;
	char			*result;

	end = ft_strrchr(begin, '/');
	if (!end)
		return (ft_strdup(""));
	result = ft_strnew(++end - begin);
	ft_strncpy(result, begin, end - begin);
	return (result);
}
