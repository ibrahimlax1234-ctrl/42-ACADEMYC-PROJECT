/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:42:49 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 15:29:51 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

char	*to_lower(char *s)
{
	int		i;
	char	*rslt;

	i = 0;
	rslt = safe_malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			rslt[i] = s[i] + 32;
			i++;
			continue ;
		}
		rslt[i] = s[i];
		i++;
	}
	rslt[i] = 0;
	return (rslt);
}

void	ft_exec_single_builtin(t_g *t)
{
	if (!ft_strcmp(to_lower(t->cmd_head->command[0]), "echo"))
		ft_echo(t->cmd_head, t);
	else if (!ft_strcmp(to_lower(t->cmd_head->command[0]), "pwd"))
		ft_pwd(t->cmd_head, t);
	else if (!ft_strcmp(t->cmd_head->command[0], "cd"))
		ft_cd(t->cmd_head, t->env, t);
	else if (!ft_strcmp(t->cmd_head->command[0], "exit"))
		ft_exit(t->cmd_head, t);
	else if (!ft_strcmp(to_lower(t->cmd_head->command[0]), "env"))
		ft_env(t->env, t);
	else if (!ft_strcmp(t->cmd_head->command[0], "export"))
		ft_export(t->cmd_head, t->env);
	else if (!ft_strcmp(t->cmd_head->command[0], "unset"))
		ft_unset(t->cmd_head, &(t->env));
}

void	handle_command_execution(t_cmd *cmd, t_env *env)
{
	if (cmd->command[0][0] == '/')
	{
		execve(cmd->command[0], cmd->command, env_2d(env));
		check_error(cmd->command[0]);
	}
	else if (cmd->command[0][0] == '.' && cmd->command[0][1] == '/')
		oc_starting_point_slash(cmd, env);
	else
		oc_bin_only(cmd, env);
}

void	fork_one_cmd(t_g *t)
{
	pid_t	pid;
	int		ex_st;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		if (!t->cmd_head->command[0])
			exit(0);
		handle_command_execution(t->cmd_head, t->env);
		ex_st = exit_status(0, 0);
		exit(ex_st);
	}
	else
	{
		waitpid(-1, &ex_st, 0);
		ex_st = WEXITSTATUS(ex_st);
		exit_status(ex_st, 1);
	}
}
