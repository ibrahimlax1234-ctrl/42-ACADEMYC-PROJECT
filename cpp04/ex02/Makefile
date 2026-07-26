NAME	=	ex02


SRC		=	Animal.cpp \
			AAnimal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \
			Brain.cpp \
			main.cpp


OBJ		=	Animal.o \
			AAnimal.o \
			Cat.o \
			Dog.o \
			WrongAnimal.o \
			WrongCat.o \
			Brain.o \
			main.o

FLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

H		=	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \
			Brain.hpp \
			AAnimal.hpp

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