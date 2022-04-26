CC		=	g++

NAME	=	tests

SRC		=	lexical_analyzer_tests.cpp	\
			specific_analyzer_tests.cpp	\
			../src/lexical_analyzer.cpp	\
			../src/token_analyzers.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -lcriterion -o $(NAME) $(OBJ)

run:
	./$(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re:	fclean all

.PHONY: all run clean fclean re
