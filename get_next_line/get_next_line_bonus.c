/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:53:04 by librahim          #+#    #+#             */
/*   Updated: 2024/02/18 01:19:37 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup_b(char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen_b(s);
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

char	*ft_read_b(char *b, int fd, int *index)
{
	char	*reden;
	int		br;

	if (!b)
		b = ft_strdup_b("");
	while (b)
	{
		reden = ft_calloc_b((size_t)BUFFER_SIZE + 1, 1);
		if (!reden)
			return (free(b), NULL);
		br = read(fd, reden, BUFFER_SIZE);
		b = ft_strjoin_b(b, reden);
		if (!b)
			return (free(reden), NULL);
		free(reden);
		if (!*b || ft_strchr_b(b, '\n') || !br)
			break ;
	}
	*index = 0;
	while (b && b[(*index)] != '\0' && b[(*index)] != '\n')
		(*index)++;
	return (b);
}

char	*get_next_line(int fd)
{
	static char	*b[OPEN_MAX];
	char		*l;
	int			i;
	char		*tmp;

	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0 || fd < 0)
		return (free(b[fd]), b[fd] = NULL, NULL);
	l = NULL;
	tmp = NULL;
	b[fd] = ft_read_b(b[fd], fd, &i);
	if (!b[fd])
		return (NULL);
	if (!*b[fd])
		return (free(b[fd]), b[fd] = NULL, NULL);
	tmp = ft_strdup_b(b[fd]);
	if (!tmp)
		return (free(b[fd]), b[fd] = NULL, NULL);
	l = ft_substr_b(b[fd], 0, i + 1);
	free(b[fd]);
	b[fd] = ft_substr_b(tmp, i + 1, ft_strlen_b(tmp));
	free(tmp);
	if (!b[fd] || !l || *l == '\0')
		return (free(l), free(b[fd]), b[fd] = NULL, NULL);
	return (l);
}
