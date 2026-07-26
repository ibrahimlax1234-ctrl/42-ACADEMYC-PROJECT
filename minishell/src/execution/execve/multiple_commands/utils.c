/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:32:02 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/19 12:04:06 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

void	ft_fork_execve(t_g *t, t_cmd *cmd_to_exec)
{
	if (!cmd_to_exec->command[0])
		return ;
	if (cmd_to_exec->command[0][0] == '/')
	{
		execve(cmd_to_exec->command[0], cmd_to_exec->command, env_2d(t->env));
		check_error(cmd_to_exec->command[0]);
	}
	else if (cmd_to_exec->command[0][0] == '.'
		&& cmd_to_exec->command[0][1] == '/')
		pipe_starting_point_slash(cmd_to_exec, t->env);
	else
		pipe_bin_only(cmd_to_exec, t->env);
}

void	handle_dup_fork_ii(t_g *t, t_cmd *c, int cmd_count)
{
	if (isatty(c->fd_in) == 1)
		dup2(t->pipe_fds[cmd_count - 1][0], STDIN_FILENO);
	else
		dup2(c->fd_in, STDIN_FILENO);
	if (isatty(c->fd_out) == 1)
		dup2(t->pipe_fds[cmd_count][1], STDOUT_FILENO);
	else
		dup2(c->fd_out, STDOUT_FILENO);
	close(c->fd_in);
	close(c->fd_out);
}

void	handle_dup_fork(t_g *t, t_cmd *c, int cmd_count)
{
	if (cmd_count == 0)
	{
		if (isatty(c->fd_out) == 1)
			dup2(t->pipe_fds[cmd_count][1], STDOUT_FILENO);
		else
			dup2(c->fd_out, STDOUT_FILENO);
		if (isatty(c->fd_in) == 0)
			dup2(c->fd_in, STDIN_FILENO);
		close(c->fd_in);
		close(c->fd_out);
	}
	else if (cmd_count == t->cmd_nbr - 1)
	{
		if (isatty(c->fd_in) == 1)
			dup2(t->pipe_fds[cmd_count - 1][0], STDIN_FILENO);
		else
			dup2(c->fd_in, STDIN_FILENO);
		if (isatty(c->fd_out) == 0)
			dup2(c->fd_out, STDOUT_FILENO);
		close(c->fd_in);
		close(c->fd_out);
	}
	else if (cmd_count > 0 && cmd_count < t->cmd_nbr - 1)
		handle_dup_fork_ii(t, c, cmd_count);
}

void	close_fds_helper(t_g *t)
{
	int	i;

	i = -1;
	while (++i < t->cmd_nbr - 1)
	{
		close(t->pipe_fds[i][0]);
		close(t->pipe_fds[i][1]);
	}
}

int	fork_and_exec(t_g *t, t_cmd *c, int cmd_count)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("minishell : fork ");
		close_fds_helper(t);
		return (1);
	}
	else if (pid == 0)
	{
		handle_dup_fork(t, c, cmd_count);
		close_fds_helper(t);
		if (!is_builtin(c->command[0]))
			ft_fork_execve(t, c);
		else
			ft_exec_fork_builtin(t, c);
		exit(exit_status(0, 0));
	}
	return (0);
}
