/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:25:22 by librahim          #+#    #+#             */
/*   Updated: 2023/12/19 16:59:31 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
