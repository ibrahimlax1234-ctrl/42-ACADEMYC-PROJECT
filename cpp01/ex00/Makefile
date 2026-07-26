
NAME 	=	zombie_apocalypse

SRC		=	main.cpp \
			newZombie.cpp \
			randomChump.cpp \
			Zombie.cpp


OBJ		=	main.o \
			newZombie.o \
			randomChump.o \
			Zombie.o


CC		=	c++


FLAGS	=  -Wall -Werror -Wextra -std=c++98



all : $(NAME)



$(NAME) : $(OBJ) Zombie.hpp
	$(CC) $(OBJ) -o $(NAME)



%.o : %.cpp Zombie.hpp
		$(CC) $(FLAGS) -c $< -o $@


clean :
		rm -rf $(OBJ)


fclean : clean
		rm -rf $(NAME)


re : fclean all


.PHONY : all clean fclean re
