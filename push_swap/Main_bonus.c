/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:05:42 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 23:11:49 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	p_err(void)
{
	write(2, "Error\n", 6);
}

int	checkit(char *s, t_s **a, t_s **b)
{
	if (!ft_strncmp(s, "sa\n", 3) || !ft_strncmp(s, "sb\n", 3)
		|| !ft_strncmp(s, "ss\n", 3))
		return (handle_swap(s, a, b), 1);
	else if (!ft_strncmp(s, "ra\n", 3) || !ft_strncmp(s, "rb\n", 3)
		|| !ft_strncmp(s, "rr\n", 3))
		return (handle_rot(s, a, b), 1);
	else if (!ft_strncmp(s, "rra\n", 4) || !ft_strncmp(s, "rrb\n", 4)
		| !ft_strncmp(s, "rrr\n", 4))
		return (handle_rrot(s, a, b), 1);
	else if (!ft_strncmp(s, "pa\n", 3) || !ft_strncmp(s, "pb\n", 3))
		return (handle_push(s, a, b), 1);
	else
		return (0);
}

void	read_check(t_s **a, t_s **b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		if (!checkit(s, a, b))
		{
			free_stack(*a);
			free_stack(*b);
			free(s);
			p_err();
			exit(1);
		}
		free(s);
		s = get_next_line(0);
	}
}

int	last_check(t_s **a, t_s **b)
{
	if (!lstsize(*b) && is_stack_sorted(*a))
	{
		free_stack(*a);
		free_stack(*b);
		return (1);
	}
	else
	{
		free_stack(*a);
		free_stack(*b);
		return (0);
	}
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
	read_check(&a, &b);
	if (last_check(&a, &b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
