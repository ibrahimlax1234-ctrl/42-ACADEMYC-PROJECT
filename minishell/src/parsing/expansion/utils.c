/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:02:16 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:51:26 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	extract_variable(char *s, t_expand *e)
{
	e->j = e->i + 1;
	while (is_valid_var_char(s[e->j]))
		e->j++;
	e->var = safe_malloc(e->j - e->i);
	e->k = 0;
	while (e->i + 1 < e->j)
		e->var[e->k++] = s[++e->i];
	e->var[e->k] = '\0';
}

void	handle_expansion_data(t_expand *e, char *s)
{
	int	in_quotes;

	in_quotes = (e->i > 0 && ((e->i - e->k - 1 >= 0
					&& s[e->i - e->k - 1] == '\'')
				|| (e->i - e->k - 1 >= 0 && s[e->i - e->k - 1] == '\"')));
	e->m = 0;
	while (e->m < e->data_length)
	{
		if (in_quotes && (e->data[e->m] == '\'' || e->data[e->m] == '\"'))
			e->new_value[e->new_length++] = e->data[e->m];
		e->new_value[e->new_length++] = e->data[e->m++];
	}
}

int	handle_variable_expansion(char *s, t_expand *e, t_env *env)
{
	if (s[e->i] == '$' && (s[e->i + 1] == ' ' || s[e->i + 1] == '\0'))
		return (0);
	if (s[e->i] == '$' && is_valid_var_char(s[e->i + 1]))
	{
		extract_variable(s, e);
		e->data = get_from_env(e->var, &env);
		if (e->data)
		{
			e->data_length = ft_strlen(e->data);
			handle_expansion_data(e, s);
		}
		e->i++;
		return (1);
	}
	return (0);
}

void	init_expand_struct(t_expand **e, int length)
{
	*e = safe_malloc (sizeof(t_expand));
	if (!(*e))
		return ;
	(*e)->i = 0;
	(*e)->new_length = 0;
	(*e)->new_value = safe_malloc (length + 1);
	if (!(*e)->new_value)
	{
		*e = NULL;
	}
}

char	*ft_expand(char *s, t_env *env)
{
	t_expand	*e;
	int			required_length;
	char		*result;

	required_length = calculate_required_length(s, env);
	init_expand_struct(&e, required_length);
	if (!e || !e->new_value)
		return (NULL);
	while (s[e->i])
	{
		if (handle_exit_status(s, e))
			continue ;
		if (skip_special_cases(s, e))
			continue ;
		if (handle_variable_expansion(s, e, env))
			continue ;
		e->new_value[e->new_length++] = s[e->i++];
	}
	e->new_value[e->new_length] = '\0';
	result = e->new_value;
	return (result);
}
