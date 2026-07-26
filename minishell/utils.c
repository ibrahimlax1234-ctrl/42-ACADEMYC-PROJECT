/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:48:54 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 15:13:21 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_null_commands(t_cmd *head)
{
	t_cmd	*tmp;
	int		i;
	int		j;

	tmp = head;
	while (tmp)
	{
		i = 0;
		while (tmp->command[i])
		{
			if (tmp->command[i][0] == 0)
			{
				j = i;
				while (tmp->command[j])
				{
					tmp->command[j] = tmp->command[j + 1];
					j++;
				}
			}
			else
				i++;
		}
		tmp = tmp->next;
	}
}

void	replace_char_2(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd)
	{
		while (cmd->command[i])
		{
			j = 0;
			while (cmd->command[i][j])
			{
				if (cmd->command[i][j] == 1)
					cmd->command[i][j] = '\'';
				else if (cmd->command[i][j] == 2)
					cmd->command[i][j] = '\"';
				j++;
			}
			i++;
		}
		cmd = cmd->next;
	}
}

void	rest_of_main_loop(t_g *t)
{
	update_env(t);
	ft_expansion(t->cmd_head, t->env);
	ft_redirection(t->cmd_head, t->env);
	remove_null_commands(t->cmd_head);
	t->cmd_nbr = cmd_nbr(t->cmd_head);
	replace_char_2(t->cmd_head);
	remove_redirection_quotes(t->cmd_head);
	launch_execution(t);
}

int	handle_input_line(t_g *t, struct termios *settings)
{
	t->rl_line = readline("minishell $ ");
	if (!t->rl_line)
		return (0);
	if (*(t->rl_line))
		add_history(t->rl_line);
	if (some_checks_before_parse(t->rl_line))
		return (free(t->rl_line), 1);
	t->cmd_head = create_command(t->rl_line, t->cmd_head);
	if (some_checks_after_parse(t->cmd_head))
	{
		free(t->rl_line);
		return (1);
	}
	free(t->rl_line);
	rest_of_main_loop(t);
	reset_data(t);
	tcsetattr(STDIN_FILENO, TCSANOW, settings);
	return (1);
}

t_g	*init_global_struct(int ac, char **av, char **env)
{
	t_g	*ret;

	(void)ac;
	(void)av;
	ret = safe_malloc(sizeof(t_g));
	if (!ret)
		return (perror("malloc"), NULL);
	ret->env = NULL;
	ret->pipe_fds = NULL;
	if (!*env)
		ret->env = create_empty_env();
	else
		ret->env = create_env(env);
	if (!ret->env)
		return (NULL);
	ret->cmd_head = NULL;
	return (ret);
}
