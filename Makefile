##
## EPITECH PROJECT, 2019
## Makefile for 103cipher
## File description:
## Build the project
##

NAME = 103cipher

SRC 	= 	main.c \
			$(wildcard src/*.c) \
			$(wildcard lib/*.c) \

CFLAGS += -I./include -Wall -Wextra -lm -g

OBJ = $(SRC:.c=.o)

.SILENT:
all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(CFLAGS)
	echo "compile..."

clean:
	rm -f $(OBJ)
	echo "clean objects..."

fclean: clean
	rm -f $(NAME)
	echo "clean binary..."

re: fclean all
