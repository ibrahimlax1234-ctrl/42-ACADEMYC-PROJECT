# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: librahim <librahim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 02:33:20 by librahim          #+#    #+#              #
#    Updated: 2024/07/31 03:20:25 by librahim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = Utils/ft_printf.c Utils/printf_utils1.c Utils/printf_utils2.c Utils/get_next_line_utils.c Utils/get_next_line.c Utils/ft_split.c data_init.c handling_keys.c map_parse.c more_map_parse.c setup_the_game.c Utils/other_utils.c main.c 
OBJ = $(SRC:.c=.o)
CC = cc
FLAG = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME): $(OBJ) common_header.h
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c common_header.h
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re