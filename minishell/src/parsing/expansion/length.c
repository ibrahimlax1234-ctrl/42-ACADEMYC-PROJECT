/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:03:24 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/09 00:32:35 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	handle_exit_status_length(int *i)
{
	*i += 2;
	return (ft_strlen(ft_itoa(exit_status(0, 0))));
}

int	handle_underscore_length(int *i, t_env *env)
{
	*i += 2;
	return (ft_strlen(get_from_env("_", &env)));
}

int	handle_variable_length(int *i, char *s, t_env *env)
{
	int		j;
	int		k;
	char	*var;
	int		length;

	j = *i + 1;
	k = 0;
	while (ft_isalpha(s[j]))
		j++;
	var = safe_malloc (j - *i);
	while (*i + 1 < j)
		var[k++] = s[++(*i)];
	var[k] = '\0';
	length = ft_strlen(get_from_env(var, &env));
	(*i)++;
	return (length);
}

int	handle_other_length(int *i)
{
	(*i)++;
	return (1);
}

int	calculate_required_length(char *s, t_env *env)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] == '?')
			length += handle_exit_status_length(&i);
		else if (s[i] == '$' && s[i + 1] == '_')
			length += handle_underscore_length(&i, env);
		else if (s[i] == '$' && (ft_isdigit(s[i + 1])
				|| s[i + 1] == '*' || s[i + 1] == '@'))
			i += 2;
		else if (s[i] == '$' && ft_isalpha(s[i + 1]))
			length += handle_variable_length(&i, s, env);
		else
			length += handle_other_length(&i);
	}
	return (length);
}
