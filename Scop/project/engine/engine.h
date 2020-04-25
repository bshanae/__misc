#ifndef ENGINE_H
# define ENGINE_H

# include "scop_OpenGL.h"
# include "scop_constant.h"
# include "scop_settings.h"
# include "core.h"
# include "scop_math.h"

# include "libft_standart.h"
# include "libft_vector.h"
# include <stdio.h>
# include <float.h>
# include <time.h>

typedef GLuint		t_vbo;

t_vbo				vbo_create();
void 				vbo_destroy(t_vbo *vbo);
void 				vbo_bind(const t_vbo *vbo);
void 				vbo_buffer(const t_vector *vector);

typedef struct		s_vao
{
	GLuint			object;
	t_vbo			attribute_data[SCOP_VAO_ATTRIBUTE_NUMBER];
	int 			attribute_next;
}					t_vao;

t_vao 				vao_create();
void 				vao_destroy(t_vao *vao);
void 				vao_bind(const t_vao *vao);
void 				vao_attribute(
					t_vao *vao, const t_vector *vector, int element_size);

typedef GLuint		t_texture;

t_texture			texture_create(const char *path);
void				texture_destroy(t_texture *texture);
void 				texture_bind(t_texture *texture);

typedef struct		s_material
{
	char			*name;
	t_texture		texture;
	t_vector3		ambient;
	t_vector3		diffuse;
	t_vector3		specular;
	float			specular_exponent;
	float 			alpha;
}					t_material;

t_material			material_create(const char *name);
void 				material_destroy(t_material *material);


typedef struct		s_mesh
{
	t_vector 		*vector_vertex;
	t_vector 		*vector_texture;
	t_vector 		*vector_normal;
	t_vector 		*vector_color;
	t_material		*material;
	int 			vertex_number;
	t_vao 			vao;
}					t_mesh;

t_mesh				mesh_create();
void				mesh_destroy(t_mesh *mesh);
void				mesh_load(t_mesh *mesh);
void 				mesh_draw(const t_mesh *mesh);

typedef struct		s_model
{
	t_vector		*meshes;
	t_vector3		position;
	float			scale;
	t_matrix		rotation;
	t_matrix		transformation;
	t_vector3 		min;
	t_vector3 		max;
	t_vector3 		size;
	t_vector3 		center;
	int				mod_from;
	int				mod_to;
	float			mod_transition;
}					t_model;

typedef GLuint		t_shader;

t_shader 			shader_create(GLuint type, const char *path);
void				shader_destroy(t_shader *shader);

typedef GLuint		t_program;

typedef GLuint		t_uniform;

typedef struct		s_uniform_set
{
	t_uniform		mod_from;
	t_uniform		mod_to;
	t_uniform		mod_transition;
	t_uniform		projection;
	t_uniform		view;
	t_uniform		transformation;
	t_uniform		camera_position;
	t_uniform		texture;
	t_uniform		material_use_texture;
	t_uniform		material_texture;
	t_uniform		material_ambient;
	t_uniform		material_diffuse;
	t_uniform		material_specular;
	t_uniform		material_specular_exponent;
	t_uniform		material_alpha;
}					t_uniform_set;

typedef struct		s_camera
{
	t_vector3		position;
	t_vector3		direction;
	t_matrix		matrix_projection;
	t_matrix		matrix_view;
	t_vector3		angles;
	t_vector3		axis_x;
	t_vector3		axis_y;
	t_vector3		axis_z;
}					t_camera;

typedef struct		s_engine
{
	t_error_config	*error_config;
	GLFWwindow		*window;
	int				window_width;
	int				window_height;
	t_bool			render_request;
	t_program		program;
	t_uniform_set	uniform;
	t_camera		camera;
	t_model			model;
	t_texture		texture;
	int				counter_rotation;
	int				counter_transition;
	t_bool			block_rotation;
	t_bool			block_rotation_by_mod;
	t_bool			block_transition;
}					t_engine;

void				engine_start(t_engine *engine, t_core *core);
void				engine_finish(t_engine *engine);

void				OpenGL_start(t_engine *engine);
void				OpenGL_finish();

void 				handle_key(GLFWwindow* window, int key, int scancode, int action, int mode);

t_bool				handle_common(t_engine *engine, int key);
t_bool				handle_mod(t_engine *engine, int key);
t_bool				handle_camera(t_engine *engine, int key);
t_bool				handle_model_a(t_engine *engine, int key);
t_bool				handle_model_b(t_engine *engine, int key);

void				program_start(t_engine *engine);
void				program_finish(t_engine *engine);

void				camera_start(t_engine *engine);
void				camera_move(t_engine *engine, t_axis axis, t_sign sign, t_vector3 *target);
void				camera_rotate(t_engine *engine, t_axis axis, t_sign sign, t_matrix *target);
void				camera_update(t_engine *engine);

void 				uniform_start(t_engine *engine);
void		 		uniform_update_common(t_engine *engine);
void				uniform_update_material(t_engine *engine, t_material *material);

void				model_start(t_engine *engine);
void 				model_finish(t_engine *engine);
void 				model_load(t_engine *engine);
void				model_update(t_engine *engine, t_matrix *rotation);
void				model_analyze(t_engine *engine);

void				model_center(t_engine *engine);
void				model_random_color(t_engine *engine);
void				model_auto_normal(t_engine *engine);
void				model_auto_texture(t_engine *engine);
void				model_auto_scale(t_engine *engine);

void 				texture_start(t_engine *engine, const char *path);
void 				texture_finish(t_engine *engine);

void				loop(t_engine *engine);
void				render(t_engine *engine);

#endif
