/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:19:02 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/11 01:35:07 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

char	**get_path(t_env *e, char *cmd)
{
	char	**path;

	(void)cmd;
	while (e)
	{
		if (e && !ft_strcmp(e->key, "PATH"))
			break ;
		e = e->next;
	}
	if (!e)
		return (NULL);
	path = ft_split(e->data, ':');
	return (path);
}

void	oc_starting_point_slash(t_cmd *cmd, t_env *env)
{
	if (access(cmd->command[0], F_OK | X_OK) == 0)
	{
		execve(cmd->command[0], cmd->command, env_2d(env));
		check_error(cmd->command[0]);
	}
	else
		check_error(cmd->command[0]);
}

static void	oc_error_path_msg(t_cmd *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd->command[0], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit_status(127, 1);
}

void	oc_bin_only(t_cmd *cmd, t_env *env)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	**path;

	i = 0;
	path = get_path(env, cmd->command[0]);
	if (!path)
	{
		oc_error_path_msg(cmd);
		return ;
	}
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd->command[0]);
		if (cmd->command[0][0] == 0)
			return ;
		if (access(tmp2, F_OK | X_OK) == 0)
			execve(tmp2, cmd->command, env_2d(env));
		i++;
	}
	exit_status(127, 1);
	check_error(cmd->command[0]);
}
