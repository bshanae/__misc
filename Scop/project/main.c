#include "core.h"
#include "engine.h"
#include "parser.h"

int					main(int argc, char **argv)
{
	t_core			core;
	t_engine		engine;
	t_parser		parser;

	if (argc != 2)
		ft_raise_error(NULL, "Invalid number of arguments");
	core_start(&core);
	engine_start(&engine, &core);
	texture_start(&engine, "project/resources/Jeda.bmp");
	parser_start(&parser, &engine);
	read_model(&parser, argv[1]);
	generate_model(&parser);
	info();
	model_load(&engine);
	loop(&engine);
	engine_finish(&engine);
	parser_finish(&parser);
	core_finish(&core);
	return (0);
}