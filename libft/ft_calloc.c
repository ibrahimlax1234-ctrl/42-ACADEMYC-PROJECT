/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:57:02 by librahim          #+#    #+#             */
/*   Updated: 2023/12/17 23:10:19 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t blocks, size_t sizeblock)
{
	void	*res;

	if (blocks * sizeblock > __LONG_MAX__)
		return (NULL);
	res = malloc(blocks * sizeblock);
	if (!res)
		return (NULL);
	ft_bzero(res, blocks * sizeblock);
	return (res);
}
