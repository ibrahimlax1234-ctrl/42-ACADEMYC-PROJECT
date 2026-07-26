/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:50:31 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 02:50:44 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common_header.h"

void	flood_fill(t_inf *d, int row, int col)
{
	if (row < 0 || col < 0 || col > d->width || row > d->height
		|| d->filled_map[row][col] == '1' || d->filled_map[row][col] == 'G'
		|| d->filled_map[row][col] == 'E')
		return ;
	d->filled_map[row][col] = 'G';
	flood_fill(d, row - 1, col);
	flood_fill(d, row + 1, col);
	flood_fill(d, row, col - 1);
	flood_fill(d, row, col + 1);
}

int	ft_dim_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_2dim_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
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
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
	free(s2);
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = n;
	i = ft_nbr_len(n);
	res = (char *)malloc(ft_nbr_len(n) + 1);
	if (!res)
		return (NULL);
	*(res + ft_nbr_len(n)) = '\0';
	if (n < 0)
		nb = -nb;
	while (i > 0)
	{
		*(res + i - 1) = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	if (n < 0)
		res[i] = '-';
	return (res);
}
