/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:50:09 by librahim          #+#    #+#             */
/*   Updated: 2024/06/12 02:36:17 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_s **lst, char c)
{
	t_s	*tmp;
	t_s	*curr;

	tmp = *lst;
	curr = *lst;
	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	while (curr->next != NULL)
		curr = curr->next;
	*lst = (*lst)->next;
	curr->next = tmp;
	tmp->next = NULL;
	if (c == 'b')
		ft_printf("rb\n");
	else if (c == 'a')
		ft_printf("ra\n");
	else
		return ;
}

void	rrotate(t_s **lst, char c)
{
	t_s	*bflast;
	t_s	*last;

	if (!lst || *lst == NULL || lstsize(*lst) == 1)
		return ;
	last = *lst;
	bflast = *lst;
	while (last->next != NULL)
		last = last->next;
	while (bflast->next->next != NULL)
		bflast = bflast->next;
	last->next = *lst;
	*lst = last;
	bflast->next = NULL;
	if (c == 'b')
		ft_printf("rrb\n");
	else if (c == 'a')
		ft_printf("rra\n");
	else
		return ;
}

void	rr(t_s **a, t_s **b)
{
	if (!a || !b)
		return ;
	if ((!(*a) && !(*b)) || (lstsize(*a) < 2 && lstsize(*b) < 2))
		return ;
	if (!(*a) || lstsize(*a) < 2)
	{
		rotate(b, '\0');
		ft_printf("rr");
		return ;
	}
	if (!(*b) || lstsize(*b) < 2)
	{
		rotate(a, '\0');
		ft_printf("rr");
		return ;
	}
	rotate(a, '\0');
	rotate(b, '\0');
	ft_printf("rr");
}

void	rrr(t_s **a, t_s **b)
{
	if (!a || !b)
		return ;
	if ((!a && !b) || (lstsize(*a) < 2 && lstsize(*b) < 2))
		return ;
	if (!(*a) || lstsize(*a) < 2)
	{
		rrotate(b, '\0');
		ft_printf("rrr");
		return ;
	}
	if (!(*b) || lstsize(*b) < 2)
	{
		rrotate(a, '\0');
		ft_printf("rrr");
		return ;
	}
	rrotate(a, '\0');
	rrotate(b, '\0');
	ft_printf("rrr");
}
