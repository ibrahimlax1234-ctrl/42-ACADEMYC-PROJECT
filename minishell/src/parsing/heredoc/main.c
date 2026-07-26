/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:32:11 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/20 14:32:09 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	clear_command(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->command[i])
		cmd->command[i++] = NULL;
}

int	is_empty_input(char *input, t_cmd *cmd, int i)
{
	if (ft_strlen(input) == 0)
	{
		if (ft_strlen(remove_quotes(cmd->command[i + 1])) != 0)
			return (1);
		else
			return (1);
	}
	return (0);
}

char	*process_input(char *input, t_cmd *cmd, int i, t_env *env)
{
	if (!ft_strchr(cmd->command[i + 1], '\'')
		&& !ft_strchr(cmd->command[i + 1], '"'))
		input = ft_expand(input, env);
	return (input);
}

void	process_heredoc(t_cmd *cmd, int i, int fd, t_env *env)
{
	char	*input;
	char	*input_copy;

	signal(SIGINT, handle_sigint_heredoc);
	rl_catch_signals = 1;
	while (1)
	{
		input = readline(">");
		input_copy = ft_strdup(input);
		free(input);
		if (g_sig == 1)
		{
			clear_command(cmd);
			break ;
		}
		if (!input_copy)
			break ;
		if (ft_strcmp(input_copy, remove_quotes(cmd->command[i + 1])) == 0)
			break ;
		if (is_empty_input(input_copy, cmd, i))
			continue ;
		input = process_input(input_copy, cmd, i, env);
		write_input(fd, input);
	}
}

int	ft_heredoc(t_cmd *cmd, int i, int fd, t_env *env)
{
	char	*tmp;
	int		du;

	du = dup(0);
	tmp = process_quotes(cmd->command[i + 1]);
	if (!tmp)
		return (0);
	cmd->command[i + 1] = ft_strdup(tmp);
	process_heredoc(cmd, i, fd, env);
	rl_catch_signals = 0;
	if (g_sig == 1)
	{
		signal(SIGINT, handle_sigs);
		dup2(du, 0);
		close(fd);
		close(du);
		g_sig = 0;
		return (1);
	}
	close(du);
	g_sig = 0;
	return (0);
}
