CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = srcs/*.c

OBJ = $(SRC:.c=.o)

all:$(SRC)
	@make -C ./parser
	@$(CC) $(CFLAGS) -o cub3D $(SRC)  -I -L ./parser/parser.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
	@echo "cub3D created successfully"

clean:
	@cd srcs && rm -rf *.o
	@cd parser && make clean
	@echo "Object files deleted - if exist"
fclean:clean
	@rm -rf *.bmp
	@rm -f cub3D
	@rm -rf cub3D.dSYM
	@echo "cub3D file deleted -if exist"
	@cd parser && make fclean

re: fclean all
	@echo "Targets updated successfully"

.PHONY: all clean fclean re
