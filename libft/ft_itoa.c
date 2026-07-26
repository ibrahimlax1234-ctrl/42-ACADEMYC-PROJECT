/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:02:44 by librahim          #+#    #+#             */
/*   Updated: 2023/12/20 16:25:46 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= (-1);
		res++;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
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
