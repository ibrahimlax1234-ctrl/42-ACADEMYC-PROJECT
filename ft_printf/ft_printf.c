/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:25:34 by librahim          #+#    #+#             */
/*   Updated: 2024/02/09 18:23:21 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	man_conv(va_list a, char l, int *len)
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

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (write(1, "TEST", 0) < 0)
		return (-1);
	va_start(args, f);
	i = 0;
	len = 0;
	while (f[i] != '\0')
	{
		if (f[i] == '%')
		{
			if (f[i + 1] == '\0')
				break ;
			man_conv(args, f[i + 1], &len);
			i++;
		}
		else
			ft_putchar_len(*(f + i), &len);
		i++;
	}
	va_end(args);
	return (len);
}
