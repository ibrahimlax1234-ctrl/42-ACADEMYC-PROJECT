/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:51:54 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/15 15:43:58 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	word_len(const char *s, char c)
{
	int		i;
	char	quote;

	i = 0;
	while (s[i] && s[i] != c && s[i] != '\t')
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			if (s[i])
				i++;
		}
		else
			i++;
	}
	return (i);
}

static int	copy_word(char *dest, const char *src, char c)
{
	int		i;
	int		k;
	char	quote;

	i = 0;
	k = 0;
	while (src[i] && (src[i] != c && src[i] != '\t'))
	{
		if (src[i] == '\'' || src[i] == '"')
		{
			quote = src[i++];
			dest[k++] = quote;
			while (src[i] && src[i] != quote)
				dest[k++] = src[i++];
			if (src[i])
				dest[k++] = src[i++];
		}
		else
			dest[k++] = src[i++];
	}
	dest[k] = '\0';
	return (i);
}

char	**ft_fill(char **str, char *s, char c)
{
	int		i;
	int		j;
	int		word_length;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] != 0 && (s[i] == c || s[i] == '\t'))
			i++;
		if (s[i] != 0)
		{
			word_length = word_len(&s[i], c);
			str[j] = safe_malloc(word_length + 1);
			if (!str[j])
				return (NULL);
			i += copy_word(str[j], &s[i], c);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_strtrok(char *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = safe_malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!str)
		return (NULL);
	str = ft_fill(str, s, c);
	return (str);
}
