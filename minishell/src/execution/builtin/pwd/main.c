/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:51:08 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/10 21:08:44 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

char	*find_pwd(void)
{
	char	cwd[PATH_MAX];
	char	*pwd;

	if (!getcwd(cwd, sizeof(cwd)))
		return (NULL);
	pwd = ft_strdup(cwd);
	return (pwd);
}

int	ft_pwd(t_cmd *cmd, t_g *t)
{
	char	*cwd;

	(void)t;
	(void)cmd;
	cwd = find_pwd();
	if (!cwd)
	{
		perror("pwd :");
		exit_status(1, 1);
		return (0);
	}
	ft_putstr_fd(cwd, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	exit_status(0, 1);
	return (0);
}
