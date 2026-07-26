/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:12:39 by librahim          #+#    #+#             */
/*   Updated: 2023/12/10 02:49:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	size_t			i;
	unsigned char	k;

	k = (unsigned char)c;
	i = 0;
	ss = (unsigned char *)s;
	while (i < n && ss[i] != k)
		i++;
	if (i < n && ss[i] == k)
		return ((void *)(ss + i));
	return (NULL);
}
