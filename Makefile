# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 17:34:00 by dchirkin          #+#    #+#              #
#    Updated: 2018/01/24 17:34:03 by dchirkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c \
		flipping.c \
		get_next_line.c \
		copy.c \
		help.c \
		inter2.c \
		start_end.c \
		way.c \
		loop_ants.c \
		move_ants.c \
		check_links.c \
		cheak_rooms.c \
		next_main.c \
		building_way.c \
		cheack_ways.c \
		next_main2.c \
		move_ants2.c \
		help1.c \
		check_links2.c \
		building_way2.c \
		start_end2.c \
		g_help.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) libft/libft.a $^ -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
