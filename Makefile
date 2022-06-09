##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC =	main.c \
		bsq_calc.c \
		bsq_print.c

OBJ = 	$(SRC:.c=.o)

NAME = 	bsq

CFLAGS = -g

all: 	$(NAME)

$(NAME): 	$(OBJ)
		gcc -g -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
