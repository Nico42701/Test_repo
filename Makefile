SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	clang $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f a.out

re: fclean all