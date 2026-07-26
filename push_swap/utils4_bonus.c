/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:50:28 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 01:11:45 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	pa(t_s **b, t_s **a)
{
	t_s	*tmp;

	if (!a || !b)
		return ;
	if (!(*b) || !lstsize(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	addfront(a, tmp);
}

void	pb(t_s **a, t_s **b)
{
	t_s	*tmp;

	if (!a || !b)
		return ;
	if (!(*a) || !lstsize(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	addfront(b, tmp);
}

void	swap(t_s *lst)
{
	int		tmp;
	int		postmp;

	if (!lst || lstsize(lst) < 2)
		return ;
	tmp = lst->value;
	postmp = lst->pos;
	lst->value = lst->next->value;
	lst->pos = lst->next->pos;
	lst->next->value = tmp;
	lst->next->pos = postmp;
}

void	ss(t_s *a, t_s *b)
{
	if ((!a && !b) || (lstsize(a) < 2 && lstsize(b) < 2))
		return ;
	if ((!a || lstsize(a) < 2) && b && lstsize(b) >= 2)
	{
		swap(b);
		return ;
	}
	else if ((!b || lstsize(b) < 2) && a && lstsize(a) >= 2)
	{
		swap(a);
		return ;
	}
	swap(b);
	swap(a);
}

int	check_edges(long n)
{
	if (n > INT_MAX)
		return (1);
	if (n < INT_MIN)
		return (1);
	return (0);
}
