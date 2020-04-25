# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshanae <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 19:12:47 by bshanae           #+#    #+#              #
#    Updated: 2019/05/13 20:53:44 by bshanae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vector

FILES = 							\
	vector_at.c						\
	vector_clear.c					\
	vector_create.c					\
	vector_delete.c					\
	vector_destroy.c				\
	vector_emplace_back.c			\
	vector_enlarge.c				\
	vector_insert.c					\
	vector_pop_back.c				\
	vector_push_back.c				\
	vector_traverse.c

SRC_DIR = ./sources/
OBJ_DIR = ./objects/

SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

INCL = -I ./ -I ../libft_standart/

COMP = gcc -Wall -Wextra -Werror $(INCL)

all : $(NAME) 
	
$(NAME) : $(OBJ_DIR) $(OBJ)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(COMP) -o $@ -c $<

clean : 
	rm -rf $(OBJ_DIR)

re : clean $(NAME)

.PHONY : $(NAME) clean re
