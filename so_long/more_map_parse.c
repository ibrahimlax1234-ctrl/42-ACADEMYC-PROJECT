/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_map_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 04:54:42 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 01:28:10 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_header.h"

int	check_exit_fill_flood(char **s)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	check_if_rectang(char **s)
{
	int	i;
	int	length;

	i = 0;
	if (s[i])
		length = ft_strlen(s[i]);
	while (s[i])
	{
		if ((int)ft_strlen(s[i]) != length)
			return (1);
		i++;
	}
	return (0);
}

int	check_nl(char *l)
{
	int	i;

	i = 0;
	if (l[0] == '\n' || l[ft_strlen(l) - 1] == '\n')
		return (1);
	while (l[i] && l[i + 1])
	{
		if (l[i] == '\n' && l[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_if_map_enclosed(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[0][i])
	{
		if (s[0][i] != '1')
			return (1);
		i++;
	}
	while (s[j])
	{
		if (s[j][0] != '1' || s[j][i - 1] != '1')
			return (1);
		j++;
	}
	i = 0;
	while (s[j - 1][i])
	{
		if (s[j - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}
