/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:30:00 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/19 12:09:48 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

void	wait_for_child_processes(void)
{
	int	ex_st;

	while (waitpid(-1, &ex_st, 0) != -1)
		;
	ex_st = WEXITSTATUS(ex_st);
	exit_status(ex_st, 1);
}

void	handle_mult_pipes(t_g *t)
{
	int		cmd_count;
	t_cmd	*cmd_ptr;

	cmd_ptr = t->cmd_head;
	cmd_count = 0;
	while (cmd_count < t->cmd_nbr && cmd_ptr)
	{
		if (fork_and_exec(t, cmd_ptr, cmd_count))
		{
			iter_close_fds(t->cmd_head);
			break ;
		}
		if (exit_status(0, 0) == 130)
			return (iter_close_fds(t->cmd_head));
		close_command_fds(cmd_ptr);
		close_pipe_fds(t, cmd_count);
		cmd_ptr = cmd_ptr->next;
		cmd_count++;
	}
	wait_for_child_processes();
}

void	mc_error_path_msg(t_cmd *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd->command[0], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit_status(127, 1);
}

void	pipe_bin_only(t_cmd *cmd, t_env *env)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	**path;

	path = get_path(env, cmd->command[0]);
	if (!path)
	{
		mc_error_path_msg(cmd);
		return ;
	}
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd->command[0]);
		if (access(tmp2, F_OK | X_OK) == 0)
			execve(tmp2, cmd->command, env_2d(env));
		i++;
	}
	exit_status(127, 1);
	check_error(cmd->command[0]);
}
