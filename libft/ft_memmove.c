/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:01:34 by librahim          #+#    #+#             */
/*   Updated: 2023/12/09 21:37:08 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (d == s)
		return (dst);
	if (d > s)
	{
		i = n - 1;
		while (i >= 0)
		{
			*(d + i) = *(s + i);
			i--;
		}
	}
	if (d < s)
		ft_memcpy(dst, src, n);
	return (dst);
}
