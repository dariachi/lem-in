#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 18:21:03 by dchirkin          #+#    #+#              #
#    Updated: 2017/02/27 12:03:41 by dchirkin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC =	ft_putchar.c	\
		ft_putstr.c		\
		ft_strlen.c		\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strdup.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_isdigit.c	\
		ft_isalpha.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_memcmp.c		\
		ft_putendl.c	\
		ft_itoa.c		\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_strsplit.c	\
		ft_lstnew.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_goodline.c	\
		ft_wcount.c		\
		ft_copw.c		\
		ft_coun_in_w.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

HEADERS = libft.h

all:	$(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
