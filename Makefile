# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 18:04:58 by adubois           #+#    #+#              #
#    Updated: 2016/03/12 17:06:19 by tbalu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3
INC_PATH = -I./inc/ -I./libft/ -I./minilibx_macos/
SRC_PATH = ./src/
SRCS = main.c image.c constructor.c events.c color.c vector.c draw_image.c \
draw_verti.c events_2.c loader.c paste_texture.c key_release.c key_press.c
FLAGSMLX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
FLAGSLIBFT = -L libft/ -lft
SRC = $(SRCS:%.c=$(SRC_PATH)%.c)
OBJ = $(SRC:%.c=%.o)

all: mlx lft $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGSLIBFT) $(FLAGSMLX)

mlx:
	make -C minilibx_macos/

lft:
	make -C libft/

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C minilibx_macos/ clean
	make -C libft/ fclean

memclean:
	rm -rf *~

re: fclean all
