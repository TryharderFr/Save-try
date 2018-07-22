CC= gcc

NAME = eval_expr

SRCS = 	operands.c \
	parenthes.c \
	main.c \
	ft_putnbr.c \
	ft_putchar.c \
	ft_strlen.c

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(SRCS)

OBJ = $(SRC:%.c=%.o)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
