/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:54:06 by librahim          #+#    #+#             */
/*   Updated: 2024/02/18 01:16:34 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_b(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc_b(size_t blocks, size_t sizeblock)
{
	void	*res;
	size_t	i;

	if (!blocks || !sizeblock)
		return (NULL);
	if (blocks * sizeblock > __LONG_MAX__)
		return (NULL);
	res = malloc(blocks * sizeblock);
	if (!res)
		return (NULL);
	i = 0;
	while (i < blocks * sizeblock)
	{
		*((char *)res + i) = 0;
		i++;
	}
	return (res);
}

char	*ft_strchr_b(char *s, int c)
{
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = ft_strlen_b(s);
	if ((unsigned char)c == '\0')
		return ((char *)(s + k));
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_substr_b(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	res = NULL;
	if (!s)
		return (NULL);
	if (start >= ft_strlen_b(s))
		return (ft_strdup_b(""));
	if (len > ft_strlen_b(s) - start)
		res = (char *)malloc((ft_strlen_b(s) - start + 1));
	else if (len <= ft_strlen_b(s) - start)
		res = (char *)malloc((len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_b(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	res = malloc(ft_strlen_b(s1) + ft_strlen_b(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}
