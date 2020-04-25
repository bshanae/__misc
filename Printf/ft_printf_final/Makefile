# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshanae <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 20:52:08 by bshanae           #+#    #+#              #
#    Updated: 2019/05/23 14:52:54 by bshanae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =														\
	./ft/ft_printf.c										\
	./ftp_buffer/ftp_buffer_functions.c						\
	./ftp_buffer/ftp_buffer_main.c							\
	./ftp_control/ftp_control_definition.c					\
	./ftp_control/ftp_control_functions.c					\
	./ftp_control/ftp_control_functions_style.c				\
	./ftp_format_data/ftp_format_data.c						\
	./ftp_format_data/ftp_format_data_default.c				\
	./ftp_format_data/ftp_format_data_long.c				\
	./ftp_format_data/ftp_format_data_short.c				\
	./ftp_format_in/ftp_format_additional.c					\
	./ftp_format_in/ftp_format_in.c							\
	./ftp_format_in/ftp_format_in_flags.c					\
	./ftp_format_in/ftp_format_in_precision.c				\
	./ftp_format_in/ftp_format_in_size.c					\
	./ftp_format_in/ftp_format_in_type.c					\
	./ftp_format_in/ftp_format_in_width.c					\
	./ftp_format_out/ftp_format_out.c						\
	./ftp_format_out/ftp_format_out_char.c					\
	./ftp_format_out/ftp_format_out_ptr.c					\
	./ftp_format_out/ftp_format_out_str.c					\
	./ftp_format_out_real/format_out_real_exceptions.c		\
	./ftp_format_out_real/ftp_format_out_real.c				\
	./ftp_format_out_real/ftp_format_out_real_convert.c		\
	./ftp_format_out_real/ftp_format_out_real_init.c		\
	./ftp_format_out_real/ftp_format_out_real_out.c			\
	./ftp_format_out_real/ftp_format_out_real_round.c		\
	./ftp_format_out_whole/ftp_format_out_whole.c			\
	./ftp_format_out_whole/ftp_format_out_whole_init.c		\
	./ftp_format_out_whole/ftp_format_out_whole_out.c		\
	./ftp_format_out_whole/ftp_format_out_whole_process.c	\
	./long/long_basic.c										\
	./long/long_functions.c									\
	./utils/utils.c

OBJ_DIR = ./objects/

OBJ_LIB_PRE =												\
	./libft_vector/objects/vector_at.o						\
	./libft_vector/objects/vector_clear.o					\
	./libft_vector/objects/vector_create.o					\
	./libft_vector/objects/vector_delete.o					\
	./libft_vector/objects/vector_destroy.o					\
	./libft_vector/objects/vector_emplace_back.o			\
	./libft_vector/objects/vector_enlarge.o					\
	./libft_vector/objects/vector_insert.o					\
	./libft_vector/objects/vector_pop_back.o				\
	./libft_vector/objects/vector_push_back.o				\
	./libft_vector/objects/vector_traverse.o				\
	./libft_standart/objects/ft_abs.o						\
	./libft_standart/objects/ft_atoi.o						\
	./libft_standart/objects/ft_atoi_base.o					\
	./libft_standart/objects/ft_bzero.o						\
	./libft_standart/objects/ft_itoa.o						\
	./libft_standart/objects/ft_max.o						\
	./libft_standart/objects/ft_memalloc.o					\
	./libft_standart/objects/ft_memccpy.o					\
	./libft_standart/objects/ft_memchr.o					\
	./libft_standart/objects/ft_memcmp.o					\
	./libft_standart/objects/ft_memcpy.o					\
	./libft_standart/objects/ft_memdel.o					\
	./libft_standart/objects/ft_memmove.o					\
	./libft_standart/objects/ft_memset.o					\
	./libft_standart/objects/ft_min.o						\
	./libft_standart/objects/ft_realloc.o					\
	./libft_standart/objects/ft_strcat.o					\
	./libft_standart/objects/ft_strchr.o					\
	./libft_standart/objects/ft_strclr.o					\
	./libft_standart/objects/ft_strcmp.o					\
	./libft_standart/objects/ft_strcpy.o					\
	./libft_standart/objects/ft_strdel.o					\
	./libft_standart/objects/ft_strdup.o					\
	./libft_standart/objects/ft_strjoin.o					\
	./libft_standart/objects/ft_strlen.o					\
	./libft_standart/objects/ft_strncat.o					\
	./libft_standart/objects/ft_strncmp.o					\
	./libft_standart/objects/ft_strncpy.o					\
	./libft_standart/objects/ft_strnew.o					\
	./libft_standart/objects/ft_strnstr.o					\
	./libft_standart/objects/ft_strrchr.o					\
	./libft_standart/objects/ft_strstr.o					\
	./libft_standart/objects/ft_strsub.o					\
	./libft_standart/objects/ft_strtrim.o

