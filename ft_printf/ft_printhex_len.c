/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:40:43 by librahim          #+#    #+#             */
/*   Updated: 2023/12/15 09:20:47 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
