/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrfUtils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:21:05 by librahim          #+#    #+#             */
/*   Updated: 2024/06/13 07:54:09 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putchar_len(int k, int *len)
{
	write (1, &k, 1);
	(*len)++;
}

static void	ft_putnull(int *len)
{
	char	*k;
	int		i;

	k = "(null)";
	i = 0;
	while (i < 6)
	{
		ft_putchar_len(k[i], len);
		i++;
	}
}

void	ft_putstr_len(char *s, int *len)
{
	if (s == NULL)
	{
		ft_putnull(len);
		return ;
	}
	while (*s)
	{
		ft_putchar_len(*s, len);
		s++;
	}
}

void	ft_putnbr_len(int nb, int *len)
{
	int		i;

	if (nb == -2147483648)
	{
		ft_putstr_len("-2147483648", len);
		return ;
	}
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_len('-', len);
	}
	if (nb < 10)
		ft_putchar_len(nb + '0', len);
	else
	{
		ft_putnbr_len(nb / 10, len);
		ft_putnbr_len(nb % 10, len);
	}
}

void	ft_putnbr_u_len(unsigned int nb, int *len)
{
	int	i;

	i = 0;
	if (nb < 10)
		ft_putchar_len(nb + '0', len);
	else
	{
		ft_putnbr_u_len(nb / 10, len);
		ft_putnbr_u_len(nb % 10, len);
	}
}
