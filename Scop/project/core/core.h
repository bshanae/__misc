#ifndef CORE_H
# define CORE_H

# include "libft_error.h"

# include <stdio.h>

typedef struct		s_core
{
	t_error_config	error_config;
}					t_core;

void				core_start(t_core *core);
void				core_finish(t_core *core);

void				info();

#endif
