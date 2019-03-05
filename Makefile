# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 16:29:23 by pdoherty          #+#    #+#              #
#    Updated: 2019/03/03 12:09:50 by pdoherty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra -g

SRC = *.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

asan: fclean
	@make -C libft
	@gcc $(FLAGS) -g -fsanitize=address -c $(SRC) ; ASAN_OPTIONS=detect_leaks=1
	@gcc $(FLAGS) -g -fsanitize=address -o $(NAME) $(OBJ) -L ./libft -lft
