#include "engine.h"

void				engine_start(t_engine *engine, t_core *core)
{
	engine->error_config = &core->error_config;
	engine->render_request = true;
	opengl_start(engine);
	camera_start(engine);
	program_start(engine);
	uniform_start(engine);
	model_start(engine);
	engine->counter_rotation = 0;
	engine->block_rotation = false;
	engine->block_rotation_by_mod = false;
	engine->block_transition = false;
}

void				engine_finish(t_engine *engine)
{
	model_finish(engine);
	texture_finish(engine);
	program_finish(engine);
	opengl_finish();
}
