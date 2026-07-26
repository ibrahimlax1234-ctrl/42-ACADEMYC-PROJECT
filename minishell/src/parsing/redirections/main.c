/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:20:48 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 15:01:45 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	handle_heredoc(t_cmd *cmd, int i, t_env *env, int *len)
{
	int	fd;
	int	j;

	if (i + 1 < *len && cmd->command[i + 1] && cmd->command[i + 1][0] != '\0')
	{
		fd = open("tmp.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (ft_heredoc(cmd, i, fd, env))
			return (300);
		close(fd);
		fd = open("tmp.txt", O_RDONLY, 0644);
		close(cmd->fd_in);
		(1) && (cmd->fd_in = fd, j = i);
		while (cmd->command[j + 2])
		{
			cmd->command[j] = cmd->command[j + 2];
			j++;
		}
		unlink("tmp.txt");
		cmd->command[j] = NULL;
		cmd->command[j + 1] = NULL;
		*len = 0;
		while (cmd->command[*len])
			(*len)++;
	}
	return (0);
}

int	handle_input_redirection(t_cmd *cmd, int i, int *len)
{
	if (i + 1 < *len && cmd->command[i + 1])
	{
		if (ft_input(cmd, i))
			return (1);
		*len = 0;
		while (cmd->command[*len])
			(*len)++;
	}
	return (0);
}

int	handle_output_redirection(t_cmd *cmd, int i, int *len)
{
	if (i + 1 < *len && cmd->command[i + 1])
	{
		if (ft_output(cmd, i))
			return (1);
		*len = 0;
		while (cmd->command[*len])
			(*len)++;
	}
	return (0);
}

int	handle_append_redirection(t_cmd *cmd, int i, int *len)
{
	if (i + 1 < *len && cmd->command[i + 1])
	{
		if (ft_append(cmd, i))
			return (1);
		*len = 0;
		while (cmd->command[*len])
			(*len)++;
	}
	return (0);
}

void	ft_redirection(t_cmd *cmd, t_env *env)
{
	int	i;
	int	len;

	(void)env;
	while (cmd)
	{
		len = 0;
		while (cmd->command[len])
			len++;
		i = 0;
		while (i < len)
		{
			if (ft_strcmp(cmd->command[i], "<<") == 0)
				handle_heredoc(cmd, i, env, &len);
			else if (ft_strcmp(cmd->command[i], "<") == 0)
				handle_input_redirection(cmd, i, &len);
			else if (ft_strcmp(cmd->command[i], ">") == 0)
				handle_output_redirection(cmd, i, &len);
			else if (ft_strcmp(cmd->command[i], ">>") == 0)
				handle_append_redirection(cmd, i, &len);
			else
				i++;
		}
		cmd = cmd->next;
	}
}
