/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:50:09 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 01:11:48 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	rotate(t_s **lst)
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
}

void	rrotate(t_s **lst)
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
}

void	rr(t_s **a, t_s **b)
{
	if (!a || !b)
		return ;
	if ((!(*a) && !(*b)) || (lstsize(*a) < 2 && lstsize(*b) < 2))
		return ;
	if (!(*a) || lstsize(*a) < 2)
	{
		rotate(b);
		return ;
	}
	if (!(*b) || lstsize(*b) < 2)
	{
		rotate(a);
		return ;
	}
	rotate(a);
	rotate(b);
}

void	rrr(t_s **a, t_s **b)
{
	if (!a || !b)
		return ;
	if ((!a && !b) || (lstsize(*a) < 2 && lstsize(*b) < 2))
		return ;
	if (!(*a) || lstsize(*a) < 2)
	{
		rrotate(b);
		return ;
	}
	if (!(*b) || lstsize(*b) < 2)
	{
		rrotate(a);
		return ;
	}
	rrotate(a);
	rrotate(b);
}

int	space_detector_at_the_end(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] == ' ')
		return (1);
	return (0);
}
