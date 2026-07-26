/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:25:39 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/20 15:55:34 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	is_quoted_string(char *str)
{
	if (!str)
		return (0);
	if ((str[0] == '\'' && str[ft_strlen(str) - 1] == '\'')
		|| (str[0] == '\"' && str[ft_strlen(str) - 1] == '\"'))
		return (1);
	return (0);
}

void	remove_redirection_quotes(t_cmd *cmd)
{
	int		i;
	char	*temp;

	i = 0;
	while (cmd->command[i])
	{
		if ((cmd->command[i][0] == '\'' || cmd->command[i][0] == '\"'))
		{
			if (is_redirection_operator(cmd->command[i], 1))
			{
				temp = remove_quotes_2(cmd->command[i]);
				cmd->command[i] = ft_strdup(temp);
			}
		}
		i++;
	}
}

int	handle_redirection(t_cmd *cmd, t_env *env, int i, int *len)
{
	if ((cmd->command[i + 1] && (!ft_strcmp(cmd->command[i], ">")
				|| !ft_strcmp(cmd->command[i], "<")
				|| !ft_strcmp(cmd->command[i], ">>")
				|| !ft_strcmp(cmd->command[i], "<<")))
		&& cmd->command[i + 1][0] == 0)
		return (ft_putstr_fd("minishell : ambiguous redirect\n", 2), 300);
	if (ft_strcmp(cmd->command[i], "<<") == 0)
	{
		if (handle_heredoc(cmd, i, env, len))
			return (300);
	}
	else if (ft_strcmp(cmd->command[i], "<") == 0)
	{
		if (handle_input_redirection(cmd, i, len))
			return (300);
	}
	else if (ft_strcmp(cmd->command[i], ">") == 0)
	{
		if (handle_output_redirection(cmd, i, len))
			return (300);
	}
	else if (ft_strcmp(cmd->command[i], ">>") == 0)
		if (handle_append_redirection(cmd, i, len))
			return (300);
	return (0);
}

int	process_command(t_cmd *cmd, t_env *env)
{
	int	i;
	int	len;
	int	status;

	len = 0;
	while (cmd->command[len])
		len++;
	i = 0;
	while (i < len)
	{
		if (!is_quoted_string(cmd->command[i]))
		{
			status = handle_redirection(cmd, env, i, &len);
			if (status != 0)
				return (status);
		}
		i++;
	}
	return (0);
}
