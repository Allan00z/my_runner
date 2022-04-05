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
		sources/file_read.c	\
		sources/object_init.c	\
		sources/menu.c	\
		sources/victory_or_defeat.c	\
		sources/destroy.c	\
		sources/display.c	\
		sources/option_menu.c	\
		sources/others.c	\
		lib/my_put_nbr.c	\
		lib/my_strcmp.c	\
		lib/my_strlen.c	\
		lib/my_getnbr.c	\
		lib/my_get_size_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

tests_run:
	echo "Je teste"
