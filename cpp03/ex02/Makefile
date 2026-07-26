
NAME	=	robot_ex02



SRC		=	ClapTrap.cpp \
			ScavTrap.cpp \
			main.cpp \
			FragTrap.cpp 


OBJ		=	ClapTrap.o \
			ScavTrap.o \
			FragTrap.o \
			main.o


CC		=	c++


FLAGS	=	-Wall -Werror -Wextra -std=c++98






all: $(NAME)





$(NAME): $(OBJ)
	c++ $(OBJ) -o $(NAME)


%.o : %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re