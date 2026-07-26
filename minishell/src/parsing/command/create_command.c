/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:07:09 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 15:05:32 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	calculate_redirections(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j])
	{
		if (s[j] == '|' || s[j] == '<' || s[j] == '>')
		{
			i++;
			if (s[j] == '>' && s[j + 1] == '>')
				j++;
			if (s[j] == '<' && s[j + 1] == '<')
				j++;
		}
		j++;
	}
	return (i * 2);
}

int	check_syntax_command(t_cmd *cmd)
{
	while (cmd)
	{
		if (check_empty_command(cmd))
			return (1);
		if (check_trailing_operator(cmd->command))
			return (1);
		if (check_consecutive_operators(cmd->command))
			return (1);
		cmd = cmd->next;
	}
	return (0);
}

t_cmd	*fill_command(char *s)
{
	t_cmd	*command_lst;
	char	**pipe_commands;
	int		i;
	char	**command;
	t_cmd	*new_node;

	command_lst = NULL;
	pipe_commands = ft_strtrok(s, '|');
	i = 0;
	while (pipe_commands[i])
	{
		command = ft_strtrok(pipe_commands[i], ' ');
		new_node = ft_lstnew(command);
		ft_lstadd_back(&command_lst, new_node);
		i++;
	}
	return (command_lst);
}

char	*send_command(char *s)
{
	t_send_cmd	*cmd;

	cmd = safe_malloc(sizeof(t_send_cmd));
	cmd->j = 0;
	cmd->i = 0;
	cmd->str_len = ft_strlen(s) + calculate_redirections(s);
	cmd->str = safe_malloc(cmd->str_len + 1);
	if (!cmd->str)
		return (NULL);
	process_characters(s, cmd);
	cmd->str[cmd->j] = '\0';
	return (cmd->str);
}

t_cmd	*create_command(char *s, t_cmd *cmd)
{
	char	*str;

	str = send_command(s);
	if (!str || !*str)
		return (0);
	cmd = fill_command(str);
	if (check_syntax_command(cmd))
	{
		ft_putstr_fd("syntax error\n", 2);
		exit_status(258, 1);
		return (0);
	}
	return (cmd);
}
