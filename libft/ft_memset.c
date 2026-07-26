/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:16:06 by librahim          #+#    #+#             */
/*   Updated: 2023/12/20 15:35:03 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;
	int	l;

	l = (int) n;
	if (n == 0)
		return (s);
	i = 0;
	while (i < l)
	{
		*((char *)s + i) = c;
		i++;
	}
	return (s);
}
