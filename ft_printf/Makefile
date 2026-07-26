# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: librahim <librahim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 02:33:20 by librahim          #+#    #+#              #
#    Updated: 2024/02/09 18:21:54 by librahim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a



SRC = ft_printf.c ft_printhex_len.c ft_printupperhex_len.c ft_putchar_len.c ft_putnbr_len.c ft_putnbr_u_len.c ft_putstr_len.c ft_printadress_len.c



OBJ = ft_printf.o ft_printhex_len.o ft_printupperhex_len.o ft_putchar_len.o ft_putnbr_len.o ft_putnbr_u_len.o ft_putstr_len.o ft_printadress_len.o



CC = CC



FLAG = -Wall -Wextra -Werror



RM = rm -rf



all : $(NAME)




%.o : %.c ft_printf.h
	$(CC) $(FLAG) -c $< -o $@



$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)



clean:
	$(RM) $(OBJ)



fclean: clean
	$(RM) $(NAME)



re: fclean all




.PHONY : all clean fclean re