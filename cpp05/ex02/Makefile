
NAME	=	ex02


SRC		=	main.cpp \
			AForm.cpp \
			Bureaucrat.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp



OBJ		=	main.o \
			AForm.o \
			Bureaucrat.o \
			PresidentialPardonForm.o \
			RobotomyRequestForm.o \
			ShrubberyCreationForm.o

H		=	AForm.hpp \
			Bureaucrat.hpp \
			PresidentialPardonForm.hpp \
			RobotomyRequestForm.hpp \
			ShrubberyCreationForm.hpp


CC		=	c++


FLAGS	=	-Wall -Werror -Wextra -std=c++98



all: $(NAME)



$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $(NAME)



%.o : %.cpp $(H)
	$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ)


fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re