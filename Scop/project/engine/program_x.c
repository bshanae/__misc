#include "engine.h"

void				program_start(t_engine *engine)
{
	t_shader		shader_vertex;
	t_shader		shader_fragment;
	int				success;
	char			log[1024];

	shader_vertex = shader_create(GL_VERTEX_SHADER, SCOP_VERTEX_SHADER);
	shader_fragment = shader_create(GL_FRAGMENT_SHADER, SCOP_FRAGMENT_SHADER);
	engine->program = glCreateProgram();
	glAttachShader(engine->program, shader_vertex);
	glAttachShader(engine->program, shader_fragment);
	glLinkProgram(engine->program);
	glGetProgramiv(engine->program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(engine->program, 1024, NULL, log);
		printf("Log : \n%s\n", log);
		ft_raise_error(engine->error_config, "Can't create program");
	}
	shader_destroy(&shader_vertex);
	shader_destroy(&shader_fragment);
	glUseProgram(engine->program);
}

void				program_finish(t_engine *engine)
{
	glUseProgram(0);
	glDeleteProgram((*engine).program);
}
