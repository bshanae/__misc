#include "parser.h"

static void				helper(t_parser *parser, int count)
{
	if (ft_str_prefix(parser->model.current_line, SCOP_MODEL_EMPTY))
		;
	else if (ft_str_prefix(parser->model.current_line, SCOP_MODEL_COMMENT))
		;
	else if (ft_str_prefix(parser->model.current_line, SCOP_MODEL_VERTEX))
		read_model_vertex(parser);
	else if (ft_str_prefix(parser->model.current_line, SCOP_MODEL_TEXTURE))
		read_model_texture(parser);
	else if (ft_str_prefix(parser->model.current_line, SCOP_MODEL_NORMAL))
		read_model_normal(parser);
	else if (ft_str_prefix(parser->model.current_line, SCOP_MODEL_FACE))
		read_model_face(parser);
	else if (ft_str_prefix(parser->model.current_line, SCOP_MODEL_LIBRARY))
		read_model_library(parser);
	else if (ft_str_prefix(parser->model.current_line, SCOP_MODEL_MATERIAL))
		read_model_material(parser);
	if (count > 1)
	{
		printf("\b\b\b\b\b\b\b\b\b\b");
		fflush(stdout);
	}
	printf("%-10.d", count);
	free(parser->model.current_line);
	parser->model.current_line = NULL;
}

void					read_model(t_parser *parser, const char *path)
{
	int					fd;
	static int			count;

	if (count)
		ft_raise_error(NULL, "Can't read more than one model");
	if (!ft_str_suffix(path, ".obj"))
		ft_raise_error(NULL, "Bad model extension");
	fd = open(path, O_RDONLY);
	ft_assert_critical(parser->error_config, fd != -1, "Bad model file");
	parser->working_directory = extract_directory(path);
	printf("\nReading model, number of lines : ");
	while (get_next_line(fd, &parser->model.current_line) > 0)
		helper(parser, ++count);
	printf("\n");
	close(fd);
}
