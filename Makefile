SRC = $(wildcard SRC/*.c) \
	$(wildcard LIB/*.c)
OBJ = $(SRC:.c=.o)
NAME = my_world
CC = epiclang
CFLAGS = -I includes/

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
