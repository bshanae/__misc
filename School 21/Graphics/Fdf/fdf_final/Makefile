
# ============================================================================ #
# 								MLX
# ============================================================================ #

MLX_FRAME =						\
	-framework OpenGL			\
	-framework AppKit

MLX_INCL =						\
	-I /usr/local/include

MLX_LIB =						\
	-L /usr/local/lib				\
	-lmlx

# ============================================================================ #
# 								LIBFT
# ============================================================================ #

LIBFT_DIR = ./libft/

LIBFT_INCL = 					\
	-I ./libft/includes/

LIBFT_LIB =						\
	-L $(LIBFT_DIR)				\
	-lft

LIBFT = 						\
	./libft/libft.a

# ============================================================================ #
# 								ERROR
# ============================================================================ #

ERROR_DIR =						\
	./error/

ERROR_INCL =					\
	-I ./error/

# ============================================================================ #
# 								COLOR
# ============================================================================ #

COLOR_DIR = 					\
	./color/

COLOR_INCL = 					\
	-I ./color/

# ============================================================================ #
# 								SOME_MATH
# ============================================================================ #

SOME_MATH_DIR = 				\
	./some_math/

SOME_MATH_INCL =				\
	-I ./some_math/

# ============================================================================ #
# 								QUATERNION
# ============================================================================ #

QUATERNION_DIR =				\
	./quaternion/

QUATERNION_INCL = 				\
	-I ./quaternion/

# ============================================================================ #
# 								POINT
# ============================================================================ #

POINT_DIR = 					\
	./point/

POINT_INCL = 					\
	-I ./point/

# ============================================================================ #
# 								MAP
# ============================================================================ #

MAP_DIR = 						\
	./map/

MAP_INCL =						\
	-I ./map/

# ============================================================================ #
# 								VO
# ============================================================================ #

VO_DIR = 						\
	./vo/

VO_INCL =						\
	-I ./vo

# ============================================================================ #
# 								ALL
# ============================================================================ #

NAME = fdf

SRC =							\
	./error/error.c				\
	./color/color.c				\
	./some_math/some_math.c		\
	./quaternion/quaternion.c	\
	./point/point.c				\
	./map_tree_utils.c			\
	./map_wu.c					\
	./map_iso.c					\
	./map_main.c				\
	./map_functions.c			\
	./map_read_utils.c			\
	./map_tree_render.c			\
	./map_read.c				\
	./vo_main.c					\
	./vo_control.c				\
	./vo_terminal_functions.c	\
	./vo_terminal_main.c		\
	./vo_term_translate.c		\
	./vo_terminal_utils.c		\
	./main.c

OBJ_DIR = ./objects/

OBJ_PRE = $(notdir $(SRC))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_PRE:.c=.o))

COMP = gcc -g -Wall -Wextra -Werror

# ============================================================================ #
# 								RULES
# ============================================================================ #

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ)
	@$(COMP) 					\
	$(MLX_INCL)					\
	$(MLX_LIB) 					\
	$(MLX_FRAME)				\
	$(LIBFT_LIB)				\
	$(OBJ)						\
	-o $(NAME) 

$(LIBFT) : 
	@make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : $(ERROR_DIR)%.c
	@$(COMP) 					\
	$(LIBFT_INCL) 				\
	-c $< -o $@

$(OBJ_DIR)%.o : $(COLOR_DIR)%.c
	@$(COMP) 					\
	$(LIBFT_INCL) 				\
	$(ERROR_INCL) 				\
	-c $< -o $@

$(OBJ_DIR)%.o : $(SOME_MATH_DIR)%.c
	@$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(QUATERNION_DIR)%.c
	@$(COMP) 					\
	$(SOME_MATH_INCL) 			\
	-c $< -o $@

$(OBJ_DIR)%.o : $(POINT_DIR)%.c
	@$(COMP) 					\
	$(LIBFT_INCL) 				\
	$(ERROR_INCL) 				\
	$(COLOR_INCL) 				\
	$(SOME_MATH_INCL) 			\
	$(QUATERNION_INCL) 			\
	-c $< -o $@

$(OBJ_DIR)%.o : $(MAP_DIR)%.c
	@$(COMP) 					\
	$(LIBFT_INCL)				\
 	$(ERROR_INCL) 				\
	$(COLOR_INCL) 				\
	$(SOME_MATH_INCL) 			\
	$(QUATERNION_INCL) 			\
	$(POINT_INCL)				\
	-c $< -o $@

$(OBJ_DIR)%.o : $(VO_DIR)%.c
	@$(COMP) 					\
	$(MLX_INCL)					\
	$(LIBFT_INCL)				\
 	$(ERROR_INCL) 				\
	$(COLOR_INCL) 				\
	$(SOME_MATH_INCL) 			\
	$(QUATERNION_INCL) 			\
	$(POINT_INCL)				\
	$(MAP_INCL)					\
	-c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make -C ./libft clean

fclean : clean
	@rm -rf $(NAME)
	@rm -rf ./libft/libft.a

re : fclean $(NAME)
