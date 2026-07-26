/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:10:04 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 12:43:35 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

int	is_unset(char *s)
{
	int	i;

	i = 0;
	if (s[i] == 0)
		return (1);
	if (ft_isdigit(s[i]))
		return (0);
	if (!ft_isalpha(s[i]) && s[i] != '_')
		return (0);
	while (s[i] && s[i] != '=')
	{
		if (s[i] == '+' && s[i + 1] != '=')
			return (0);
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	ft_unset_variable(t_env **env, char *key)
{
	t_env	*prev;
	t_env	*current;

	current = *env;
	prev = NULL;
	while (current)
	{
		if (!ft_strcmp(current->key, key) && ft_strcmp(current->key, "_"))
		{
			if (!prev)
				*env = current->next;
			else
				prev->next = current->next;
			current->key = NULL;
			current->data = NULL;
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	ft_unset(t_cmd *cmd, t_env **env)
{
	int	i;

	i = 1;
	while (cmd->command[i])
	{
		if (!env || !*env || !cmd->command[i])
			return ;
		ft_unset_variable(env, cmd->command[i]);
		i++;
	}
}
