cmake_minimum_required(VERSION 3.15)
project(21_scop C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

link_directories(
	/usr/local/Cellar/glew/2.1.0_1/lib
	/usr/local/Cellar/glfw/3.3/lib
	/usr/local/Cellar/freetype/2.10.1/lib
	project/libft)

link_libraries(
	"-framework OpenGL"
	GLEW
	GLFW
	ft
	freetype)

include_directories(
	/usr/local/Cellar/glew/2.1.0_1/include
	/usr/local/Cellar/glfw/3.3/include
	/usr/local/Cellar/freetype/2.10.1/include/freetype2
	~/workspace/21_libft/includes)

include_directories(
	project
	project/common
	project/core
	project/math
	project/engine
	project/parser)

set(SCOP_MAIN
	project/main.c)

set(SCOP_CORE
	project/core/core.c
	project/core/info.c)

set(SCOP_MATH
	project/math/vector/vector2.c
	project/math/vector/vector3.c
	project/math/vector/vector4.c
	project/math/matrix/empty.c
	project/math/matrix/look_at.c
	project/math/matrix/perspective.c
	project/math/matrix/product.c
	project/math/matrix/print.c
	project/math/matrix/rotate_x.c
	project/math/matrix/scale.c
	project/math/matrix/translate.c
	project/math/matrix/identity.c
	project/math/other/degrees_to_radians.c)

set(SCOP_ENGINE
	project/engine/engine.c
	project/engine/OpenGL_x.c
	project/engine/shader_x.c
	project/engine/program_x.c
	project/engine/loop.c
	project/engine/render.c
	project/engine/handle_key.c
	project/engine/handle_x.c
	project/engine/vbo_x.c
	project/engine/vao_x.c
	project/engine/mesh_x.c
	project/engine/camera_x.c
	project/engine/uniform_x.c
	project/engine/texture_x_a.c
	project/engine/texture_x_b.c
	project/engine/material_x.c
	project/engine/model_x_a.c
	project/engine/model_x_b.c
	project/engine/model_x_с.c)

set(SCOP_PARSER
	project/parser/parser.c
	project/parser/fill_x.c
	project/parser/read_model.c
	project/parser/read_model_x_a.c
	project/parser/read_model_x_b.c
	project/parser/read_material_x_a.c
	project/parser/read_material_x_b.c
	project/parser/interim_mesh_x.c
	project/parser/generate_x.c
	project/parser/extract_directory.c)

add_executable(21_scop
	${SCOP_MAIN}
	${SCOP_CORE}
	${SCOP_MATH}
	${SCOP_ENGINE}
	${SCOP_PARSER})