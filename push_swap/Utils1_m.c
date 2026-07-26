/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:50:17 by librahim          #+#    #+#             */
/*   Updated: 2024/06/12 01:51:00 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkspace(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ')
			i++;
		else
			return (1);
	}
	if (arg[i] == '\0')
		return (0);
	else
		return (1);
}

char	*joineverything(char **argv, int argc)
{
	int		i;
	char	*res;

	res = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || !checkspace(argv[i]))
			return (free(res), NULL);
		res = ft_strjoin(res, argv[i]);
		res = ft_strjoin(res, " ");
		i++;
	}
	return (res);
}

int	checkargs(char *lstr)
{
	int	i;

	i = 0;
	while (lstr[i] != '\0')
	{
		if (lstr[i] == '+' || lstr[i] == '-')
		{
			if (!(i == 0) && lstr[i - 1] != ' ')
				return (0);
			if (!(lstr[i + 1] >= '0' && lstr[i + 1] <= '9'))
				return (0);
		}
		if (!((lstr[i] >= '0' && lstr[i] <= '9') || lstr[i] == ' '
				|| lstr[i] == '-' || lstr[i] == '+'))
			return (0);
		else
			i++;
	}
	return (1);
}

long	fetsh(char *res, int *j, int *flag)
{
	long	nb;

	nb = 0;
	if (res[(*j)])
	{
		if (ft_cust_atoi(res, &nb, j))
		{
			*flag = 0;
			return (0);
		}
	}
	return (nb);
}

void	rmlastspace(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	i--;
	if (str + i)
		str[i] = '\0';
}
