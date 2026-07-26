/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:22:51 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/10 23:24:32 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	ft_output(t_cmd *cmd, int i)
{
	int	fd;
	int	j;

	fd = open(cmd->command[i + 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		j = 0;
		while (cmd->command[j])
			cmd->command[j++] = NULL;
		perror("open");
		return (exit_status(1, 1), 1);
	}
	close(cmd->fd_out);
	(1) && (cmd->fd_out = fd, j = i);
	if (cmd->command[j + 1])
	{
		while (cmd->command[j + 2])
		{
			cmd->command[j] = cmd->command[j + 2];
			j++;
		}
		cmd->command[j] = NULL;
		cmd->command[j + 1] = NULL;
	}
	return (0);
}

int	ft_input(t_cmd *cmd, int i)
{
	int	fd;
	int	j;

	fd = open(cmd->command[i + 1], O_RDONLY, 0644);
	if (fd == -1)
	{
		j = 0;
		while (cmd->command[j])
			cmd->command[j++] = NULL;
		perror("open");
		return (exit_status(1, 1), 1);
	}
	close(cmd->fd_in);
	(1) && (cmd->fd_in = fd, j = i);
	if (cmd->command[j + 1])
	{
		while (cmd->command[j + 2])
		{
			cmd->command[j] = cmd->command[j + 2];
			j++;
		}
		cmd->command[j] = NULL;
		cmd->command[j + 1] = NULL;
	}
	return (0);
}

int	ft_append(t_cmd *cmd, int i)
{
	int	fd;
	int	j;

	fd = open(cmd->command[i + 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
	{
		j = 0;
		while (cmd->command[j])
			cmd->command[j++] = NULL;
		perror("open");
		return (exit_status(1, 1), 1);
	}
	close(cmd->fd_out);
	(1) && (cmd->fd_out = fd, j = i);
	if (cmd->command[j + 1])
	{
		while (cmd->command[j + 2])
		{
			cmd->command[j] = cmd->command[j + 2];
			j++;
		}
		cmd->command[j] = NULL;
		cmd->command[j + 1] = NULL;
	}
	return (0);
}
