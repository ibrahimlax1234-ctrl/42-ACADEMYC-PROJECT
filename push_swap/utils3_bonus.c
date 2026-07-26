/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:50:22 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 01:38:20 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_s	*fill(int argc, char **argv)
{
	char	*allargs;
	int		j;
	t_s		*res;
	t_s		*h;
	int		flag;

	flag = 1;
	res = NULL;
	allargs = parse(argc, argv);
	if (!allargs)
		return (NULL);
	j = 0;
	while (j < (ft_strlen(allargs)))
	{
		h = newlist(fetsh(allargs, &j, &flag));
		if (!flag)
			return (free(allargs), free_stack(h), free_stack(res), NULL);
		indexing(res, h);
		addback(&res, h);
	}
	free(allargs);
	if (duplicate_detection(res))
		return (free_stack(res), NULL);
	return (res);
}

void	rm_last_one(t_s **lst)
{
	t_s	*h;
	t_s	*fred;

	if (!lst || !(*lst))
		return ;
	h = *lst;
	while (h->next->next)
		h = h->next;
	fred = h->next;
	free(fred);
	h->next = NULL;
}

void	free_stack(t_s *s)
{
	t_s	*tmp;

	tmp = NULL;
	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
	}
}

int	is_stack_sorted(t_s *s)
{
	t_s	*current;
	int	last;

	if (s == NULL)
		return (0);
	last = s->pos;
	current = s;
	while (current != NULL)
	{
		if (last > current->pos)
			return (0);
		last = current->pos;
		current = current->next;
	}
	return (1);
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
