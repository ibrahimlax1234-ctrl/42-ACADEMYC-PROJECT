/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:50:20 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 01:11:39 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_s	*newlist(int value)
{
	t_s	*res;

	res = (t_s *)malloc(sizeof(t_s));
	if (res)
	{
		res->value = value;
		res->next = NULL;
	}
	return (res);
}

int	lstsize(t_s *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	addfront(t_s **lst, t_s *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	addback(t_s **lst, t_s *new)
{
	t_s	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	duplicate_detection(t_s *h)
{
	t_s	*i;
	t_s	*j;
	int	count;

	i = h;
	while (i)
	{
		j = h;
		count = 0;
		while (j)
		{
			if ((i->value) == (j->value))
				count++;
			j = j->next;
		}
		if (count > 1)
			return (1);
		i = i->next;
	}
	return (0);
}
