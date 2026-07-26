# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: librahim <librahim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 16:45:01 by librahim          #+#    #+#              #
#    Updated: 2024/06/28 19:09:38 by librahim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server




NAME2 = client




FL = -Wall -Wextra -Werror




SERVSRC = ft_printf.c PrfUtils1.c PrfUtils2.c server.c




SERVOBJS = $(SERVSRC:.c=.o)





CLIESRC = client.c






CLIOBJS = $(CLIESRC:.c=.o)





all : $(NAME) $(NAME2)






$(NAME) : $(SERVOBJS) minitalk.h
		cc $(FL) $(SERVOBJS) -o $(NAME)





$(NAME2) : $(CLIOBJS) minitalk.h
		cc $(FL) $(CLIOBJS) -o $(NAME2)




%.o : %.c minitalk.h
		cc $(FL) -c $< -o $@







clean :
		rm -f $(CLIOBJS) $(SERVOBJS)





fclean : clean
		rm -f $(NAME) $(NAME2)



re : fclean all



.PHONY : clean fclean all re