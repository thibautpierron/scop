# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 17:18:42 by tpierron          #+#    #+#              #
#    Updated: 2017/02/15 20:00:11 by thibautpier      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop
SRC = main.c initialization.c shader.c loadShaders.c math3d.c createBuffers.c loadModel.c loadModelFunc.c loadTexture.c genericTools.c
OBJ = main.o initialization.o shader.o loadShaders.o math3d.o createBuffers.o loadModel.o loadModelFunc.o loadTexture.o genericTools.o
LIBFT = lft
LIBMLX = lmlx
FLAGS = -Wall -Wextra -Werror
FRAME = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): ft mini
	gcc -c $(SRC)
	gcc -o $(NAME) -L./libft/ -$(LIBFT) -L./minilibx/ -$(LIBMLX) $(OBJ) $(FRAME) $(FLAGS)

ft:
	make -C libft

mini:
	make -C minilibx

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
