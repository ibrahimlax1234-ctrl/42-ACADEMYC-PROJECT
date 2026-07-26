/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:41:12 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 12:53:01 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	check_empty_command(t_cmd *cmd)
{
	if (!cmd->command[0])
		return (1);
	return (0);
}

int	check_trailing_operator(char **command)
{
	int	i;

	i = 0;
	while (command[i])
		i++;
	if (i > 0 && (!ft_strcmp(command[i - 1], ">")
			|| !ft_strcmp(command[i - 1], "<")
			|| !ft_strcmp(command[i - 1], "|")
			|| !ft_strcmp(command[i - 1], ">>")
			|| !ft_strcmp(command[i - 1], "<<")))
		return (1);
	return (0);
}

int	check_consecutive_operators(char **command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if ((!ft_strcmp(command[i], ">") || !ft_strcmp(command[i], "<")
				|| !ft_strcmp(command[i], ">>")
				|| !ft_strcmp(command[i], "<<")))
		{
			if (command[i + 1] && (!ft_strcmp(command[i + 1], ">")
					|| !ft_strcmp(command[i + 1], "<")
					|| !ft_strcmp(command[i + 1], "|")
					|| !ft_strcmp(command[i + 1], ">>")
					|| !ft_strcmp(command[i + 1], "<<")))
				return (1);
		}
		i++;
	}
	return (0);
}

int	more_checks(t_cmd *head)
{
	t_cmd	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp && (!ft_strcmp(tmp->command[0], "\"\"")
				|| !ft_strcmp(tmp->command[0], "''")))
		{
			ft_putstr_fd("minishell : : command not found\n", 2);
			exit_status(127, 1);
		}
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp && !ft_strcmp(tmp->command[0], "\"\"") && tmp->command[1] != NULL)
		return (1);
	return (0);
}

int	some_checks_after_parse(t_cmd *cmd)
{
	if (cmd == NULL)
		return (1);
	if (check_syntax_command(cmd))
	{
		ft_putstr_fd("minishell : syntax error\n", 2);
		exit_status(258, 1);
		return (1);
	}
	if ((!ft_strcmp(cmd->command[0], "\"\"")
			|| !ft_strcmp(cmd->command[0], "''")) && cmd_nbr(cmd) == 1)
	{
		ft_putstr_fd("minishell : : command not found\n", 2);
		exit_status(127, 1);
		return (1);
	}
	if (more_checks(cmd))
		return (1);
	return (0);
}
