/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:40:16 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/06 22:56:38 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	check_invalid_pipes(char *s, int *i)
{
	if (s[*i] == '|')
	{
		if (s[*i + 1] == '|')
			return (1);
	}
	return (0);
}

int	check_double_quotes(char *s, int *i)
{
	if (s[*i] == '\"')
	{
		(*i)++;
		while (s[*i] && s[*i] != '\"')
			(*i)++;
		if (s[*i] != '\"')
			return (1);
	}
	return (0);
}

int	check_single_quotes(char *s, int *i)
{
	if (s[*i] == '\'')
	{
		(*i)++;
		while (s[*i] && s[*i] != '\'')
			(*i)++;
		if (s[*i] != '\'')
			return (1);
	}
	return (0);
}
