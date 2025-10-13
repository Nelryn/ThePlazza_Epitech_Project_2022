##
## EPITECH PROJECT, 2020
## main Makefile
## File description:
## root
##

SRC	=	main.cpp				\
		src/Ingredients.cpp		\
		src/Kitchen.cpp			\
		src/Reception.cpp		\
		src/Utils.cpp			\
		src/Clock.cpp			\
		src/ParseCommand.cpp	\
		src/Error.cpp

OBJ	=	$(SRC:.cpp=.o)

INC	=	-I include/

CFLAGS	=	-W -Wall -Wextra -Werror -std=c++20 -pthread

NAME=	plazza

FIFO=	fifo.pipe

all: $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf *~
	rm -rf src/*~
	rm -rf include/*~

fclean: clean
	rm -rf $(NAME)
	rm -f $(NAME_TEST)
	rm -rf $(OBJ)
	rm -rf $(FIFO)

re: fclean all