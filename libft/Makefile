#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 16:30:30 by smaksymy          #+#    #+#              #
#    Updated: 2017/05/03 16:00:46 by smaksymy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	libft.a

SRC =	ft_putchar.c ft_putstr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		ft_memmove.c ft_memchr.c ft_memcmp.c\
		ft_strlen.c ft_strcpy.c ft_strdup.c ft_strncpy.c\
		ft_strcat.c ft_strncat.c ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strnequ.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_whitespace.c\
		ft_getlet.c\
		ft_getwords.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_absval.c\
		ft_power.c\
		ft_max.c\
		ft_min.c\
		ft_tobigger.c\
		ft_tosmaller.c\
		get_next_line.c\

OBJ =	$(SRC:.c=.o)

FLAGS = 	-Wall -Wextra -Werror

OPTIONS = 	-c -I 

all : 		$(NAME)

$(NAME) :
	gcc $(FLAGS) $(OPTIONS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all