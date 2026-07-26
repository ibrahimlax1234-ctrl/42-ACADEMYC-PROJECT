/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_the_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 04:50:01 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 03:00:39 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_header.h"

int	retrieve_player_pos(char **map, int *y)
{
	int	x;
	int	yy;

	x = 0;
	while (map[x])
	{
		yy = 0;
		while (map[x][yy])
		{
			if (map[x][yy] == 'P')
			{
				*y = yy;
				return (x);
			}
			yy++;
		}
		x++;
	}
	return (-1);
}

int	check_player_map(char **s)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

void	drawing(t_inf *q)
{
	int	i;
	int	j;

	mlx_clear_window(q->cnx, q->w);
	i = 0;
	while (q->map[i])
	{
		j = 0;
		while (q->map[i][j])
		{
			drawing_ii(q, i, j);
			j++;
		}
		i++;
	}
}

void	drawing_ii(t_inf *q, int i, int j)
{
	char	*s;

	s = ft_itoa(q->moves);
	if (q->map[i][j] == '1')
		mlx_put_image_to_window(q->cnx, q->w, q->img_wall, j * 50, i * 50);
	else if (q->map[i][j] == '0')
		mlx_put_image_to_window(q->cnx, q->w, q->img_fl, j * 50, i * 50);
	else if (q->map[i][j] == 'C')
	{
		mlx_put_image_to_window(q->cnx, q->w, q->img_fl, j * 50, i * 50);
		mlx_put_image_to_window(q->cnx, q->w, q->img_coll, j * 50, i * 50);
	}
	else if (q->map[i][j] == 'E')
		mlx_put_image_to_window(q->cnx, q->w, q->img_exit, j * 50, i * 50);
	else if (q->map[i][j] == 'P')
	{
		mlx_put_image_to_window(q->cnx, q->w, q->img_fl, j * 50, i * 50);
		mlx_put_image_to_window(q->cnx, q->w, q->img_pl, j * 50, i * 50);
	}
	mlx_string_put(q->cnx, q->w, 10, 10, 800, "CURRENT MOVES :");
	mlx_string_put(q->cnx, q->w, 170, 10, 800, s);
	free(s);
}