OBJ_LIB = $(addprefix $(OBJ_DIR), $(notdir $(OBJ_LIB_PRE)))

OBJ_FT_PRE = $(notdir $(SRC:.c=.o))
OBJ_FT = $(addprefix $(OBJ_DIR), $(OBJ_FT_PRE))

INCL_DIR  =													\
	./ft/													\
	./ftp_buffer/											\
	./ftp_control/											\
	./ftp_format_data/										\
	./ftp_format_in/										\
	./ftp_format_out/										\
	./ftp_format_out_real/									\
	./ftp_format_out_whole/									\
	./ftp_whitespaces/										\
	./long/													\
	./utils/												\
	./libft_standart/										\
	./libft_vector/

INCL_FILES = 												\
	./ftp_buffer/ftp_buffer_main.h							\
	./ftp_buffer/ftp_buffer_definition.h					\
	./ftp_buffer/ftp_buffer_functions.h						\
	./ftp_control/ftp_control_definition.h					\
	./ftp_control/ftp_control_functions.h					\
	./ftp_whitespaces/ftp_whitespaces.h						\
	./ftp_format_in/ftp_format_in.h							\
	./utils/utils.h											\
	./ftp_format_data/ftp_format_data.h						\
	./ftp_format_out_whole/ftp_format_out_whole.h			\
	./long/long.h											\
	./ftp_format_out_real/ftp_format_out_real.h				\
	./ftp_format_out/ftp_format_out.h						\
	./ft/ft_printf.h										\
	./libft_standart/libft_standart.h						\
	./libft_vector/libft_vector.h

INCL = $(addprefix -I, $(INCL_DIR))

NAME = libftprintf.a

COMP = gcc -Wall -Wextra -Werror -c

all : $(NAME)

$(NAME) : $(INCL_FILES) $(OBJ_DIR) $(OBJ_LIB) $(OBJ_FT) 
	@echo ">>> ft_printf : creating library <<<"
	@ar rc $(NAME) $(OBJ_LIB) $(OBJ_FT)
	@ranlib $(NAME)

$(OBJ_DIR) :
	@echo ">>> ft_printf : creating directory for objects <<<"
	@mkdir -p $(OBJ_DIR)

$(OBJ_LIB_PRE) :
	@echo ">>> ft_printf : compiling libft <<<"
	@make -C ./libft_standart/
	@make -C ./libft_vector/

$(OBJ_LIB) : $(OBJ_LIB_PRE)
	@echo ">>> ft_printf : coping libft objects <<<"
	@$(foreach obj,$(OBJ_LIB_PRE), cp $(obj) $(addprefix $(OBJ_DIR), $(notdir $(obj)));)


$(OBJ_FT) : $(SRC)
	@echo ">>> ft_printf : compiling my objects <<<"
	@$(COMP) $(INCL) $(SRC)
	@$(foreach obj,$(OBJ_FT_PRE),mv $(obj) $(addprefix $(OBJ_DIR), $(obj));)

clean :
	@echo ">>> ft_printf : deleting objects <<<"
	@rm -rf test
	@rm -rf $(OBJ_DIR)
	@make clean -C ./libft_vector/
	@make clean -C ./libft_standart/

fclean : clean
	@echo ">>> ft_printf : deleting library file <<<"
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
