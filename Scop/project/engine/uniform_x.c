#include "engine.h"

static void			helper_a(t_engine *engine)
{
	engine->uniform.mod_from = glGetUniformLocation(
		engine->program, "uniform_mod_from");
	engine->uniform.mod_to = glGetUniformLocation(
		engine->program, "uniform_mod_to");
	engine->uniform.mod_transition = glGetUniformLocation(
		engine->program, "uniform_mod_transition");
	engine->uniform.projection = glGetUniformLocation(
		engine->program, "uniform_projection");
	engine->uniform.view = glGetUniformLocation(
		engine->program, "uniform_view");
	engine->uniform.transformation = glGetUniformLocation(
		engine->program, "uniform_transformation");
	engine->uniform.camera_position = glGetUniformLocation(
		engine->program, "uniform_camera_position");
}

static void			helper_b(t_engine *engine)
{
	engine->uniform.material_use_texture = glGetUniformLocation(
		engine->program, "uniform_material.use_texture");
	engine->uniform.material_texture = glGetUniformLocation(
		engine->program, "uniform_material.texture");
	engine->uniform.material_ambient = glGetUniformLocation(
		engine->program, "uniform_material.ambient");
	engine->uniform.material_diffuse = glGetUniformLocation(
		engine->program, "uniform_material.diffuse");
	engine->uniform.material_specular = glGetUniformLocation(
		engine->program, "uniform_material.specular");
	engine->uniform.texture = glGetUniformLocation(
		engine->program, "uniform_texture");
	engine->uniform.material_specular_exponent = glGetUniformLocation(
		engine->program, "uniform_material.specular_exponent");
	engine->uniform.material_alpha = glGetUniformLocation(
		engine->program, "uniform_material.alpha");
	engine->uniform.model_min = glGetUniformLocation(
		engine->program, "uniform_model_min");
	engine->uniform.model_max = glGetUniformLocation(
		engine->program, "uniform_model_max");
}

void				uniform_start(t_engine *engine)
{
	helper_a(engine);
	helper_b(engine);
}

void				uniform_update_common(t_engine *engine)
{
	glUniformMatrix4fv(engine->uniform.projection,
		1, GL_FALSE, &engine->camera.matrix_projection.data[0][0]);
	glUniformMatrix4fv(engine->uniform.view,
		1, GL_FALSE, &engine->camera.matrix_view.data[0][0]);
	glUniformMatrix4fv(engine->uniform.transformation,
		1, GL_FALSE, &engine->model.transformation.data[0][0]);
	glUniform3fv(engine->uniform.camera_position,
		1, &engine->camera.position.x);
	glUniform1i(engine->uniform.mod_from, engine->model.mod_from);
	glUniform1i(engine->uniform.mod_to, engine->model.mod_to);
	glUniform1f(engine->uniform.mod_transition, engine->model.mod_transition);
	glUniform3fv(engine->uniform.model_min, 1, &engine->model.min.x);
	glUniform3fv(engine->uniform.model_max, 1, &engine->model.max.x);
}

void				uniform_update_material(
					t_engine *engine,
					t_material *material)
{
	glActiveTexture(GL_TEXTURE1);
	texture_bind(&material->texture);
	glUniform1i(engine->uniform.material_use_texture, material->texture != 0);
	glUniform3fv(engine->uniform.material_ambient, 1, &material->ambient.x);
	glUniform3fv(engine->uniform.material_diffuse, 1, &material->diffuse.x);
	glUniform3fv(engine->uniform.material_specular, 1, &material->specular.x);
	glUniform1f(engine->uniform.material_specular_exponent,
		material->specular_exponent);
	glUniform1f(engine->uniform.material_alpha, material->alpha);
}
