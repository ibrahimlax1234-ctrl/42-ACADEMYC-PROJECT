# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: librahim <librahim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 19:43:32 by librahim          #+#    #+#              #
#    Updated: 2024/12/13 10:15:24 by librahim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC = data_init.c main.c the_dinner.c gettimeofday.c ftatoi.c launching_the_dinner.c the_dinner_ii.c monit.c

OBJ = data_init.o main.o the_dinner.o gettimeofday.o ftatol.o launching_the_dinner.o the_dinner_ii.o monit.o

HEADER = philo.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
