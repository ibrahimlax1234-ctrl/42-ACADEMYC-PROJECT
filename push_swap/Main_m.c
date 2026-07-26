/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:05:42 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 23:08:09 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	p_err(void)
{
	write(2, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	t_s		*a;
	t_s		*b;

	if (argc == 1)
		return (0);
	b = NULL;
	a = fill(argc, argv);
	if (!a)
		return (p_err(), 1);
	if (is_stack_sorted(a))
		return (free_stack(a), 1);
	if (lstsize(a) < 6)
		push_five(&a, &b);
	else
		push_to_b(&a, &b);
	while (b)
		push_max_to_a(&a, &b);
	free_stack(a);
	return (0);
}
