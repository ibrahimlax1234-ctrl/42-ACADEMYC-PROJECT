NAME = ex02

SRC = Base.cpp main.cpp functions.cpp


OBJ = Base.o main.o functions.o


H = A.hpp B.hpp C.hpp Base.hpp


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