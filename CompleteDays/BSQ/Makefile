# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 21:44:08 by mbenhass          #+#    #+#              #
#    Updated: 2018/07/23 03:26:37 by mbenhass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(wildcard srcs/*/*.c)

FLAGS = -Wall -Wextra -Werror

NAME = bsq

HEAD = ./includes/

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) -I $(HEAD) -o $@ $^

%.o: %.c
	gcc $(FLAGS) -I $(HEAD) -o $@ -c $<

clean :
	/bin/rm -rf */*/*.o

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
