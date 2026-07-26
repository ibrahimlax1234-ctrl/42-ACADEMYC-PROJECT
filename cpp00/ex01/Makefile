NAME	=	Phonebook_Manager

SRC		=	main.cpp Contact.cpp PhoneBook.cpp 

OBJ		=	main.o Contact.o PhoneBook.o 


CC		=	c++


FLAG	= -Wall -Werror -Wextra -std=c++98


all : $(NAME)


$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)



%.o : %.cpp
		$(CC) $(FLAG) -c $< -o $@



clean :
		rm -rf $(OBJ)



fclean : clean
		rm -rf $(NAME)


re : fclean all


.PHONY : all clean fclean re