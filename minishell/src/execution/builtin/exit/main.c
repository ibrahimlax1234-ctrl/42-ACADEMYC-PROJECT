/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:10:35 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/20 14:46:43 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

int	ft_is_too_big(char *str)
{
	char	*tmp;

	tmp = str;
	if (*tmp == '-')
		tmp++;
	if (ft_isnumber(str) == 1 && ft_strlen(tmp) < 19)
		return (0);
	if (ft_strlen(tmp) > 19)
		return (1);
	if (ft_isnumber(str) == 1 && ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	if (ft_isnumber(str) == 1 && str[0] && str[0] == '-' && ft_strcmp(str,
			"-9223372036854775808") > 0)
		return (1);
	return (0);
}

void	ft_error(char *arg, char *str, int error_code)
{
	ft_putstr_fd("exit\nminishell: exit: ", 2);
	if (error_code == 1)
		ft_putstr_fd(arg, 2);
	ft_putstr_fd(str, 2);
}

int	arglist_size(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int	check_exit_argument(t_cmd *cmd, char *str)
{
	str = ft_strtrim(remove_quotes(str), " ");
	if (!str || !*str || ft_strcmp(str, "\'\'") == 0
		|| ft_strcmp(str, "\"\"") == 0)
	{
		if (!str || !*str)
		{
			safe_free();
			exit(exit_status(0, 1));
		}
		safe_free();
		exit(exit_status(255, 1));
	}
	if (!ft_isnumber(str) || ft_is_too_big(str))
	{
		ft_error(str, ": numeric argument required\n", 1);
		safe_free();
		exit(exit_status(255, 1));
	}
	if (arglist_size(cmd->command) > 2)
	{
		ft_error(str, "too many arguments\n", 2);
		return (exit_status(1, 1), -1);
	}
	return (ft_atoll(str) % 256);
}

int	ft_exit(t_cmd *cmd, t_g *t)
{
	int		status;
	char	*str;

	status = 0;
	if (cmd->command[1])
	{
		str = cmd->command[1];
		status = check_exit_argument(cmd, str);
	}
	if (t->cmd_nbr == 1)
	{
		if (status == -1)
			return (0);
		safe_free();
		ft_putstr_fd("exit\n", 2);
		exit(exit_status(status, 1));
	}
	else
		exit_status(status, 1);
	return (0);
}
