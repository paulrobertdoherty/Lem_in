# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 16:23:43 by pdoherty          #+#    #+#              #
#    Updated: 2018/10/25 18:41:57 by pdoherty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c

OUT = $(SRCS:%.c=%.o)

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRCS) -I $(INCLUDES)
	@ar rcs $(NAME) $(OUT)
	
clean:
	@rm -f $(OUT)

fclean:
	@rm -f $(OUT)
	@rm -f $(NAME)

re: fclean $(NAME)
