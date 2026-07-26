/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:42:34 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:44:48 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

void	pipe_starting_point_slash(t_cmd *cmd, t_env *env)
{
	if (access(cmd->command[0], F_OK | X_OK) == 0)
	{
		execve(cmd->command[0], cmd->command, env_2d(env));
		check_error(cmd->command[0]);
	}
	else
		check_error(cmd->command[0]);
}
