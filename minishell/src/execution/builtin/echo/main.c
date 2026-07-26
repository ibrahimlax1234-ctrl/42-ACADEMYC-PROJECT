/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:44:48 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/11 00:03:46 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

int	is_only_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		if (str[i] != 'n')
			return (0);
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

void	ft_print(t_cmd *cmd, int print_newline)
{
	int	i;

	i = 1;
	while (cmd->command[i])
	{
		if (!is_only_n(cmd->command[i]))
			break ;
		i++;
	}
	while (cmd->command[i])
	{
		ft_putstr_fd(cmd->command[i], STDOUT_FILENO);
		if (cmd->command[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (print_newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
}

void	ft_echo(t_cmd *cmd, t_g *t)
{
	int	i;
	int	print_newline;

	(void)t;
	i = 1;
	print_newline = 1;
	while (cmd->command[i] && is_only_n(cmd->command[i]))
	{
		print_newline = 0;
		i++;
	}
	ft_print(cmd, print_newline);
	exit_status(0, 1);
}
