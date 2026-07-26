/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:11:10 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:09:41 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	split_quotes_calcul(char *s)
{
	int		count;
	char	quote;

	count = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '\"' || *s == '\'')
		{
			quote = *s++;
			while (*s && *s != quote)
				s++;
			if (*s)
				s++;
			count++;
		}
		else
		{
			while (*s && *s != '\'' && *s != '\"')
				s++;
			count++;
		}
	}
	return (count);
}

char	*process_quoted_section(t_split_quotes *split, char *s)
{
	split->quote = *s;
	split->splitted[split->i] = safe_malloc (sizeof(char) * (strlen(s) + 1));
	split->k = 0;
	split->splitted[split->i][split->k++] = split->quote;
	s++;
	while (*s && *s != split->quote)
		split->splitted[split->i][split->k++] = *s++;
	if (*s)
		split->splitted[split->i][split->k++] = split->quote;
	split->splitted[split->i][split->k] = '\0';
	split->i++;
	if (*s)
		s++;
	return (s);
}

char	*process_non_quoted_section(t_split_quotes *split, char *s)
{
	int		j;

	split->k = 0;
	while (s[split->k] && s[split->k] != '\'' && s[split->k] != '\"')
		split->k++;
	split->splitted[split->i] = safe_malloc(split->k + 1);
	j = 0;
	while (j < split->k && s[j] && s[j] != '\'' && s[j] != '\"')
	{
		split->splitted[split->i][j] = s[j];
		j++;
	}
	split->splitted[split->i][j] = '\0';
	s += j;
	split->i++;
	return (s);
}

void	initialize_split(t_split_quotes **split)
{
	*split = safe_malloc (sizeof(t_split_quotes));
	(*split)->count = 0;
	(*split)->splitted = NULL;
	(*split)->i = 0;
	(*split)->quote = 0;
}

char	**split_quotes(char *s)
{
	t_split_quotes	*split;

	initialize_split(&split);
	split->count = split_quotes_calcul(s);
	split->splitted = safe_malloc (sizeof(char *) * (split->count + 1));
	split->i = 0;
	if (split->count == 0)
		return (NULL);
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\"' || *s == '\'')
		{
			s = process_quoted_section(split, s);
		}
		else if (*s)
		{
			s = process_non_quoted_section(split, s);
		}
	}
	split->splitted[split->i] = NULL;
	return (split->splitted);
}
