src = main.c
obj = $(src:.c=.o)
name = my_test
CC = clang

all: $(obj)
	$(CC) -o $(name) $(obj)

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(name)

re: fclean all