CC		=	g++

NAME	=	./lexical_analyzer

SRC		=	main.cpp					\
			src/lexical_analyzer.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests:
	make -C test
	make run -C test

clean:
	rm -f $(NAME)
	make clean -C test

fclean: clean
	rm -f $(OBJ)
	make fclean -C test

re:	fclean all
	make re -C test

.PHONY:	all tests clean fclean re
