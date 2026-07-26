/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:11:56 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/20 14:56:39 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

void	replace_char(char **s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == '\'')
			(*s)[i] = 1;
		else if ((*s)[i] == '"')
			(*s)[i] = 2;
		i++;
	}
}

int	check_valid_id(char *key)
{
	int	i;

	if (!key || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (print_invalid_id_error(key));
	i = 0;
	while (key[i])
	{
		if ((!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && key[i] != '_')
			|| (key[i] == '+' && key[i + 1] != '='))
			return (print_invalid_id_error(key));
		i++;
	}
	return (0);
}

char	*find_data(char *s)
{
	int		i;
	int		len;
	char	*data;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] != '=')
		return (NULL);
	i++;
	len = 0;
	while (s[i + len])
		len++;
	data = safe_malloc(len + 1);
	if (!data)
		return (NULL);
	len = 0;
	while (s[i])
		data[len++] = s[i++];
	data[len] = '\0';
	return (data);
}

char	*find_key(char *s)
{
	int		i;
	char	*key;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '=' && s[i] != '+')
		i++;
	if (s[i] == '+' && s[i + 1] != '=')
	{
		print_invalid_id_error(s);
		return (NULL);
	}
	key = safe_malloc(i + 1);
	i = 0;
	while (s[i] && s[i] != '=' && s[i] != '+')
	{
		key[i] = s[i];
		i++;
	}
	key[i] = 0;
	return (key);
}

void	sort_list(t_env *env)
{
	int		swapped;
	t_env	*ptr;

	if (!env || !env->next)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = env;
		while (ptr->next)
		{
			if (ft_strcmp(ptr->key, ptr->next->key) > 0)
			{
				swap_env_data(ptr, ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
		}
	}
}
