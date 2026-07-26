NAME	=	humans_and_weapons



SRC		=	main.cpp \
			HumanA.cpp \
			HumanB.cpp \
		 	Weapon.cpp \
			 


OBJ		=	main.o \
			HumanA.o \
			HumanB.o \
		 	Weapon.o \


CC		=	c++


FLAGS	=  -Wall -Werror -Wextra -std=c++98



all : $(NAME)



$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)



%.o : %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
		$(CC) $(FLAGS) -c $< -o $@



clean :
		rm -rf $(OBJ)


fclean : clean
		rm -rf $(NAME)


re : fclean all


.PHONY : all clean fclean re
