/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:45:22 by librahim          #+#    #+#             */
/*   Updated: 2024/07/03 01:31:49 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_small(t_s *stack_a, int *ptr)
{
	int	where;
	t_s	*cur;

	cur = stack_a;
	*ptr = stack_a->pos;
	while (stack_a)
	{
		if (stack_a->pos < (*ptr))
			(*ptr) = stack_a->pos;
		stack_a = stack_a->next;
	}
	where = 0;
	while (cur->pos != (*ptr))
	{
		cur = cur->next;
		where++;
	}
	return (where);
}

void	sort_three(t_s **s_a)
{
	int	a;
	int	b;
	int	c;

	a = (*s_a)->value;
	b = (*s_a)->next->value;
	c = (*s_a)->next->next->value;
	if (a < c && c < b)
	{
		swap(*s_a, 'a');
		rotate(s_a, 'a');
	}
	else if (b < a && a < c)
		swap(*s_a, 'a');
	else if (b < c && c < a)
		rotate(s_a, 'a');
	else if (c < a && a < b)
		rrotate(s_a, 'a');
	else if (c < b && b < a)
	{
		swap(*s_a, 'a');
		rrotate(s_a, 'a');
	}
}

void	push_five(t_s **stack_a, t_s **stack_b)
{
	int	index;
	int	size;
	int	where;

	size = lstsize(*stack_a);
	if (size == 2 && !is_stack_sorted(*stack_a))
		swap(*stack_a, 'a');
	if (is_stack_sorted(*stack_a))
		return ;
	while (lstsize(*stack_a) > 3)
	{
		where = find_small(*stack_a, &index);
		while ((*stack_a)->pos != index)
		{
			if (where < (lstsize(*stack_a) / 2))
				rotate(stack_a, 'a');
			else
				rrotate(stack_a, 'a');
		}
		pb(stack_a, stack_b);
	}
	if (!is_stack_sorted(*stack_a))
		sort_three(stack_a);
}
