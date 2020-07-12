#						FUNCTIONS

define INFO
${info ${PREFIX} : $1}
endef

#						VARIABLES

COMMA = ,

OBJECT_FOLDER = .object
DEPEND_FOLDER = .depend

COMPILER = gcc
PREFIX = scop
EXECUTABLE = scop

INCLUDE = -I ../project/libft/includes -I ../project -I ../project/common -I ../project/core -I ../project/math -I ../project/engine -I ../project/parser
OBJECT = ${OBJECT_FOLDER}/main.c.o ${OBJECT_FOLDER}/core.c.o ${OBJECT_FOLDER}/info.c.o ${OBJECT_FOLDER}/add.c.o ${OBJECT_FOLDER}/array.c.o ${OBJECT_FOLDER}/cross.c.o ${OBJECT_FOLDER}/div.c.o ${OBJECT_FOLDER}/dot.c.o ${OBJECT_FOLDER}/empty.c.o ${OBJECT_FOLDER}/length_x.c.o ${OBJECT_FOLDER}/max.c.o ${OBJECT_FOLDER}/min.c.o ${OBJECT_FOLDER}/mul.c.o ${OBJECT_FOLDER}/normalize.c.o ${OBJECT_FOLDER}/pack.c.o ${OBJECT_FOLDER}/print.c.o ${OBJECT_FOLDER}/rotate_x.c.o ${OBJECT_FOLDER}/sub.c.o ${OBJECT_FOLDER}/empty_1.c.o ${OBJECT_FOLDER}/look_at.c.o ${OBJECT_FOLDER}/perspective.c.o ${OBJECT_FOLDER}/product.c.o ${OBJECT_FOLDER}/print_1.c.o ${OBJECT_FOLDER}/rotate_x_1.c.o ${OBJECT_FOLDER}/scale.c.o ${OBJECT_FOLDER}/translate.c.o ${OBJECT_FOLDER}/identity.c.o ${OBJECT_FOLDER}/degrees_to_radians.c.o ${OBJECT_FOLDER}/clamp.c.o ${OBJECT_FOLDER}/engine.c.o ${OBJECT_FOLDER}/opengl_x.c.o ${OBJECT_FOLDER}/shader_x.c.o ${OBJECT_FOLDER}/program_x.c.o ${OBJECT_FOLDER}/loop.c.o ${OBJECT_FOLDER}/render.c.o ${OBJECT_FOLDER}/handle_key.c.o ${OBJECT_FOLDER}/handle_x.c.o ${OBJECT_FOLDER}/vbo_x.c.o ${OBJECT_FOLDER}/vao_x.c.o ${OBJECT_FOLDER}/mesh_x.c.o ${OBJECT_FOLDER}/camera_x.c.o ${OBJECT_FOLDER}/uniform_x.c.o ${OBJECT_FOLDER}/texture_x_a.c.o ${OBJECT_FOLDER}/texture_x_b.c.o ${OBJECT_FOLDER}/material_x.c.o ${OBJECT_FOLDER}/model_x_a.c.o ${OBJECT_FOLDER}/model_x_b.c.o ${OBJECT_FOLDER}/model_x_c.c.o ${OBJECT_FOLDER}/parser.c.o ${OBJECT_FOLDER}/fill_x.c.o ${OBJECT_FOLDER}/read_model.c.o ${OBJECT_FOLDER}/read_model_x_a.c.o ${OBJECT_FOLDER}/read_model_x_b.c.o ${OBJECT_FOLDER}/read_material_x_a.c.o ${OBJECT_FOLDER}/read_material_x_b.c.o ${OBJECT_FOLDER}/interim_mesh_x.c.o ${OBJECT_FOLDER}/generate_x.c.o ${OBJECT_FOLDER}/extract_directory.c.o
DEPEND = ${DEPEND_FOLDER}/main.c.d ${DEPEND_FOLDER}/core.c.d ${DEPEND_FOLDER}/info.c.d ${DEPEND_FOLDER}/add.c.d ${DEPEND_FOLDER}/array.c.d ${DEPEND_FOLDER}/cross.c.d ${DEPEND_FOLDER}/div.c.d ${DEPEND_FOLDER}/dot.c.d ${DEPEND_FOLDER}/empty.c.d ${DEPEND_FOLDER}/length_x.c.d ${DEPEND_FOLDER}/max.c.d ${DEPEND_FOLDER}/min.c.d ${DEPEND_FOLDER}/mul.c.d ${DEPEND_FOLDER}/normalize.c.d ${DEPEND_FOLDER}/pack.c.d ${DEPEND_FOLDER}/print.c.d ${DEPEND_FOLDER}/rotate_x.c.d ${DEPEND_FOLDER}/sub.c.d ${DEPEND_FOLDER}/empty_1.c.d ${DEPEND_FOLDER}/look_at.c.d ${DEPEND_FOLDER}/perspective.c.d ${DEPEND_FOLDER}/product.c.d ${DEPEND_FOLDER}/print_1.c.d ${DEPEND_FOLDER}/rotate_x_1.c.d ${DEPEND_FOLDER}/scale.c.d ${DEPEND_FOLDER}/translate.c.d ${DEPEND_FOLDER}/identity.c.d ${DEPEND_FOLDER}/degrees_to_radians.c.d ${DEPEND_FOLDER}/clamp.c.d ${DEPEND_FOLDER}/engine.c.d ${DEPEND_FOLDER}/opengl_x.c.d ${DEPEND_FOLDER}/shader_x.c.d ${DEPEND_FOLDER}/program_x.c.d ${DEPEND_FOLDER}/loop.c.d ${DEPEND_FOLDER}/render.c.d ${DEPEND_FOLDER}/handle_key.c.d ${DEPEND_FOLDER}/handle_x.c.d ${DEPEND_FOLDER}/vbo_x.c.d ${DEPEND_FOLDER}/vao_x.c.d ${DEPEND_FOLDER}/mesh_x.c.d ${DEPEND_FOLDER}/camera_x.c.d ${DEPEND_FOLDER}/uniform_x.c.d ${DEPEND_FOLDER}/texture_x_a.c.d ${DEPEND_FOLDER}/texture_x_b.c.d ${DEPEND_FOLDER}/material_x.c.d ${DEPEND_FOLDER}/model_x_a.c.d ${DEPEND_FOLDER}/model_x_b.c.d ${DEPEND_FOLDER}/model_x_c.c.d ${DEPEND_FOLDER}/parser.c.d ${DEPEND_FOLDER}/fill_x.c.d ${DEPEND_FOLDER}/read_model.c.d ${DEPEND_FOLDER}/read_model_x_a.c.d ${DEPEND_FOLDER}/read_model_x_b.c.d ${DEPEND_FOLDER}/read_material_x_a.c.d ${DEPEND_FOLDER}/read_material_x_b.c.d ${DEPEND_FOLDER}/interim_mesh_x.c.d ${DEPEND_FOLDER}/generate_x.c.d ${DEPEND_FOLDER}/extract_directory.c.d
LINK_DIRECTORY = -L ../project/libft
LINK_LIBRARY = -l glfw -l glew -l ft -framework OpenGL

