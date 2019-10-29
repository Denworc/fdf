#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 01:16:19 by smaksymy          #+#    #+#              #
#    Updated: 2017/10/12 01:16:30 by smaksymy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    = fdf

SRC     = src/main.c \
	src/check.c \
	src/color.c \
	src/draw.c \
	src/make.c \
	src/make_im.c \
	src/matrix.c \
	src/matrix2.c \
	src/matrix3.c \
	src/move.c \
	src/ui.c \

SUBMAKE = ./libft

CD = cd ..

MAKE = make

OBJECT = $(SRC:.c=.o)

CC  = gcc

FLAGS   = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

LIB = -L./libft -lft -I.

all : $(NAME)

$(NAME): $(OBJECT)
	cd $(SUBMAKE) && $(MAKE) && $(CD)
	$(CC) $(FLAGS) -o $(NAME) $(MLX_FLAGS) $(OBJECT) $(LIB)

clean :
	rm -rf src/*.o
	rm -rf libft/*.o

fclean : clean
	rm -rf fdf
	rm -rf libft/libft.a

re : fclean all