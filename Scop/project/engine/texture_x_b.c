#include "engine.h"

void				texture_start(t_engine *engine, const char *path)
{
	glUniform1i(engine->uniform.texture, 0);
	glUniform1i(engine->uniform.material_texture, 1);
	engine->texture = texture_create(path);
}

void				texture_finish(t_engine *engine)
{
	texture_destroy(&engine->texture);
}
