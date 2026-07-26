/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:41:03 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/20 13:22:27 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	exec_one(t_g *t)
{
	int	tmp_fd_in;
	int	tmp_fd_out;

	tmp_fd_in = dup(STDIN_FILENO);
	tmp_fd_out = dup(STDOUT_FILENO);
	dup2(t->cmd_head->fd_in, STDIN_FILENO);
	close(t->cmd_head->fd_in);
	dup2(t->cmd_head->fd_out, STDOUT_FILENO);
	close(t->cmd_head->fd_out);
	if (is_builtin(t->cmd_head->command[0]) == 1)
		ft_exec_single_builtin(t);
	else
		fork_one_cmd(t);
	dup2(tmp_fd_in, STDIN_FILENO);
	dup2(tmp_fd_out, STDOUT_FILENO);
	close(tmp_fd_in);
	close (tmp_fd_out);
}

void	close_all_files(t_g *t)
{
	t_cmd	*s;

	s = t->cmd_head;
	while (s)
	{
		close(s->fd_in);
		close(s->fd_out);
		s = s->next;
	}
}

int	**alloc_pipes(t_g *t)
{
	int	i;
	int	**res;

	i = -1;
	res = safe_malloc(sizeof(int *) * t->cmd_nbr);
	while (++i < (t->cmd_nbr - 1))
	{
		res[i] = safe_malloc(sizeof(int) * 2);
		if (!res[i])
		{
			perror("minishell");
			close_free_pipes(res, i);
			safe_free();
			exit(exit_status(0, 0));
		}
		if (pipe(res[i]) == -1)
		{
			perror("minishell");
			close_free_pipes(res, i);
			close_all_files(t);
			return (NULL);
		}
	}
	res[t->cmd_nbr - 1] = NULL;
	return (res);
}

void	launch_execution(t_g *t)
{
	if (t->cmd_nbr == 1)
		exec_one(t);
	else if (t->cmd_nbr > 1)
	{
		t->pipe_fds = alloc_pipes(t);
		if (t->pipe_fds == NULL)
			return ;
		handle_mult_pipes(t);
	}
}
