/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:36:38 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 15:28:46 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

void	close_free_pipes(int **pipe_ends, int i)
{
	while (i > 0)
	{
		close(pipe_ends[i][0]);
		close(pipe_ends[i][1]);
		i--;
	}
}

void	ft_exec_fork_builtin(t_g *t, t_cmd *cmd_ptr)
{
	if (!ft_strcmp(to_lower(cmd_ptr->command[0]), "echo"))
		ft_echo(cmd_ptr, t);
	if (!ft_strcmp(to_lower(cmd_ptr->command[0]), "pwd"))
		ft_pwd(cmd_ptr, t);
	if (!ft_strcmp(cmd_ptr->command[0], "cd"))
		ft_cd(cmd_ptr, t->env, t);
	if (!ft_strcmp(cmd_ptr->command[0], "exit"))
		ft_exit(cmd_ptr, t);
	if (!ft_strcmp(to_lower(cmd_ptr->command[0]), "env"))
		ft_env(t->env, t);
	if (!ft_strcmp(cmd_ptr->command[0], "export"))
		ft_export(cmd_ptr, t->env);
	if (!ft_strcmp(cmd_ptr->command[0], "unset"))
		ft_unset(cmd_ptr, &(t->env));
}

void	iter_close_fds(t_cmd *h)
{
	t_cmd	*tmp;

	tmp = h;
	while (tmp)
	{
		close(tmp->fd_in);
		close(tmp->fd_out);
		tmp = tmp->next;
	}
}

void	close_pipe_fds(t_g *t, int cmd_count)
{
	if (cmd_count > 0)
		close(t->pipe_fds[cmd_count - 1][0]);
	if (cmd_count < t->cmd_nbr - 1)
		close(t->pipe_fds[cmd_count][1]);
}

void	close_command_fds(t_cmd *cmd_ptr)
{
	close(cmd_ptr->fd_in);
	close(cmd_ptr->fd_out);
}
