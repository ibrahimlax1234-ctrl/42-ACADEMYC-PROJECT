/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:33:00 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/07 00:33:06 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	copy_quoted_string(char *str, char *result, int *k, int *c)
{
	char	quote;

	quote = str[*k];
	result[(*c)++] = quote;
	(*k)++;
	while (str[*k] && str[*k] != quote)
		result[(*c)++] = str[(*k)++];
	if (str[*k] == quote)
		result[(*c)++] = str[(*k)++];
	return (1);
}

int	copy_normal_characters(char *str, char *result, int *k, int *c)
{
	if (str[*k] == '$' && (str[*k + 1] == '"' || str[*k + 1] == '\''))
	{
		(*k)++;
		return (0);
	}
	result[(*c)++] = str[(*k)++];
	return (1);
}

int	handle_quote_size(char *str, int *k)
{
	int		size;
	char	quote;

	quote = str[*k];
	size = 1;
	(*k)++;
	while (str[*k] && str[*k] != quote)
	{
		size++;
		(*k)++;
	}
	if (str[*k] == quote)
	{
		size++;
		(*k)++;
	}
	return (size);
}

int	handle_normal_size(char *str, int *k)
{
	if (str[*k] == '$' && (str[*k + 1] == '"' || str[*k + 1] == '\''))
	{
		(*k)++;
		return (0);
	}
	(*k)++;
	return (1);
}
