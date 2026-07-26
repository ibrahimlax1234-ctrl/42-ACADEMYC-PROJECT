/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:25:34 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 02:58:12 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common_header.h"

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

void	free_memory(char **arr, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_nbr_len(int n)
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
