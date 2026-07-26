/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:29:33 by librahim          #+#    #+#             */
/*   Updated: 2023/12/20 15:58:24 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_howmanywords(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 1;
	while (*s)
	{
		if (*s == c)
			in_word = 1;
		else if (in_word)
		{
			in_word = 0;
			count++;
		}
		s++;
	}
	return (count);
}

static int	wl(const char *s, char c)
{
	int	count;

	count = 0;
	while (*(s + count) != '\0' && *(s + count) != c)
		count++;
	return (count);
}

static void	free_memory(char **arr, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**fill(char **res, const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (*(s + j))
	{
		while (*(s + j) == c)
			j++;
		if (*(s + j))
		{
			res[i] = (char *)malloc(sizeof(char) * wl((s + j), c) + 1);
			if (!res[i])
			{
				free_memory(res, i);
				return (NULL);
			}
			ft_strlcpy(*(res + i), (s + j), wl((s + j), c) + 1);
			i++;
			j = j + wl((s + j), c);
		}
	}
	*(res + i) = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_howmanywords((char *)s, c) + 1));
	if (!res)
		return (NULL);
	res = fill(res, s, c, i);
	return (res);
}
