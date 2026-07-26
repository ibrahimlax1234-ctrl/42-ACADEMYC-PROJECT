/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:30:09 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 09:42:30 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

void	print_exported_env(t_env *env)
{
	t_env	*sorted;
	t_env	*node;

	sorted = NULL;
	while (env)
	{
		node = ft_lstnew_env(env->key, env->data);
		ft_lstadd_back_env(&sorted, node);
		env = env->next;
	}
	sort_list(sorted);
	while (sorted)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(sorted->key, 1);
		ft_putstr_fd("=\"", 1);
		if (sorted->data)
			ft_putstr_fd(sorted->data, 1);
		ft_putstr_fd("\"\n", 1);
		sorted = sorted->next;
	}
}

int	check_if_exist( char *s, t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(s, env->key))
			return (1);
		env = env->next;
	}
	return (0);
}

void	handle_exist(char *s, t_env *env)
{
	int		i;
	char	*temp;

	while (ft_strcmp(find_key(s), env->key))
		env = env->next;
	i = 0;
	while (s[i] && s[i] != '=' && s[i] != '+')
		i++;
	if (find_data(s) && s[i] != '+')
	{
		env->data = ft_strdup(find_data(s));
	}
	else if (find_data(s) && s[i] == '+')
	{
		temp = ft_strjoin(env->data, find_data(s));
		env->data = ft_strdup(temp);
	}
}

void	handle_non_exist(char *s, t_env *env)
{
	t_env	*tmp;

	if (find_data(s))
	{
		tmp = ft_lstnew_env(find_key(s), find_data(s));
		ft_lstadd_back_env(&env, tmp);
	}
	else
	{
		tmp = ft_lstnew_env(find_key(s), ft_strdup("\2"));
		ft_lstadd_back_env(&env, tmp);
	}
}

void	ft_export(t_cmd *cmd, t_env *env)
{
	int		i;
	char	*key;

	i = 1;
	if (!cmd->command[i])
		return (print_exported_env(env));
	while (cmd->command[i])
	{
		replace_char(&cmd->command[i]);
		key = find_key(cmd->command[i]);
		if (!key || check_valid_id(key) || !ft_strcmp(cmd->command[i], "="))
		{
			ft_putstr_fd("export: not a valid identifier\n", 2);
			exit_status(1, 1);
			i++;
			continue ;
		}
		if (check_if_exist(key, env))
			handle_exist(cmd->command[i], env);
		else
			handle_non_exist(cmd->command[i], env);
		i++;
	}
}
