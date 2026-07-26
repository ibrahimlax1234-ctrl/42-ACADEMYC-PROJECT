NAME	=	megaphone

SRC		=	megaphone.cpp

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98 


all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)


fclean : clean


re : fclean all


.PHONY : all clean fclean re