PREFIX = [Scop]
INFO = ${info ${PREFIX} : $1}

INCLUDES =										\
	../project									\
    ../project/common							\
    ../project/core								\
    ../project/math								\
    ../project/engine							\
    ../project/parser

INCLUDES_PREFIXED = ${addprefix -I,${INCLUDES}}

OBJECT_FLAGS = 									\
	`pkg-config --cflags glew`					\
	`pkg-config --cflags glfw3`					\
	`pkg-config --cflags glm`					\
	`pkg-config --cflags freetype2`				\
	-I ../project/libft/includes

EXECUTABLE_FLAGS =								\
	`pkg-config --libs glew`					\
	`pkg-config --libs glfw3`					\
	`pkg-config --libs glm`						\
	`pkg-config --libs freetype2`				\
	-L ../project/libft							\
	-l ft										\
	-framework OpenGL

SOURCES =										\
	../project/main.c							\
	../project/core/core.c						\
	../project/core/info.c						\
	../project/math/vector/vector2.c			\
	../project/math/vector/vector3.c			\
	../project/math/vector/vector4.c			\
	../project/math/matrix/empty.c				\
	../project/math/matrix/look_at.c			\
	../project/math/matrix/perspective.c		\
	../project/math/matrix/product.c			\
	../project/math/matrix/print.c				\
	../project/math/matrix/rotate_x.c			\
	../project/math/matrix/scale.c				\
	../project/math/matrix/translate.c			\
	../project/math/matrix/identity.c			\
	../project/math/other/degrees_to_radians.c	\
	../project/engine/engine.c					\
	../project/engine/OpenGL_x.c				\
	../project/engine/shader_x.c				\
	../project/engine/program_x.c				\
	../project/engine/loop.c					\
	../project/engine/render.c					\
	../project/engine/handle_key.c				\
	../project/engine/handle_x.c				\
	../project/engine/vbo_x.c					\
	../project/engine/vao_x.c					\
	../project/engine/mesh_x.c					\
	../project/engine/camera_x.c				\
	../project/engine/uniform_x.c				\
	../project/engine/texture_x_a.c				\
	../project/engine/texture_x_b.c				\
	../project/engine/material_x.c				\
	../project/engine/model_x_a.c				\
	../project/engine/model_x_b.c				\
	../project/engine/model_x_с.c				\
	../project/parser/parser.c					\
	../project/parser/fill_x.c					\
	../project/parser/read_model.c				\
	../project/parser/read_model_x_a.c			\
	../project/parser/read_model_x_b.c			\
	../project/parser/read_material_x_a.c		\
	../project/parser/read_material_x_b.c		\
	../project/parser/interim_mesh_x.c			\
	../project/parser/generate_x.c				\
	../project/parser/extract_directory.c

VPATH = 										\
	../project									\
	../project/core								\
	../project/math/vector						\
	../project/math/matrix						\
	../project/math/other						\
	../project/engine							\
	../project/parser

OBJECTS_FOLDER = objects

OBJECTS_NAMES = ${notdir ${SOURCES}}
OBJECTS_IN_FOLDER = ${addprefix ${OBJECTS_FOLDER}/, ${OBJECTS_NAMES}}
OBJECTS = ${addsuffix .o,${OBJECTS_IN_FOLDER}}

EXECUTABLE = ../scop

LIBFT_FOLDER = ../project/libft
LIBFT_TARGET = ../project/libft/libft.a

all : ${EXECUTABLE}

${EXECUTABLE} : ${LIBFT_TARGET} ${OBJECTS_FOLDER} ${OBJECTS}
	${call INFO,Linking executuable ${EXECUTABLE}}
	@gcc ${INCLUDES_PREFIXED} ${EXECUTABLE_FLAGS} ${OBJECTS} -o ${EXECUTABLE}

${LIBFT_TARGET} :
	${call INFO,Compiling Libft}
	@make -C ${LIBFT_FOLDER}

${OBJECTS_FOLDER} :
	${call INFO,Creating folder for objects}
	@mkdir ${OBJECTS_FOLDER}

${OBJECTS_FOLDER}/%.c.o : %.c
	${call INFO,Compiling source file $<}
	@gcc ${INCLUDES_PREFIXED} ${OBJECT_FLAGS} -c $< -o $@

clean :
	${call INFO,Deleting objects' folder}
	@rm -rf ${OBJECTS_FOLDER}

fclean : clean
	${call INFO,Deleting executable}
	@rm -rf ${EXECUTABLE}
	${call INFO,Cleaning libft}
	@make fclean -C ${LIBFT_FOLDER}

re : fclean all

.PHONY : all clean fclean re

