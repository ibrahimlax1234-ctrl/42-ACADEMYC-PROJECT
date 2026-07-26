


NAME	=	robot_ex00



SRC		=	ClapTrap.cpp \
			main.cpp


OBJ		=	ClapTrap.o \
			main.o 


CC		=	c++


FLAGS	= 	-Wall -Werror -Wextra -std=c++98



all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)



%.o : %.cpp ClapTrap.hpp
	$(CC) $(FLAGS) -c $< -o $@



clean:
	rm -rf $(OBJ)


fclean: clean
	rm -rf $(NAME)


re: fclean all


.PHONY: all clean fclean re