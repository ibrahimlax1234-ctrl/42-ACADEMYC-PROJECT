/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:10:56 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/06 22:11:54 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static t_env	*new_env_node(char *env)
{
	t_env	*new;

	new = safe_malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_substr(env, 0, (ft_strchr(env, '=') - env));
	new->data = ft_strdup(ft_strchr(env, '=') + 1);
	new->next = NULL;
	return (new);
}

static void	add_sort_node(t_env **exp_list, t_env *new)
{
	t_env	*cur;
	t_env	*prev;

	if (!exp_list || !new)
		return ;
	if (*exp_list == NULL)
	{
		*exp_list = new;
		return ;
	}
	if (ft_strcmp((*exp_list)->key, new->key) > 0)
	{
		new->next = *exp_list;
		*exp_list = new;
		return ;
	}
	cur = *exp_list;
	prev = cur;
	while (cur != NULL && ft_strcmp(cur->key, new->key) < 0)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->next = cur;
}

t_env	*create_exp(char **env)
{
	t_env	*env_list;
	int		i;
	t_env	*new;

	i = 0;
	env_list = NULL;
	while (env[i])
	{
		new = new_env_node(env[i]);
		if (!new)
			return (NULL);
		add_sort_node(&env_list, new);
		i++;
	}
	return (env_list);
}
