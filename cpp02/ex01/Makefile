NAME 	=	fixed_ex01



SRC 	=	main.cpp \
			Fixed.cpp


OBJ 	=	main.o \
			Fixed.o


FLAGS 	=	-Wall -Wextra -Werror -std=c++98


CC		=	c++


all: $(NAME)



$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $(NAME)


%.o : %.cpp Fixed.hpp
		$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ)



fclean: clean
	rm -rf $(NAME)



re: fclean all



.PHONY: all clean fclean re