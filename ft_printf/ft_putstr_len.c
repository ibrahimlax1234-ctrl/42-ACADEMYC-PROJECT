/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:24:44 by librahim          #+#    #+#             */
/*   Updated: 2023/12/15 08:54:57 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
