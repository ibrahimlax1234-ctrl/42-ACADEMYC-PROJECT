/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:24:30 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/06 23:02:16 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_arglen(char **arg)
{
	int	i;

	i = 0;
	if (!arg || !*arg)
		return (0);
	while (arg[i])
		i++;
	return (i);
}
