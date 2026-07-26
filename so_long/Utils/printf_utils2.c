/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:42:32 by librahim          #+#    #+#             */
/*   Updated: 2024/07/28 03:29:16 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common_header.h"

void	man_conv(va_list a, char l, int *len)
{
	if (l == 'd' || l == 'i')
		ft_putnbr_len(va_arg(a, int), len);
	else if (l == 'c')
		ft_putchar_len(va_arg(a, int), len);
	else if (l == 's')
		ft_putstr_len(va_arg(a, char *), len);
	else if (l == 'u')
		ft_putnbr_u_len(va_arg(a, unsigned int), len);
	else if (l == '%')
		ft_putchar_len('%', len);
	else if (l == 'p')
		ft_printadress_len(va_arg(a, void *), len);
	else if (l == 'x')
		ft_printhex_len(va_arg(a, unsigned int), len);
	else if (l == 'X')
		ft_printupperhex_len(va_arg(a, unsigned long), len);
	else
		ft_putchar_len(l, len);
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
