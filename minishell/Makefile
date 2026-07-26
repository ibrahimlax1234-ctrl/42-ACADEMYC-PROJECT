# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: librahim <librahim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 21:29:05 by mkobaa            #+#    #+#              #
#    Updated: 2024/12/21 15:32:41 by librahim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC =	main.c \
		utils.c \
		utils_2.c \
		src/execution/env/env.c \
		src/execution/env/exp.c \
		src/parsing/syntax/before_parse.c \
		src/parsing/syntax/before_utils.c \
		src/safe_malloc/safe_malloc.c \
		src/signals/signals.c \
		src/utils/exit_status.c \
		src/utils/ft_atoi.c \
		src/utils/ft_isalnum.c \
		src/utils/ft_isalpha.c \
		src/utils/ft_isdigit.c \
		src/utils/ft_itoa.c \
		src/utils/ft_lst_addback.c \
		src/utils/ft_lstnew.c \
		src/utils/ft_lstsize.c \
		src/utils/ft_putchar_fd.c \
		src/utils/ft_putendl_fd.c \
		src/utils/ft_putstr_fd.c \
		src/utils/ft_split.c \
		src/utils/ft_strchr.c \
		src/utils/ft_strcmp.c \
		src/utils/ft_strdup.c \
		src/utils/ft_strjoin.c \
		src/utils/ft_strlen.c \
		src/utils/ft_strtrok.c \
		src/utils/ft_substr.c \
		src/parsing/command/create_command.c \
		src/parsing/command/create_utils.c \
		src/parsing/syntax/after_parse.c \
		src/execution/env/update_env.c \
		src/parsing/expansion/length.c \
		src/parsing/expansion/main.c \
		src/parsing/expansion/utils.c \
		src/parsing/quotes/handle_quotes.c \
		src/utils/remove_quotes.c \
		src/parsing/quotes/utils.c \
		src/parsing/redirections/main.c \
		src/parsing/redirections/utils.c\
		src/parsing/heredoc/main.c \
		src/parsing/heredoc/utils.c \
		src/utils/cmd_nbr.c \
		src/execution/launch/main.c \
		src/execution/launch/utils.c \
		src/execution/builtin/echo/main.c \
		src/execution/builtin/pwd/main.c \
		src/execution/builtin/cd/main.c \
		src/utils/ft_atoll.c \
		src/utils/ft_strtrim.c \
		src/utils/ft_isnumber.c \
		src/execution/builtin/exit/main.c \
		src/execution/builtin/env/main.c \
		src/execution/builtin/export/export.c \
		src/execution/builtin/unset/unset.c \
		src/execution/execve/one_command/main.c \
		src/execution/error/main.c \
		src/execution/execve/multiple_commands/utils.c \
		src/execution/execve/multiple_commands/utils2.c \
		src/execution/execve/multiple_commands/main.c \
		src/utils/ft_strlcpy.c \
		src/parsing/redirections/utils_2.c \
		src/execution/builtin/export/utils.c \
		src/execution/builtin/export/utils_2.c \
		src/utils/ft_strtrok_helper.c \
		src/parsing/quotes/utils_2.c \
		src/parsing/heredoc/utils_2.c \
		src/execution/execve/multiple_commands/utils_3.c \
		src/parsing/expansion/utils_3.c
		
		

OBJ = $(SRC:.c=.o)

READLINE_INC = -I$(shell brew --prefix readline)/include

READLINE_LIB = -L$(shell brew --prefix readline)/lib -lreadline

all: $(NAME)

%.o: %.c minishell.h
	$(CC) $(FLAGS) $(READLINE_INC) -c $< -o $@

$(NAME): $(OBJ) minishell.h
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(READLINE_LIB)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
