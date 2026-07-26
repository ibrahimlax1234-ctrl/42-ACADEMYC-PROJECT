/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:51:44 by librahim          #+#    #+#             */
/*   Updated: 2024/06/13 04:56:11 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	space_detector_at_the_end(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] == ' ')
		return (1);
	return (0);
}

void	indexing(t_s *stack_a, t_s *node)
{
	node->pos = 0;
	if (stack_a == NULL)
		return ;
	while (stack_a)
	{
		if (stack_a->value > node->value)
			stack_a->pos += 1;
		else
			node->pos += 1;
		stack_a = stack_a->next;
	}
}
