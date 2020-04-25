#include "engine.h"

#define M1			glGetUniformLocation
#define M2			engine->program

void				uniform_start(t_engine *engine)
{
	engine->uniform.mod_from = M1(M2, "uniform_mod_from");
	engine->uniform.mod_to = M1(M2, "uniform_mod_to");
	engine->uniform.mod_transition = M1(M2, "uniform_mod_transition");
	engine->uniform.projection = M1(M2, "uniform_projection");
	engine->uniform.view = M1(M2, "uniform_view");
	engine->uniform.transformation = M1(M2, "uniform_transformation");
	engine->uniform.camera_position = M1(M2, "uniform_camera_position");
	engine->uniform.texture = M1(M2, "uniform_texture");
	engine->uniform.material_use_texture = M1(M2, "uniform_material.use_texture");
	engine->uniform.material_texture = M1(M2, "uniform_material.texture");
	engine->uniform.material_ambient = M1(M2, "uniform_material.ambient");
	engine->uniform.material_diffuse = M1(M2, "uniform_material.diffuse");
	engine->uniform.material_specular = M1(M2, "uniform_material.specular");
	engine->uniform.material_specular_exponent = M1(M2, "uniform_material.specular_exponent");
	engine->uniform.material_alpha = M1(M2, "uniform_material.alpha");
}

void 				uniform_update_common(t_engine *engine)
{
	glUniform1i(engine->uniform.mod_from, engine->model.mod_from);
	glUniform1i(engine->uniform.mod_to, engine->model.mod_to);
	glUniform1f(engine->uniform.mod_transition, engine->model.mod_transition);
	glUniformMatrix4fv(engine->uniform.projection, 1, GL_FALSE, &engine->camera.matrix_projection.data[0][0]);
	glUniformMatrix4fv(engine->uniform.view, 1, GL_FALSE, &engine->camera.matrix_view.data[0][0]);
	glUniformMatrix4fv(engine->uniform.transformation, 1, GL_FALSE, &engine->model.transformation.data[0][0]);
	glUniform3fv(engine->uniform.camera_position, 1, &engine->camera.position.x);
}

void				uniform_update_material(t_engine *engine, t_material *material)
{
	glActiveTexture(GL_TEXTURE1);
	texture_bind(&material->texture);
	glUniform1i(engine->uniform.material_use_texture, material->texture != 0);
	glUniform3fv(engine->uniform.material_ambient, 1, &material->ambient.x);
	glUniform3fv(engine->uniform.material_diffuse, 1, &material->diffuse.x);
	glUniform3fv(engine->uniform.material_specular, 1, &material->specular.x);
	glUniform1f(engine->uniform.material_specular_exponent, material->specular_exponent);
	glUniform1f(engine->uniform.material_alpha, material->alpha);
}