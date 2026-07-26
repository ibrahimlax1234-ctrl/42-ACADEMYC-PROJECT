/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:50:28 by librahim          #+#    #+#             */
/*   Updated: 2024/06/12 02:35:56 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}

void	swap(t_s *lst, char c)
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
	if (c == 'b')
		ft_printf("sb\n");
	else if (c == 'a')
		ft_printf("sa\n");
	else
		return ;
}

void	ss(t_s *a, t_s *b)
{
	if ((!a && !b) || (lstsize(a) < 2 && lstsize(b) < 2))
		return ;
	if ((!a || lstsize(a) < 2) && b && lstsize(b) >= 2)
	{
		swap(b, 'u');
		ft_printf("ss\n");
		return ;
	}
	else if ((!b || lstsize(b) < 2) && a && lstsize(a) >= 2)
	{
		swap(a, 'u');
		ft_printf("ss\n");
		return ;
	}
	swap(b, 'u');
	swap(a, 'u');
	ft_printf("ss\n");
}

int	check_edges(long n)
{
	if (n > INT_MAX)
		return (1);
	if (n < INT_MIN)
		return (1);
	return (0);
}
