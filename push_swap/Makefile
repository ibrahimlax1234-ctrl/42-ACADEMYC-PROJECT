# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: librahim <librahim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 05:33:38 by librahim          #+#    #+#              #
#    Updated: 2024/07/06 01:12:14 by librahim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap





BONUS = checker






FL = -Wall -Wextra -Werror 







srcs = Utils0_m.c Utils1_m.c Utils2_m.c Utils3_m.c Utils4_m.c Utils5_m.c Utils6_m.c thresh_hold_m.c sort_small_m.c Main_m.c ft_printf_m.c PrfUtils1_m.c PrfUtils2_m.c








Bsrcs = utils0_bonus.c utils1_bonus.c utils2_bonus.c utils3_bonus.c utils4_bonus.c utils5_bonus.c utils6_bonus.c ft_printf_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c handl_actions_bonus.c Main_bonus.c PrfUtils1_bonus.c PrfUtils2_bonus.c







objs = $(srcs:.c=.o)







Bobjs = $(Bsrcs:.c=.o)






all : $(NAME)







bonus : $(BONUS)






$(NAME) : $(objs) 
			cc $(FL) $(objs) -o $(NAME)






$(BONUS) : $(Bobjs) 
		cc $(FL) $(Bobjs) -o $(BONUS)




%_bonus.o : %_bonus.c pushswap_bonus.h
		cc -c $(FL)  $< -o $@




%_m.o : %_m.c pushswap.h
		cc -c $(FL)  $< -o $@





clean :
	rm -f $(objs) $(Bobjs)





fclean : clean
		rm -f $(NAME) $(BONUS)





re : fclean all





.PHONY : all bonus clean fclean re