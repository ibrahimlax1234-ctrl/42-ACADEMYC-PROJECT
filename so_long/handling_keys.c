/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 05:04:36 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 03:27:56 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_header.h"

int	handle_inp(int keysym, t_inf *q)
{
	q->oldx_moves = q->p_x;
	q->oldy_moves = q->p_y;
	if (q->count_col > 0)
		handle_inp_coll(keysym, q);
	else
		handle_inp_ex(keysym, q);
	if (q->oldx_moves != q->p_x
		|| q->oldy_moves != q->p_y)
	{
		q->moves++;
		ft_printf("Current moves : %d.\n", q->moves);
	}
	drawing(q);
	return (0);
}

int	handle_inp_coll(int keysym, t_inf *q)
{
	if (keysym == 53)
		clean_free_everything(q, 1);
	else if (keysym == 13 && q->p_y - 1 >= 0
		&& q->map[q->p_y - 1][q->p_x] != '1'
		&& q->map[q->p_y - 1][q->p_x] != 'E')
	{
		q->map[q->p_y][q->p_x] = '0';
		q->p_y--;
	}
	else if (keysym == 0 && q->p_x - 1 >= 0
		&& q->map[q->p_y][q->p_x - 1] != '1'
		&& q->map[q->p_y][q->p_x - 1] != 'E')
	{
		q->map[q->p_y][q->p_x] = '0';
		q->p_x--;
	}
	handle_inp_coll_ii(keysym, q);
	q->map[q->p_y][q->p_x] = 'P';
	return (0);
}

void	handle_inp_coll_ii(int keysym, t_inf *q)
{
	if (keysym == 1 && q->p_y + 1 < q->height
		&& q->map[q->p_y + 1][q->p_x] != '1'
		&& q->map[q->p_y + 1][q->p_x] != 'E')
	{
		q->map[q->p_y][q->p_x] = '0';
		q->p_y++;
	}
	else if (keysym == 2 && q->p_x + 1 < q->width
		&& q->map[q->p_y][q->p_x + 1] != '1'
		&& q->map[q->p_y][q->p_x + 1] != 'E')
	{
		q->map[q->p_y][q->p_x] = '0';
		q->p_x++;
	}
	if (q->map[q->p_y][q->p_x] == 'C')
		q->count_col--;
}

int	handle_inp_ex(int keysym, t_inf *q)
{
	if (keysym == 53)
	{
		mlx_destroy_window(q->cnx, q->w);
		exit(0);
	}
	handle_inp_ex_ii(keysym, q);
	if (q->map[q->p_y][q->p_x] == 'E' && q->count_col == 0)
	{
		ft_printf("YOU WON!!\n");
		q->map[q->p_y][q->p_x] = 'P';
		drawing(q);
		clean_free_everything(q, 1);
	}
	q->map[q->p_y][q->p_x] = 'P';
	return (0);
}

void	handle_inp_ex_ii(int keysym, t_inf *q)
{
	if (keysym == 13 && q->p_y - 1 >= 0
		&& q->map[q->p_y - 1][q->p_x] != '1')
	{
		q->map[q->p_y][q->p_x] = '0';
		q->p_y--;
	}
	else if (keysym == 0 && q->p_x - 1 >= 0
		&& q->map[q->p_y][q->p_x - 1] != '1')
	{
		q->map[q->p_y][q->p_x] = '0';
		q->p_x--;
	}
	else if (keysym == 1 && q->p_y + 1 < q->height
		&& q->map[q->p_y + 1][q->p_x] != '1')
	{
		q->map[q->p_y][q->p_x] = '0';
		q->p_y++;
	}
	else if (keysym == 2 && q->p_x + 1 < q->width
		&& q->map[q->p_y][q->p_x + 1] != '1')
	{
		q->map[q->p_y][q->p_x] = '0';
		q->p_x++;
	}
}
