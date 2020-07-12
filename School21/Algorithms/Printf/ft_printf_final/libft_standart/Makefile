# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshanae <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 21:01:30 by bshanae           #+#    #+#              #
#    Updated: 2019/05/23 13:17:14 by bshanae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#							MEMORY
# ============================================================================ #

MEM_FILES = 				\
	ft_bzero.c				\
	ft_memalloc.c			\
	ft_memccpy.c			\
	ft_memchr.c				\
	ft_memcmp.c				\
	ft_memcpy.c				\
	ft_memdel.c				\
	ft_memmove.c			\
	ft_memset.c				\
	ft_realloc.c

MEM_DIR = 					\
	./sources_memory/

MEM_OBJ = $(addprefix $(OBJ_DIR), $(MEM_FILES:.c=.o))


# ============================================================================ #
#							NUMERIC
# ============================================================================ #

NUM_FILES = 				\
	ft_abs.c				\
	ft_max.c				\
	ft_min.c

NUM_DIR = 					\
	./sources_num/

NUM_OBJ = $(addprefix $(OBJ_DIR), $(NUM_FILES:.c=.o))


# ============================================================================ #
# 							STRING
# ============================================================================ #

STR_FILES = 				\
	ft_atoi.c				\
	ft_atoi_base.c			\
	ft_itoa.c				\
	ft_strcat.c				\
	ft_strchr.c				\
	ft_strclr.c				\
	ft_strcmp.c				\
	ft_strcpy.c				\
	ft_strdel.c				\
	ft_strdup.c				\
	ft_strjoin.c			\
	ft_strlen.c				\
	ft_strncat.c			\
	ft_strncmp.c			\
	ft_strncpy.c			\
	ft_strnew.c				\
	ft_strnstr.c			\
	ft_strrchr.c			\
	ft_strstr.c				\
	ft_strsub.c				\
	ft_strtrim.c

STR_DIR = 					\
	./sources_string/

STR_OBJ = $(addprefix $(OBJ_DIR), $(STR_FILES:.c=.o))

# ============================================================================ #
# ============================================================================ #
# 							STANDART
# ============================================================================ #
# ============================================================================ #

NAME = standart

INCL = -I ./

COMP = gcc -Wall -Wextra -Werror $(INCL)

OBJ_DIR =					\
	./objects/

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(MEM_OBJ) $(NUM_OBJ) $(STR_OBJ)

$(OBJ_DIR) : 
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : $(MEM_DIR)%.c
	$(COMP) -o $@ -c $<

$(OBJ_DIR)%.o : $(NUM_DIR)%.c
	$(COMP) -o $@ -c $<

$(OBJ_DIR)%.o : $(STR_DIR)%.c
	$(COMP) -o $@ -c $<

clean : 
	rm -rf $(OBJ_DIR)

re : clean $(NAME)

.PHONY : $(NAME) clean re
