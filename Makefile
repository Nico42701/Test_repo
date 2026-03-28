SRC = main.c
OBJ = $(SRC:.c=.o)
NAME = my_tests

all: $(OBJ)
	clang $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all