FLAG_OBJECT = `pkg-config --cflags glew` `pkg-config --cflags glfw3`
FLAG_EXECUTABLE = `pkg-config --libs glew` `pkg-config --libs glfw3`
FLAG_COMMON = 

#						BASIC RULES	

all : ${EXECUTABLE}

${EXECUTABLE} : ${OBJECT}
	${call INFO,Linking in executable ${EXECUTABLE}}
	@${COMPILER} ${FLAG_EXECUTABLE} ${FLAG_COMMON} ${LINK_DIRECTORY} ${LINK_LIBRARY} ${OBJECT} -o ${EXECUTABLE}

clean :
	${call INFO,Deleting objects' folder}
	@rm -rf ${OBJECT_FOLDER}
	${call INFO,Deleting dependencies' folder}
	@rm -rf ${DEPEND_FOLDER}

fclean : clean
	${call INFO,Deleting executable}
	@rm -rf ${EXECUTABLE}

re : fclean ${EXECUTABLE}

info :
	@echo "Objects :"
	@echo ${OBJECT}
	@echo "Depends :"
	@echo ${DEPEND}

.PHONY : clean fclean re info

#						OBJECTS
	
${OBJECT_FOLDER} :
	${call INFO,Creating objects' folder}
	@mkdir ${OBJECT_FOLDER}

${OBJECT_FOLDER}/main.c.o : ${DEPEND_FOLDER}/main.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,1%${COMMA} compiling object ../project/main.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/main.c.o -MF ${DEPEND_FOLDER}/main.c.d -c ../project/main.c -o ${OBJECT_FOLDER}/main.c.o

${OBJECT_FOLDER}/core.c.o : ${DEPEND_FOLDER}/core.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,3%${COMMA} compiling object ../project/core/core.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/core.c.o -MF ${DEPEND_FOLDER}/core.c.d -c ../project/core/core.c -o ${OBJECT_FOLDER}/core.c.o

${OBJECT_FOLDER}/info.c.o : ${DEPEND_FOLDER}/info.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,5%${COMMA} compiling object ../project/core/info.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/info.c.o -MF ${DEPEND_FOLDER}/info.c.d -c ../project/core/info.c -o ${OBJECT_FOLDER}/info.c.o

${OBJECT_FOLDER}/add.c.o : ${DEPEND_FOLDER}/add.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,6%${COMMA} compiling object ../project/math/vector/add.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/add.c.o -MF ${DEPEND_FOLDER}/add.c.d -c ../project/math/vector/add.c -o ${OBJECT_FOLDER}/add.c.o

${OBJECT_FOLDER}/array.c.o : ${DEPEND_FOLDER}/array.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,8%${COMMA} compiling object ../project/math/vector/array.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/array.c.o -MF ${DEPEND_FOLDER}/array.c.d -c ../project/math/vector/array.c -o ${OBJECT_FOLDER}/array.c.o

${OBJECT_FOLDER}/cross.c.o : ${DEPEND_FOLDER}/cross.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,10%${COMMA} compiling object ../project/math/vector/cross.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/cross.c.o -MF ${DEPEND_FOLDER}/cross.c.d -c ../project/math/vector/cross.c -o ${OBJECT_FOLDER}/cross.c.o

${OBJECT_FOLDER}/div.c.o : ${DEPEND_FOLDER}/div.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,12%${COMMA} compiling object ../project/math/vector/div.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/div.c.o -MF ${DEPEND_FOLDER}/div.c.d -c ../project/math/vector/div.c -o ${OBJECT_FOLDER}/div.c.o

${OBJECT_FOLDER}/dot.c.o : ${DEPEND_FOLDER}/dot.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,13%${COMMA} compiling object ../project/math/vector/dot.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/dot.c.o -MF ${DEPEND_FOLDER}/dot.c.d -c ../project/math/vector/dot.c -o ${OBJECT_FOLDER}/dot.c.o

${OBJECT_FOLDER}/empty.c.o : ${DEPEND_FOLDER}/empty.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,15%${COMMA} compiling object ../project/math/vector/empty.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/empty.c.o -MF ${DEPEND_FOLDER}/empty.c.d -c ../project/math/vector/empty.c -o ${OBJECT_FOLDER}/empty.c.o

${OBJECT_FOLDER}/length_x.c.o : ${DEPEND_FOLDER}/length_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,17%${COMMA} compiling object ../project/math/vector/length_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/length_x.c.o -MF ${DEPEND_FOLDER}/length_x.c.d -c ../project/math/vector/length_x.c -o ${OBJECT_FOLDER}/length_x.c.o

${OBJECT_FOLDER}/max.c.o : ${DEPEND_FOLDER}/max.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,18%${COMMA} compiling object ../project/math/vector/max.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/max.c.o -MF ${DEPEND_FOLDER}/max.c.d -c ../project/math/vector/max.c -o ${OBJECT_FOLDER}/max.c.o

${OBJECT_FOLDER}/min.c.o : ${DEPEND_FOLDER}/min.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,20%${COMMA} compiling object ../project/math/vector/min.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/min.c.o -MF ${DEPEND_FOLDER}/min.c.d -c ../project/math/vector/min.c -o ${OBJECT_FOLDER}/min.c.o

${OBJECT_FOLDER}/mul.c.o : ${DEPEND_FOLDER}/mul.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,22%${COMMA} compiling object ../project/math/vector/mul.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/mul.c.o -MF ${DEPEND_FOLDER}/mul.c.d -c ../project/math/vector/mul.c -o ${OBJECT_FOLDER}/mul.c.o

${OBJECT_FOLDER}/normalize.c.o : ${DEPEND_FOLDER}/normalize.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,24%${COMMA} compiling object ../project/math/vector/normalize.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/normalize.c.o -MF ${DEPEND_FOLDER}/normalize.c.d -c ../project/math/vector/normalize.c -o ${OBJECT_FOLDER}/normalize.c.o

${OBJECT_FOLDER}/pack.c.o : ${DEPEND_FOLDER}/pack.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,25%${COMMA} compiling object ../project/math/vector/pack.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/pack.c.o -MF ${DEPEND_FOLDER}/pack.c.d -c ../project/math/vector/pack.c -o ${OBJECT_FOLDER}/pack.c.o

${OBJECT_FOLDER}/print.c.o : ${DEPEND_FOLDER}/print.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,27%${COMMA} compiling object ../project/math/vector/print.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/print.c.o -MF ${DEPEND_FOLDER}/print.c.d -c ../project/math/vector/print.c -o ${OBJECT_FOLDER}/print.c.o

${OBJECT_FOLDER}/rotate_x.c.o : ${DEPEND_FOLDER}/rotate_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,29%${COMMA} compiling object ../project/math/vector/rotate_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/rotate_x.c.o -MF ${DEPEND_FOLDER}/rotate_x.c.d -c ../project/math/vector/rotate_x.c -o ${OBJECT_FOLDER}/rotate_x.c.o

${OBJECT_FOLDER}/sub.c.o : ${DEPEND_FOLDER}/sub.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,31%${COMMA} compiling object ../project/math/vector/sub.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/sub.c.o -MF ${DEPEND_FOLDER}/sub.c.d -c ../project/math/vector/sub.c -o ${OBJECT_FOLDER}/sub.c.o

${OBJECT_FOLDER}/empty_1.c.o : ${DEPEND_FOLDER}/empty_1.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,32%${COMMA} compiling object ../project/math/matrix/empty.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/empty_1.c.o -MF ${DEPEND_FOLDER}/empty_1.c.d -c ../project/math/matrix/empty.c -o ${OBJECT_FOLDER}/empty_1.c.o

${OBJECT_FOLDER}/look_at.c.o : ${DEPEND_FOLDER}/look_at.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,34%${COMMA} compiling object ../project/math/matrix/look_at.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/look_at.c.o -MF ${DEPEND_FOLDER}/look_at.c.d -c ../project/math/matrix/look_at.c -o ${OBJECT_FOLDER}/look_at.c.o

${OBJECT_FOLDER}/perspective.c.o : ${DEPEND_FOLDER}/perspective.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,36%${COMMA} compiling object ../project/math/matrix/perspective.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/perspective.c.o -MF ${DEPEND_FOLDER}/perspective.c.d -c ../project/math/matrix/perspective.c -o ${OBJECT_FOLDER}/perspective.c.o

${OBJECT_FOLDER}/product.c.o : ${DEPEND_FOLDER}/product.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,37%${COMMA} compiling object ../project/math/matrix/product.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/product.c.o -MF ${DEPEND_FOLDER}/product.c.d -c ../project/math/matrix/product.c -o ${OBJECT_FOLDER}/product.c.o

${OBJECT_FOLDER}/print_1.c.o : ${DEPEND_FOLDER}/print_1.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,39%${COMMA} compiling object ../project/math/matrix/print.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/print_1.c.o -MF ${DEPEND_FOLDER}/print_1.c.d -c ../project/math/matrix/print.c -o ${OBJECT_FOLDER}/print_1.c.o

${OBJECT_FOLDER}/rotate_x_1.c.o : ${DEPEND_FOLDER}/rotate_x_1.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,41%${COMMA} compiling object ../project/math/matrix/rotate_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/rotate_x_1.c.o -MF ${DEPEND_FOLDER}/rotate_x_1.c.d -c ../project/math/matrix/rotate_x.c -o ${OBJECT_FOLDER}/rotate_x_1.c.o

${OBJECT_FOLDER}/scale.c.o : ${DEPEND_FOLDER}/scale.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,43%${COMMA} compiling object ../project/math/matrix/scale.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/scale.c.o -MF ${DEPEND_FOLDER}/scale.c.d -c ../project/math/matrix/scale.c -o ${OBJECT_FOLDER}/scale.c.o

${OBJECT_FOLDER}/translate.c.o : ${DEPEND_FOLDER}/translate.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,44%${COMMA} compiling object ../project/math/matrix/translate.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/translate.c.o -MF ${DEPEND_FOLDER}/translate.c.d -c ../project/math/matrix/translate.c -o ${OBJECT_FOLDER}/translate.c.o

${OBJECT_FOLDER}/identity.c.o : ${DEPEND_FOLDER}/identity.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,46%${COMMA} compiling object ../project/math/matrix/identity.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/identity.c.o -MF ${DEPEND_FOLDER}/identity.c.d -c ../project/math/matrix/identity.c -o ${OBJECT_FOLDER}/identity.c.o

${OBJECT_FOLDER}/degrees_to_radians.c.o : ${DEPEND_FOLDER}/degrees_to_radians.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,48%${COMMA} compiling object ../project/math/other/degrees_to_radians.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/degrees_to_radians.c.o -MF ${DEPEND_FOLDER}/degrees_to_radians.c.d -c ../project/math/other/degrees_to_radians.c -o ${OBJECT_FOLDER}/degrees_to_radians.c.o

${OBJECT_FOLDER}/clamp.c.o : ${DEPEND_FOLDER}/clamp.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,50%${COMMA} compiling object ../project/math/other/clamp.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/clamp.c.o -MF ${DEPEND_FOLDER}/clamp.c.d -c ../project/math/other/clamp.c -o ${OBJECT_FOLDER}/clamp.c.o

${OBJECT_FOLDER}/engine.c.o : ${DEPEND_FOLDER}/engine.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,51%${COMMA} compiling object ../project/engine/engine.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/engine.c.o -MF ${DEPEND_FOLDER}/engine.c.d -c ../project/engine/engine.c -o ${OBJECT_FOLDER}/engine.c.o

${OBJECT_FOLDER}/opengl_x.c.o : ${DEPEND_FOLDER}/opengl_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,53%${COMMA} compiling object ../project/engine/opengl_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/opengl_x.c.o -MF ${DEPEND_FOLDER}/opengl_x.c.d -c ../project/engine/opengl_x.c -o ${OBJECT_FOLDER}/opengl_x.c.o

${OBJECT_FOLDER}/shader_x.c.o : ${DEPEND_FOLDER}/shader_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,55%${COMMA} compiling object ../project/engine/shader_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/shader_x.c.o -MF ${DEPEND_FOLDER}/shader_x.c.d -c ../project/engine/shader_x.c -o ${OBJECT_FOLDER}/shader_x.c.o

${OBJECT_FOLDER}/program_x.c.o : ${DEPEND_FOLDER}/program_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,56%${COMMA} compiling object ../project/engine/program_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/program_x.c.o -MF ${DEPEND_FOLDER}/program_x.c.d -c ../project/engine/program_x.c -o ${OBJECT_FOLDER}/program_x.c.o

${OBJECT_FOLDER}/loop.c.o : ${DEPEND_FOLDER}/loop.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,58%${COMMA} compiling object ../project/engine/loop.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/loop.c.o -MF ${DEPEND_FOLDER}/loop.c.d -c ../project/engine/loop.c -o ${OBJECT_FOLDER}/loop.c.o

${OBJECT_FOLDER}/render.c.o : ${DEPEND_FOLDER}/render.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,60%${COMMA} compiling object ../project/engine/render.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/render.c.o -MF ${DEPEND_FOLDER}/render.c.d -c ../project/engine/render.c -o ${OBJECT_FOLDER}/render.c.o

${OBJECT_FOLDER}/handle_key.c.o : ${DEPEND_FOLDER}/handle_key.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,62%${COMMA} compiling object ../project/engine/handle_key.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/handle_key.c.o -MF ${DEPEND_FOLDER}/handle_key.c.d -c ../project/engine/handle_key.c -o ${OBJECT_FOLDER}/handle_key.c.o

${OBJECT_FOLDER}/handle_x.c.o : ${DEPEND_FOLDER}/handle_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,63%${COMMA} compiling object ../project/engine/handle_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/handle_x.c.o -MF ${DEPEND_FOLDER}/handle_x.c.d -c ../project/engine/handle_x.c -o ${OBJECT_FOLDER}/handle_x.c.o

${OBJECT_FOLDER}/vbo_x.c.o : ${DEPEND_FOLDER}/vbo_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,65%${COMMA} compiling object ../project/engine/vbo_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/vbo_x.c.o -MF ${DEPEND_FOLDER}/vbo_x.c.d -c ../project/engine/vbo_x.c -o ${OBJECT_FOLDER}/vbo_x.c.o

${OBJECT_FOLDER}/vao_x.c.o : ${DEPEND_FOLDER}/vao_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,67%${COMMA} compiling object ../project/engine/vao_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/vao_x.c.o -MF ${DEPEND_FOLDER}/vao_x.c.d -c ../project/engine/vao_x.c -o ${OBJECT_FOLDER}/vao_x.c.o

${OBJECT_FOLDER}/mesh_x.c.o : ${DEPEND_FOLDER}/mesh_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,68%${COMMA} compiling object ../project/engine/mesh_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/mesh_x.c.o -MF ${DEPEND_FOLDER}/mesh_x.c.d -c ../project/engine/mesh_x.c -o ${OBJECT_FOLDER}/mesh_x.c.o

${OBJECT_FOLDER}/camera_x.c.o : ${DEPEND_FOLDER}/camera_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,70%${COMMA} compiling object ../project/engine/camera_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/camera_x.c.o -MF ${DEPEND_FOLDER}/camera_x.c.d -c ../project/engine/camera_x.c -o ${OBJECT_FOLDER}/camera_x.c.o

${OBJECT_FOLDER}/uniform_x.c.o : ${DEPEND_FOLDER}/uniform_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,72%${COMMA} compiling object ../project/engine/uniform_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/uniform_x.c.o -MF ${DEPEND_FOLDER}/uniform_x.c.d -c ../project/engine/uniform_x.c -o ${OBJECT_FOLDER}/uniform_x.c.o

${OBJECT_FOLDER}/texture_x_a.c.o : ${DEPEND_FOLDER}/texture_x_a.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,74%${COMMA} compiling object ../project/engine/texture_x_a.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/texture_x_a.c.o -MF ${DEPEND_FOLDER}/texture_x_a.c.d -c ../project/engine/texture_x_a.c -o ${OBJECT_FOLDER}/texture_x_a.c.o

${OBJECT_FOLDER}/texture_x_b.c.o : ${DEPEND_FOLDER}/texture_x_b.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,75%${COMMA} compiling object ../project/engine/texture_x_b.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/texture_x_b.c.o -MF ${DEPEND_FOLDER}/texture_x_b.c.d -c ../project/engine/texture_x_b.c -o ${OBJECT_FOLDER}/texture_x_b.c.o

${OBJECT_FOLDER}/material_x.c.o : ${DEPEND_FOLDER}/material_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,77%${COMMA} compiling object ../project/engine/material_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/material_x.c.o -MF ${DEPEND_FOLDER}/material_x.c.d -c ../project/engine/material_x.c -o ${OBJECT_FOLDER}/material_x.c.o

${OBJECT_FOLDER}/model_x_a.c.o : ${DEPEND_FOLDER}/model_x_a.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,79%${COMMA} compiling object ../project/engine/model_x_a.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/model_x_a.c.o -MF ${DEPEND_FOLDER}/model_x_a.c.d -c ../project/engine/model_x_a.c -o ${OBJECT_FOLDER}/model_x_a.c.o

${OBJECT_FOLDER}/model_x_b.c.o : ${DEPEND_FOLDER}/model_x_b.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,81%${COMMA} compiling object ../project/engine/model_x_b.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/model_x_b.c.o -MF ${DEPEND_FOLDER}/model_x_b.c.d -c ../project/engine/model_x_b.c -o ${OBJECT_FOLDER}/model_x_b.c.o

${OBJECT_FOLDER}/model_x_c.c.o : ${DEPEND_FOLDER}/model_x_c.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,82%${COMMA} compiling object ../project/engine/model_x_c.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/model_x_c.c.o -MF ${DEPEND_FOLDER}/model_x_c.c.d -c ../project/engine/model_x_c.c -o ${OBJECT_FOLDER}/model_x_c.c.o

${OBJECT_FOLDER}/parser.c.o : ${DEPEND_FOLDER}/parser.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,84%${COMMA} compiling object ../project/parser/parser.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/parser.c.o -MF ${DEPEND_FOLDER}/parser.c.d -c ../project/parser/parser.c -o ${OBJECT_FOLDER}/parser.c.o

${OBJECT_FOLDER}/fill_x.c.o : ${DEPEND_FOLDER}/fill_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,86%${COMMA} compiling object ../project/parser/fill_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/fill_x.c.o -MF ${DEPEND_FOLDER}/fill_x.c.d -c ../project/parser/fill_x.c -o ${OBJECT_FOLDER}/fill_x.c.o

${OBJECT_FOLDER}/read_model.c.o : ${DEPEND_FOLDER}/read_model.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,87%${COMMA} compiling object ../project/parser/read_model.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/read_model.c.o -MF ${DEPEND_FOLDER}/read_model.c.d -c ../project/parser/read_model.c -o ${OBJECT_FOLDER}/read_model.c.o

${OBJECT_FOLDER}/read_model_x_a.c.o : ${DEPEND_FOLDER}/read_model_x_a.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,89%${COMMA} compiling object ../project/parser/read_model_x_a.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/read_model_x_a.c.o -MF ${DEPEND_FOLDER}/read_model_x_a.c.d -c ../project/parser/read_model_x_a.c -o ${OBJECT_FOLDER}/read_model_x_a.c.o

${OBJECT_FOLDER}/read_model_x_b.c.o : ${DEPEND_FOLDER}/read_model_x_b.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,91%${COMMA} compiling object ../project/parser/read_model_x_b.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/read_model_x_b.c.o -MF ${DEPEND_FOLDER}/read_model_x_b.c.d -c ../project/parser/read_model_x_b.c -o ${OBJECT_FOLDER}/read_model_x_b.c.o

${OBJECT_FOLDER}/read_material_x_a.c.o : ${DEPEND_FOLDER}/read_material_x_a.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,93%${COMMA} compiling object ../project/parser/read_material_x_a.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/read_material_x_a.c.o -MF ${DEPEND_FOLDER}/read_material_x_a.c.d -c ../project/parser/read_material_x_a.c -o ${OBJECT_FOLDER}/read_material_x_a.c.o

${OBJECT_FOLDER}/read_material_x_b.c.o : ${DEPEND_FOLDER}/read_material_x_b.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,94%${COMMA} compiling object ../project/parser/read_material_x_b.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/read_material_x_b.c.o -MF ${DEPEND_FOLDER}/read_material_x_b.c.d -c ../project/parser/read_material_x_b.c -o ${OBJECT_FOLDER}/read_material_x_b.c.o

${OBJECT_FOLDER}/interim_mesh_x.c.o : ${DEPEND_FOLDER}/interim_mesh_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,96%${COMMA} compiling object ../project/parser/interim_mesh_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/interim_mesh_x.c.o -MF ${DEPEND_FOLDER}/interim_mesh_x.c.d -c ../project/parser/interim_mesh_x.c -o ${OBJECT_FOLDER}/interim_mesh_x.c.o

${OBJECT_FOLDER}/generate_x.c.o : ${DEPEND_FOLDER}/generate_x.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,98%${COMMA} compiling object ../project/parser/generate_x.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/generate_x.c.o -MF ${DEPEND_FOLDER}/generate_x.c.d -c ../project/parser/generate_x.c -o ${OBJECT_FOLDER}/generate_x.c.o

${OBJECT_FOLDER}/extract_directory.c.o : ${DEPEND_FOLDER}/extract_directory.c.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,100%${COMMA} compiling object ../project/parser/extract_directory.c}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/extract_directory.c.o -MF ${DEPEND_FOLDER}/extract_directory.c.d -c ../project/parser/extract_directory.c -o ${OBJECT_FOLDER}/extract_directory.c.o
	

#						DEPENDENCIES

${DEPEND_FOLDER} :
	${call INFO,Creating dependencies' folder}
	@mkdir ${DEPEND_FOLDER}
	
${DEPEND} :

include ${wildcard ${DEPEND}}	
