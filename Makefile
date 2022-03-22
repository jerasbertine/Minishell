##
## EPITECH PROJECT, 2021
## B-PSU-100-PAR-1-1-bsmyls-jeras.bertine
## File description:
## Makefile
##

SRC		=	src/main.c			\
			src/my_printf.c			\
			src/my_put_nbr.c		\
			src/my_put_nbr_pos.c		\
			src/my_putchar.c		\
			src/my_str_to_array.c		\
			src/my_strcmp.c			\
			src/my_strlen.c			\
			src/env_function.c		\
			src/pwd_function.c		\
			src/my_strcat.c			\
			src/cd_function.c		\
			src/setenv_function.c		\
			src/bin_function.c		\
			src/my_putstr.c

EXEC	=	mysh

CC		=	gcc

CPPFLAGS	=	-Wall -Wextra -I include

OBJ		=	$(SRC:.c=.o)

all:	$(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CPPFLAGS)
	@echo -e "\n\e[94mSuccessfully compiled\e[0m"

clean:
	rm -f src/*.o
	rm -f $(EXEC)

fclean: clean
	rm -f $(EXEC)

re:	fclean all
