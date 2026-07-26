NAME = ex01

SRC = main.cpp Serializer.cpp


OBJ = main.o Serializer.o


H = Data.hpp Serializer.hpp 


CC = c++ 


FLAGS = -Werror -Wextra -Wall -std=c++98


all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)


%.o: %.cpp $(H)
	$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)


re: fclean all