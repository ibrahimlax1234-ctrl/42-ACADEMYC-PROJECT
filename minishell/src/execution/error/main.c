/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:17:14 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/11 01:35:59 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	print_error_and_exit(char *cmd, char *error_message, int exit_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(error_message, 2);
	exit_status(exit_code, 1);
}

void	check_file_or_directory_error(char *cmd)
{
	if ((cmd[0] == '/' && access(cmd, F_OK) == -1)
		|| (cmd[0] == '.' && cmd[1] == '/' && access(cmd, F_OK) == -1))
		print_error_and_exit(cmd, ": No such file or directory\n", 127);
	else if ((cmd[0] == '/' && is_directory(cmd))
		|| (cmd[0] == '.' && cmd[1] == '/' && is_directory(cmd)))
		print_error_and_exit(cmd, ": is a directory\n", 126);
	else if ((cmd[0] == '.' && cmd[1] == '/')
		&& access(cmd, F_OK) == 0 && access(cmd, X_OK) == -1)
		print_error_and_exit(cmd, ": Permission denied\n", 126);
	else
		print_error_and_exit(cmd, ": command not found\n", 127);
}

void	check_error(char *cmd)
{
	if (!ft_strcmp(cmd, "."))
	{
		print_error_and_exit(cmd, ": usage: . filename [arguments]\n", 127);
	}
	else if (!ft_strcmp(cmd, ".."))
	{
		print_error_and_exit(cmd, ": command not found\n", 127);
	}
	else
	{
		check_file_or_directory_error(cmd);
	}
}

int	is_directory(const char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	else
		return (0);
}
