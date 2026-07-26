/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:58:29 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/20 15:32:29 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	check_expand(char **s, t_env *env)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_expand(*s, env);
	if ((*s)[i] != '\'')
	{
		*s = ft_strdup(str);
	}
}

void	handle_non_expansion_case(char **sp, char **s)
{
	int	j;

	j = 0;
	while (sp[j])
	{
		if (sp[j + 1] && !ft_strcmp(sp[j], "$")
			&& (sp[j + 1][0] == '"' || sp[j + 1][0] == '\''))
		{
			j++;
			continue ;
		}
		if (sp[j] && *sp[j])
			*s = ft_strjoin(*s, remove_quotes(sp[j]));
		j++;
	}
}

int	calculate_rows(char **array)
{
	int	count;

	count = 0;
	while (array[count])
	{
		count++;
	}
	return (count);
}

int	process(char **sp, t_env *env, char **cmd_segment)
{
	char	*s;
	int		j;
	char	*tmp;

	s = ft_strdup("");
	j = 0;
	while (sp[j])
	{
		if (sp[j + 1] && !ft_strcmp(sp[j], "$")
			&& (sp[j + 1][0] == '"' || sp[j + 1][0] == '\''))
		{
			j++;
			continue ;
		}
		tmp = ft_strdup(sp[j]);
		check_expand(&sp[j], env);
		j++;
	}
	handle_non_expansion_case(sp, &s);
	*cmd_segment = ft_strdup(s);
	return (0);
}

void	ft_expansion(t_cmd *cmd, t_env *env)
{
	int	i;

	while (cmd)
	{
		i = 0;
		while (cmd->command[i])
		{
			if (i > 0 && ft_strcmp(cmd->command[i - 1], "<<"))
			{
				if (process(split_quotes(cmd->command[i]),
						env, &(cmd->command[i])) == 1)
					return ;
			}
			else if (i == 0)
			{
				if (process(split_quotes(cmd->command[i]),
						env, &(cmd->command[i])) == 1)
					return ;
			}
			cmd->command[i] = ft_strdup(ft_strtrim(cmd->command[i], " "));
			i++;
		}
		cmd = cmd->next;
	}
}
