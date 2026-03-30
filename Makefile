##
## EPITECH PROJECT, 2026
## make
## File description:
## make
##
NAME	:=	crocus

SRC_DIR := src
SRC_SUBDIRS := parser print free crocus
SRC_PATHS := $(addprefix $(SRC_DIR)/,$(SRC_SUBDIRS))
SRC_ROOT := $(wildcard $(SRC_DIR)/*.c)
SRC_SUB  := $(foreach dir,$(SRC_PATHS),$(wildcard $(dir)/*.c))
SRC := $(SRC_ROOT) $(SRC_SUB)

OBJ	:=	$(SRC:.c=.o)

CFLAGS	:=	-I./include

CC	:=	clang

FLAG	:=	-I./include

all:	$(OBJ)
	@echo "[OK] Binary files $(NAME) compiled succesfully"
	@$(CC) -o $(NAME) $(OBJ) $(FLAG)

clean:
	@rm -rf $(OBJ)
	@rm -rf #Makefile#
	@rm -rf $(LIBNAME)
	@echo "Remove .o"

fclean: clean
	@rm -rf $(NAME)
	@echo "Remove binary files"

clang: all
	@epiclang -o $(NAME) src/*.c $(FLAG)
	@echo "Epiclang done"

re:	fclean all
