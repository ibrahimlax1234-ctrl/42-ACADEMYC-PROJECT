
NAME = Harl


SRC = Harl.cpp main.cpp


OBJ = Harl.o main.o


CC = c++


FLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)


%.o : %.cpp Harl.hpp
		$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ)


fclean: clean
	rm -rf $(NAME)


re: fclean all
