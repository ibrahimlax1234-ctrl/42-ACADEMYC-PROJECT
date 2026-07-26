NAME = zombie_apocalypse

SRC		=	main.cpp


CC		=	c++



FLAGS	=  -Wall -Werror -Wextra -std=c++98



all: $(NAME)


$(NAME) :
	$(CC) $(FLAGS) $(SRC) -o $(NAME)


clean :
		rm -rf $(NAME)


fclean : clean


re : fclean all


.PHONY : all clean fclean re
