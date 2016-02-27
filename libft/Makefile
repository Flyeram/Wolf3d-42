# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:04:50 by tbalu             #+#    #+#              #
#    Updated: 2016/02/08 15:09:31 by tbalu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC = ft_putchar.c ft_putstr.c ft_strlen.c ft_isalpha.c ft_isalnum.c \
ft_isdigit.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_atoi.c ft_memccpy.c ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c \
ft_memmove.c ft_memchr.c ft_strequ.c ft_strnequ.c ft_itoa.c ft_memcmp.c\
ft_putnbr.c ft_putnbr_fd.c ft_strsub.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_lsteadd.c ft_lstmap.c get_next_line.c get_next_line_utils.c ft_min.c \
ft_max.c ft_hextodec.c ft_arraylen.c ft_free_array.c ft_isblank.c ft_stof.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

memoryclean:
	rm -f *~

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
