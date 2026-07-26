/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:03:11 by librahim          #+#    #+#             */
/*   Updated: 2024/07/06 01:11:13 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

char	*parse(int argc, char **argv)
{
	char	*allargs;

	allargs = joineverything(argv, argc);
	if (!allargs)
		return (NULL);
	while (space_detector_at_the_end(allargs))
		rmlastspace(allargs);
	if (checkargs(allargs))
		return (allargs);
	else
		free(allargs);
	return (NULL);
}

void	handle_swap(char *s, t_s **a, t_s **b)
{
	if (!ft_strncmp(s, "sa\n", 3))
		swap(*a);
	else if (!ft_strncmp(s, "sb\n", 3))
		swap(*b);
	else if (!ft_strncmp(s, "ss\n", 3))
		ss(*a, *b);
}

void	handle_rot(char *s, t_s **a, t_s **b)
{
	if (!ft_strncmp(s, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(s, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(s, "rr\n", 3))
		rr(a, b);
}

void	handle_rrot(char *s, t_s **a, t_s **b)
{
	if (!ft_strncmp(s, "rra\n", 4))
		rrotate(a);
	else if (!ft_strncmp(s, "rra\n", 4))
		rrotate(b);
	else if (!ft_strncmp(s, "rrr\n", 4))
		rrr(a, b);
}

void	handle_push(char *s, t_s **a, t_s **b)
{
	if (!ft_strncmp(s, "pa\n", 3))
		pa(b, a);
	else if (!ft_strncmp(s, "pb\n", 3))
		pb(a, b);
}
