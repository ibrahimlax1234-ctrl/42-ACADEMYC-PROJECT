/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:01:29 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/06 22:08:21 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*find_env_name(char **envp, int i)
{
	int		j;
	char	*name;

	j = 0;
	while (envp[i][j] != '=')
		j++;
	name = safe_malloc(j + 1);
	if (!name)
		return (NULL);
	j = 0;
	while (envp[i][j] != '=')
	{
		name[j] = envp[i][j];
		j++;
	}
	name[j] = 0;
	i++;
	return (name);
}

char	*find_env_data(char **envp, int i)
{
	int		j;
	int		k;
	int		y;
	char	*data;

	(1) && (j = 0, k = 0, y = 0);
	while (envp[i][j] != '=')
		j++;
	j++;
	y = j;
	while (envp[i][j])
	{
		k++;
		j++;
	}
	data = safe_malloc(k + 1);
	if (!data)
		return (NULL);
	k = 0;
	while (envp[i][y])
		data[k++] = envp[i][y++];
	data[k] = 0;
	return (data);
}

char	*get_from_env(char *var, t_env **env)
{
	t_env	*head;

	head = *env;
	if (!env || !*env)
		return (NULL);
	while (head)
	{
		if (ft_strcmp(var, head->key) == 0)
			break ;
		head = head->next;
	}
	if (head)
		return (head->data);
	else
		return (NULL);
}

t_env	*create_env(char **envp)
{
	int		i;
	char	*name;
	char	*data;
	t_env	*new_node;
	t_env	*head;

	(1) && (i = 0, head = NULL);
	while (envp[i])
	{
		name = find_env_name(envp, i);
		if (ft_strcmp(name, "SHLVL") == 0)
		{
			data = ft_itoa(ft_atoi(find_env_data(envp, i)) + 1);
			if (data)
				new_node = ft_lstnew_env(name, data);
			ft_lstadd_back_env(&head, new_node);
			i++;
			continue ;
		}
		data = find_env_data(envp, i);
		new_node = ft_lstnew_env(name, data);
		ft_lstadd_back_env(&head, new_node);
		i++;
	}
	return (head);
}

char	**env_2d(t_env *env)
{
	int		i;
	char	**env_2d;
	t_env	*head;

	i = ft_lstsize_env(env);
	env_2d = safe_malloc(sizeof(char *) * (i + 1));
	if (!env_2d)
		return (NULL);
	head = env;
	i = 0;
	while (head)
	{
		env_2d[i] = ft_strjoin(head->key, "=");
		env_2d[i] = ft_strjoin(env_2d[i], head->data);
		head = head->next;
		i++;
	}
	env_2d[i] = NULL;
	return (env_2d);
}
