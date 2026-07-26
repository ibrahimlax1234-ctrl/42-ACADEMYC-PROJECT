/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:21:05 by librahim          #+#    #+#             */
/*   Updated: 2023/12/13 22:48:16 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
