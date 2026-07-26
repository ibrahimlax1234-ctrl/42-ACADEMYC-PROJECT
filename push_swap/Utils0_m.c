/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:50:14 by librahim          #+#    #+#             */
/*   Updated: 2024/05/07 19:50:14 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	atoi_helper(char *str, int *j)
{
	while ((str[(*j)] >= 9 && str[(*j)] <= 13) || str[(*j)] == ' ')
		(*j)++;
	while (str[(*j)] == '0')
		(*j)++;
}

int	ft_cust_atoi(char *str, long *nbr, int *j)
{
	long	neg;
	long	res;

	res = 0;
	neg = 1;
	atoi_helper(str, j);
	if (str[(*j)] == '+' || str[(*j)] == '-')
	{
		if (str[(*j)++] == '-')
		{
			while (str[(*j)] == '0')
				(*j)++;
			neg = -1;
		}
	}
	while (str[(*j)] && str[(*j)] >= '0' && str[(*j)] <= '9')
	{
		res = res * 10 + str[(*j)] - 48;
		(*j)++;
		if (check_edges(res * neg))
			return (1);
	}
	*nbr = res * neg;
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}
