/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:53:04 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 01:11:05 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

char	*ftr_strdup(char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ftr_strlen(s);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_read(char *b, int fd, int *index)
{
	char	*reden;
	int		br;

	if (!b)
		b = ftr_strdup("");
	while (b)
	{
		reden = ftr_calloc((size_t)BUFFER_SIZE + 1, 1);
		if (!reden)
			return (free(b), NULL);
		br = read(fd, reden, BUFFER_SIZE);
		b = ftr_strjoin(b, reden);
		if (!b)
			return (free(reden), NULL);
		free(reden);
		if (!*b || ftr_strchr(b, '\n') || !br)
			break ;
	}
	*index = 0;
	while (b && b[(*index)] != '\0' && b[(*index)] != '\n')
		(*index)++;
	return (b);
}

char	*get_next_line(int fd)
{
	static char	*b;
	char		*l;
	int			i;
	char		*tmp;

	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0 || fd < 0)
		return (free(b), b = NULL, NULL);
	l = NULL;
	tmp = NULL;
	b = ft_read(b, fd, &i);
	if (!b)
		return (NULL);
	if (!*b)
		return (free(b), b = NULL, NULL);
	tmp = ftr_strdup(b);
	if (!tmp)
		return (free(b), b = NULL, NULL);
	l = ftr_substr(b, 0, i + 1);
	free(b);
	b = ftr_substr(tmp, i + 1, ftr_strlen(tmp));
	free(tmp);
	if (!b || !l || *l == '\0')
		return (free(l), free(b), b = NULL, NULL);
	return (l);
}
