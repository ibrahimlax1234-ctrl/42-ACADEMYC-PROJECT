/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:24:52 by librahim          #+#    #+#             */
/*   Updated: 2023/12/11 21:56:44 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dl;
	size_t	sl;

	if (!dst && !size)
		return (ft_strlen(src));
	sl = ft_strlen(src);
	dl = ft_strlen(dst);
	i = 0;
	if (size == 0 || size <= dl)
		return (size + sl);
	while (i < size - dl - 1 && src[i] != '\0')
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}
