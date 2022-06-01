CC		=	g++

CXXFLAGS	=	-std=c++11

NAME	=	./analyzer

SRC		=	main.cpp					\
			src/lexical_analyzer.cpp	\
			src/token_analyzers.cpp		\
			src/utils.cpp				\
			src/syntax_analyzer.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)

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
