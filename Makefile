# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 16:29:23 by pdoherty          #+#    #+#              #
#    Updated: 2019/02/16 12:10:04 by pdoherty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

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
	@gcc $(FLAGS) -g -fsanitize=address -c $(SRC)
	@gcc $(FLAGS) -g -fsanitize=address -o $(NAME) $(OBJ) -L ./libft -lft
