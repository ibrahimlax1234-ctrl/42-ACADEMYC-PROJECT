/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:54:06 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 01:11:09 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

size_t	ftr_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	*ftr_calloc(size_t blocks, size_t sizeblock)
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

char	*ftr_strchr(char *s, int c)
{
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = ftr_strlen(s);
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

char	*ftr_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	res = NULL;
	if (!s)
		return (NULL);
	if (start >= ftr_strlen(s))
		return (ftr_strdup(""));
	if (len > ftr_strlen(s) - start)
		res = (char *)malloc((ftr_strlen(s) - start + 1));
	else if (len <= ftr_strlen(s) - start)
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

char	*ftr_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	res = malloc(ftr_strlen(s1) + ftr_strlen(s2) + 1);
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
