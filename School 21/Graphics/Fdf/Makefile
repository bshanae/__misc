NAME = fdf

#  libft

FT_DIR = ./libft
FT_LIB = $(addprefix $(FT_DIR), libft.a)
FT_INCL = $(addprefix $(FT_DIR), /include)

# compiler

CC = gcc
FLAGS = -Wall -Werror -Wextra 
MLX = -I $(MLX_DIR)include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 
OUT = -o $(NAME)

# sources, objects

FILES = map_read.c \
	  	point.c \
  		wu.c

SOURCES = $(addprefix $(FILES)

OBJECTS = 

# rules

all : $(FT_LIB) $(OBJECTS) 

$(FT_LIB) :
	make -C $(FT_DIR)
	make clean -C $(FT_DIR)
