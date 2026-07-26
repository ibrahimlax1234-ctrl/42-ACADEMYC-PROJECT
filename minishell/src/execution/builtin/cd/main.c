/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:06:47 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/10 22:20:43 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

void	replace_env(t_env *env, char *old_path)
{
	while (env)
	{
		if (!ft_strcmp(env->key, "OLDPWD"))
			env->data = ft_strdup(old_path);
		if (!ft_strcmp(env->key, "PWD"))
			env->data = ft_strdup(find_pwd());
		env = env->next;
	}
}

void	ft_cd(t_cmd *cmd, t_env *env, t_g *t)
{
	char	*old_path;

	(void)t;
	old_path = ft_strdup(find_pwd());
	if (!cmd->command[1])
	{
		if (chdir(get_from_env("HOME", &env)) == -1)
		{
			ft_putstr_fd("Minishell : cd: HOME not set\n", 2);
			exit_status(1, 1);
			return ;
		}
		replace_env(env, old_path);
		return ;
	}
	else if (chdir(cmd->command[1]) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(cmd->command[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit_status(1, 1);
		return ;
	}
	replace_env(env, old_path);
	exit_status(0, 1);
}
