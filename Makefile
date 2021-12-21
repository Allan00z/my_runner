##
## EPITECH PROJECT, 2021
## B-MUL-100-LYN-1-1-myrunner-allan.branco
## File description:
## Makefile
##

SRC	=	sources/window.c	\
		sources/set_sprites.c	\
		sources/paralax.c	\
		sources/move.c	\
		sources/init.c	\
		sources/main_menu.c	\
		lib/my_strcmp.c	\
		lib/my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
