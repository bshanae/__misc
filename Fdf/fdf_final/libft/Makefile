# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshanae <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 13:31:11 by bshanae           #+#    #+#              #
#    Updated: 2019/04/19 11:03:42 by bshanae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#						MEMORY
# ============================================================================ #

MEM_FILES = 			\
	ft_memcmp.c			\
	ft_bzero.c			\
	ft_memcpy.c			\
	ft_memalloc.c		\
	ft_memccpy.c		\
	ft_realloc.c		\
	ft_memchr.c			\
	ft_memset.c			\
	ft_memdel.c			\
	ft_memmove.c	

MEM_DIR = 				\
	./src_memory/

MEM_OBJ = $(addprefix $(OBJ_DIR), $(MEM_FILES:.c=.o))


# ============================================================================ #
#						NUMERIC
# ============================================================================ #

NUM_FILES = 			\
	ft_max.c			\
	ft_min.c			\
	ft_abs.c

NUM_DIR = 				\
	./src_num/

NUM_OBJ = $(addprefix $(OBJ_DIR), $(NUM_FILES:.c=.o))


# ============================================================================ #
# 						STRING
# ============================================================================ #

STR_FILES = 			\
	ft_strncat.c		\
	ft_strnstr.c		\
	ft_strequ.c			\
	ft_strlen.c			\
	ft_strclr.c			\
	ft_strchr.c			\
	ft_striteri.c		\
	ft_strjoin.c		\
	ft_strstr.c			\
	ft_strcat.c			\
	ft_strdel.c			\
	ft_strnequ.c		\
	ft_strrchr.c		\
	ft_strmap.c			\
	ft_strncmp.c		\
	ft_strcpy.c			\
	ft_strmapi.c		\
	ft_strtrim.c		\
	ft_strnew.c			\
	ft_strlcat.c		\
	ft_strdup.c			\
	ft_atoi.c			\
	ft_atoi_base.c		\
	ft_itoa.c			\
	ft_striter.c		\
	ft_strsub.c			\
	ft_strncpy.c		\
	ft_strcmp.c

STR_DIR = 				\
	./src_string/

STR_OBJ = $(addprefix $(OBJ_DIR), $(STR_FILES:.c=.o))


# ============================================================================ #
# 						PUT
# ============================================================================ #

PUT_FILES = 			\
	ft_putchar.c		\
	ft_putchar_fd.c		\
	ft_putendl.c		\
	ft_putendl_fd.c		\
	ft_putnbr.c			\
	ft_putnbr_fd.c		\
	ft_putstr.c			\
	ft_putstr_fd.c

PUT_DIR = 				\
	./src_put/

PUT_OBJ = $(addprefix $(OBJ_DIR), $(PUT_FILES:.c=.o))


# ============================================================================ #
# 						LIST
# ============================================================================ #

LIST_FILES = 			\
	list_alloc.c		\
	list_free.c			\
	list_clean.c		\
	list_push_front.c	\
	list_push_back.c	\
	list_emplace_front.c\
	list_emplace_back.c	\
	list_delete.c		\
	list_find.c			\
	list_iter.c			\
	list_print.c		\
	list_last.c			\
	list_len.c

LIST_DIR = 				\
	./src_list/

LIST_OBJ = $(addprefix $(OBJ_DIR), $(LIST_FILES:.c=.o))


# ============================================================================ #
# 						BTREE
# ============================================================================ #

BTREE_FILES = 			\
	btree_alloc.c		\
	btree_clean.c		\
	btree_insert.c		\
	btree_delete.c		\
	btree_find.c		\
	btree_depth.c		\
	btree_verify.c		\
	btree_infix.c		\
	btree_prefix.c		\
	btree_suffix.c

BTREE_DIR = 			\
	./src_btree/

BTREE_OBJ = $(addprefix $(OBJ_DIR), $(BTREE_FILES:.c=.o))


# ============================================================================ #
# 						GET_NEXT_LINE
# ============================================================================ #

SB_FILES =				\
	sb_alloc.c			\
	sb_free.c			\
	sb_realloc.c		\
	sb_reset.c			\
	sb_set_target.c		\
	sb_functors.c		\
	sb_in.c				\
	sb_out.c

SB_DIR = 				\
	./src_gnl/sb/

SB_OBJ = $(addprefix $(OBJ_DIR), $(SB_FILES:.c=.o))

GNL_FILES = 			\
	get_next_line.c

GNL_DIR =	 			\
	./src_gnl/gnl/

GNL_OBJ = $(addprefix $(OBJ_DIR), $(GNL_FILES:.c=.o))

# ============================================================================ #
# ============================================================================ #
# 						LIBFT
# ============================================================================ #
# ============================================================================ #

NAME = libft.a
	
OBJ = 					\
	$(MEM_OBJ)			\
	$(NUM_OBJ)			\
	$(STR_OBJ)			\
	$(PUT_OBJ)			\
	$(LIST_OBJ)			\
	$(BTREE_OBJ)		\
	$(SB_OBJ)			\
	$(GNL_OBJ)

OBJ_DIR = ./temp/

COMP = gcc -Wall -Wextra -Werror -I./includes

# main
all : $(NAME)

$(NAME)	: $(OBJ_DIR) $(OBJ) 	
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	
# folder
$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

# memory
$(OBJ_DIR)%.o : $(MEM_DIR)%.c
	@$(COMP) -c $< -o $@

# numeric
$(OBJ_DIR)%.o : $(NUM_DIR)%.c
	@$(COMP) -c $< -o $@

# str
$(OBJ_DIR)%.o : $(STR_DIR)%.c
	@$(COMP) -c $< -o $@

# put
$(OBJ_DIR)%.o : $(PUT_DIR)%.c
	@$(COMP) -c $< -o $@

# list
$(OBJ_DIR)%.o : $(LIST_DIR)%.c
	@$(COMP) -c $< -o $@

# btree 
$(OBJ_DIR)%.o : $(BTREE_DIR)%.c
	@$(COMP) -c $< -o $@

# get next line_ptr
$(OBJ_DIR)%.o : $(SB_DIR)%.c
	@$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(GNL_DIR)%.c
	@$(COMP) -c $< -o $@

#
clean :
	@/bin/rm -rf $(OBJ_DIR)

fclean : clean
	@/bin/rm -f $(NAME)

# 
re : fclean all
