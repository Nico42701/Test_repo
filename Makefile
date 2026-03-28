SRC = $(wildcard src/*.c) \
	$(wildcard lib/*.c) \
	$(wildcard lib/my_printf/*.c)

OBJ = $(SRC:.c=.o)

NAME = mysh
CC = clang
CFLAGS = -I includes/ -W -Werror -Wall -Wextra

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
