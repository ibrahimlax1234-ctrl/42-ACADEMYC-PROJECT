/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:22:47 by librahim          #+#    #+#             */
/*   Updated: 2023/12/09 22:42:22 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		k;
	char	*f;

	f = (char *)s;
	k = ft_strlen(s);
	i = k;
	if ((char)c == '\0')
		return (f + k);
	while (i >= 0)
	{
		if (f[i] == (char)c)
			return (f + i);
		i--;
	}
	return (NULL);
}
