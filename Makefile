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
		cheack_ways.c

OBJ = $(SRC:.c=.o)

CFLAGS = -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	gcc $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

%.o: ./%.c
	gcc -g -o $@ -c $<

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
