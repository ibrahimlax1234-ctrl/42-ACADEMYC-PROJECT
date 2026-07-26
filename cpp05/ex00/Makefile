
NAME	=	ex00


SRC		=	main.cpp \
			Bureaucrat.cpp


OBJ		=	main.o \
			Bureaucrat.o


CC		=	c++


FLAGS	=	-Wall -Werror -Wextra -std=c++98

H		=	Bureaucrat.hpp

all: $(NAME)



$(NAME): $(OBJ) 
	c++ $(OBJ) -o $(NAME)



%.o : %.cpp $(H)
	$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ)


fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re