/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 04:36:00 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 01:28:03 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_header.h"

int	check_map_path(t_inf *t)
{
	int	i;

	i = 0;
	flood_fill(t, t->p_y, t->p_x);
	if (checkfilled_map_coll(t->filled_map)
		|| check_exit_fill_flood(t->filled_map))
		return (1);
	return (0);
}

int	checkfilled_map_coll(char **s)
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
			if (s[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count != 0)
		return (1);
	return (0);
}

int	check_collectibles_map(char **s)
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
			if (s[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
		return (-1);
	return (count);
}

int	check_exit_map(char **s)
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
	if (count > 1 || count == 0)
		return (1);
	return (0);
}

int	check_map_chars(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!(s[i][j] == '1' || s[i][j] == '0' || s[i][j] == 'E'
				|| s[i][j] == 'C' || s[i][j] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
