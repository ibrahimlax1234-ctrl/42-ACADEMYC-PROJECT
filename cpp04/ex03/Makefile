NAME	=	ex03


SRC		=	AMateria.cpp \
			Character.cpp \
			Cure.cpp \
			Ice.cpp \
			MateriaSource.cpp \
			main.cpp


OBJ		=	AMateria.o \
			Character.o \
			Cure.o \
			Ice.o \
			MateriaSource.o \
			main.o 


FLAGS	=	-Wall -Wextra -Werror -std=c++98 



H		=	AMateria.hpp \
			Character.hpp \
			Cure.hpp \
			ICharacter.hpp \
			Ice.hpp \
			MateriaSource.hpp


CC		=	c++



all: $(NAME)



$(NAME): $(OBJ) 
	$(CC)  $(OBJ) -o $(NAME)


%.o : %.cpp $(H)
	$(CC)  $(FLAGS) -c $< -o $@



clean:
	rm -rf $(OBJ)



fclean: clean
	rm -rf $(NAME)


re: fclean all


.PHONY: all clean fclean re