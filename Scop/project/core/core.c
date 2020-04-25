#include "core.h"

void				core_start(t_core *core)
{
	core->error_config = error_config_create();
	ft_strcpy(core->error_config.warning_prefix, "SCOP WARNING");
	ft_strcpy(core->error_config.error_prefix, "SCOP ERROR");
	printf("Scop start\n");
}

void 				core_finish(t_core *core)
{
	printf("\nScop finish\n");
}
