NAME	=	zombie_apocalypse

 

SRC		=	main.cpp Zombie.cpp  zombieHorde.cpp 


OBJ		=	main.o Zombie.o  zombieHorde.o


CC		=	c++


FLAGS	=  -Wall -Werror -Wextra -std=c++98



all : $(NAME)



$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)



%.o : %.cpp Zombie.hpp
		$(CC) $(FLAGS) -c $< -o $@



clean :
		rm -rf $(OBJ)


fclean : clean
		rm -rf $(NAME)


re : fclean all


.PHONY : all clean fclean re
