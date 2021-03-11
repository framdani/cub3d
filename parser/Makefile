CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = parser.a
SRC = *.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	@rm -rf *.o
fclean:clean
	@rm -rf $(NAME)
re:fclean all
