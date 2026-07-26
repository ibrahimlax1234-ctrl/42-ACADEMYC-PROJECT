/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:50:57 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:51:16 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	handle_exit_status(char *s, t_expand *e)
{
	if (s[e->i] == '$' && s[e->i + 1] == '?')
	{
		e->status = ft_itoa(exit_status(0, 0));
		e->p = 0;
		e->i += 2;
		while (e->status[e->p])
			e->new_value[e->new_length++] = e->status[e->p++];
		return (1);
	}
	return (0);
}

int	skip_special_cases(char *s, t_expand *e)
{
	if ((s[e->i] == '$' && (ft_isdigit(s[e->i + 1]) || s[e->i + 1] == '*'
				|| s[e->i + 1] == '@')))
	{
		e->i += 2;
		return (1);
	}
	return (0);
}

int	is_valid_var_char(char c)
{
	return (ft_isalpha(c) || c == '_');
}
