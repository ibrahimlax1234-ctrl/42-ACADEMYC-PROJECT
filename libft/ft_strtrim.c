/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:21:09 by librahim          #+#    #+#             */
/*   Updated: 2023/12/09 21:21:09 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isit_in_set(const char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	st;
	size_t	e;
	char	*res;

	if (!s)
		return (NULL);
	st = 0;
	e = ft_strlen(s) - 1;
	while (s[st] && (isit_in_set(s[st], set) == 1))
		st++;
	while (s[e] && (isit_in_set(s[e], set) == 1))
		e--;
	res = ft_substr(s, st, (e - st + 1));
	return (res);
}
