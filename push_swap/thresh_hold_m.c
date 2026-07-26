/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thresh_hold.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:14:35 by librahim          #+#    #+#             */
/*   Updated: 2024/06/24 20:07:44 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_to_b(t_s **a, t_s **b)
{
	int	vseuil;
	int	cseuil;

	vseuil = 0;
	cseuil = 16;
	if (lstsize(*a) >= 150)
		cseuil = 36;
	else if (lstsize(*a) >= 350)
		cseuil = 48;
	while (lstsize(*a) != 0)
	{
		if ((*a)->pos <= vseuil)
		{
			pb(a, b);
			vseuil++;
		}
		else if ((*a)->pos <= vseuil + cseuil)
		{
			pb(a, b);
			rotate(b, 'b');
			vseuil++;
		}
		else
			rotate(a, 'a');
	}
}

void	push_max_to_a(t_s **a, t_s **b)
{
	t_s	*cur;
	int	indx;
	int	pos_max;

	pos_max = lstsize(*b) - 1;
	cur = *b;
	indx = 0;
	while (cur && cur->pos != pos_max)
	{
		cur = cur->next;
		indx++;
	}
	if (indx <= lstsize(*b) / 2)
	{
		while (indx--)
			rotate(b, 'b');
	}
	else
	{
		indx = (lstsize(*b) - 1 + 1) - indx;
		while (indx--)
			rrotate(b, 'b');
	}
	pa(b, a);
}
