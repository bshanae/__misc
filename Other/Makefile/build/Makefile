#						FUNCTIONS

define INFO
${info ${PREFIX} : $1}
endef

#						VARIABLES

COMMA = ,

OBJECT_FOLDER = .object
DEPEND_FOLDER = .depend

COMPILER = clang++
PREFIX = test
EXECUTABLE = test

INCLUDE = -I ../test_project
OBJECT = ${OBJECT_FOLDER}/main.cpp.o ${OBJECT_FOLDER}/impl.cpp.o ${OBJECT_FOLDER}/impl_1.cpp.o
DEPEND = ${DEPEND_FOLDER}/main.cpp.d ${DEPEND_FOLDER}/impl.cpp.d ${DEPEND_FOLDER}/impl_1.cpp.d
LINK_DIRECTORY = -L ../test_project/lib
LINK_LIBRARY = -l 1 -framework OpenCL

FLAG_OBJECT = `pkg-config --cflags glew` `pkg-config --cflags glfw3` `pkg-config --cflags glm` `pkg-config --cflags freetype2`
FLAG_EXECUTABLE = `pkg-config --libs glew` `pkg-config --libs glfw3` `pkg-config --libs glm` `pkg-config --libs freetype2`
FLAG_COMMON = std=c++17

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

${OBJECT_FOLDER}/main.cpp.o : ${DEPEND_FOLDER}/main.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,33%${COMMA} compiling object ../test_project/main.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/main.cpp.o -MF ${DEPEND_FOLDER}/main.cpp.d -c ../test_project/main.cpp -o ${OBJECT_FOLDER}/main.cpp.o

${OBJECT_FOLDER}/impl.cpp.o : ${DEPEND_FOLDER}/impl.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,66%${COMMA} compiling object ../test_project/print_hi/impl.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/impl.cpp.o -MF ${DEPEND_FOLDER}/impl.cpp.d -c ../test_project/print_hi/impl.cpp -o ${OBJECT_FOLDER}/impl.cpp.o

${OBJECT_FOLDER}/impl_1.cpp.o : ${DEPEND_FOLDER}/impl_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,100%${COMMA} compiling object ../test_project/print_bye/impl.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/impl_1.cpp.o -MF ${DEPEND_FOLDER}/impl_1.cpp.d -c ../test_project/print_bye/impl.cpp -o ${OBJECT_FOLDER}/impl_1.cpp.o
	

#						DEPENDENCIES

${DEPEND_FOLDER} :
	${call INFO,Creating dependencies' folder}
	@mkdir ${DEPEND_FOLDER}
	
${DEPEND} :

include ${wildcard ${DEPEND}}	
