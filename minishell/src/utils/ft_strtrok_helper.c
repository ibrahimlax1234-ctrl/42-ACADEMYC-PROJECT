/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrok_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:11:43 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/15 15:12:02 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	skip_quote(const char *s, int i)
{
	char	quote;

	quote = s[i++];
	while (s[i] && s[i] != quote)
		i++;
	if (s[i])
		i++;
	return (i);
}

int	count_word(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == '\t'))
			i++;
		if (s[i] && s[i] != c && s[i] != '\t')
		{
			words++;
			while (s[i] && s[i] != c && s[i] != '\t')
			{
				if (s[i] == '\'' || s[i] == '\"')
					i = skip_quote(s, i);
				else
					i++;
			}
		}
	}
	return (words);
}
