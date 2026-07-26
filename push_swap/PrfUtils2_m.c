/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrfUtils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:42:32 by librahim          #+#    #+#             */
/*   Updated: 2024/06/13 07:54:39 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_h(unsigned long l, int *len)
{
	char	*base;
	int		i;
	char	c[16];

	if (l == 0)
	{
		write (1, "0", 1);
		(*len)++;
		return ;
	}
	i = 0;
	base = "0123456789abcdef";
	while (l > 0)
	{
		c[i] = base[l % 16];
		l = l / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &c[i], 1);
		i--;
		(*len)++;
	}
}

void	ft_printadress_len(void *a, int *len)
{
	ft_putstr_len("0x", len);
	ft_h((unsigned long)a, len);
}

void	ft_printupperhex_len(unsigned int l, int *len)
{
	char	*base;
	int		i;
	char	c[16];

	if (l == 0)
	{
		write (1, "0", 1);
		(*len)++;
		return ;
	}
	i = 0;
	base = "0123456789ABCDEF";
	while (l > 0)
	{
		c[i] = base[l % 16];
		l = l / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &c[i], 1);
		i--;
		(*len)++;
	}
}

void	ft_printhex_len(unsigned int l, int *len)
{
	char	*base;
	int		i;
	char	c[16];

	if (l == 0)
	{
		write (1, "0", 1);
		(*len)++;
		return ;
	}
	i = 0;
	base = "0123456789abcdef";
	while (l > 0)
	{
		c[i] = base[l % 16];
		l = l / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &c[i], 1);
		i--;
		(*len)++;
	}
}
