/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:01:38 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 03:28:44 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_header.h"

int	clean_free_everything(t_inf	*q, int seg)
{
	if (seg == 1)
	{
		mlx_destroy_image(q->cnx, q->img_coll);
		mlx_destroy_image(q->cnx, q->img_exit);
		mlx_destroy_image(q->cnx, q->img_fl);
		mlx_destroy_image(q->cnx, q->img_wall);
		mlx_destroy_image(q->cnx, q->img_pl);
	}
	mlx_clear_window(q->cnx, q->w);
	mlx_destroy_window(q->cnx, q->w);
	free_2dim_arr(q->map);
	free_2dim_arr(q->filled_map);
	exit(0);
}

int	check_filename(char **v)
{
	if (ft_strlen(v[1]) < 4)
		return (1);
	if (v[1][ft_strlen(v[1]) - 1] != 'r'
		&& v[1][ft_strlen(v[1]) - 2] != 'e'
		&& v[1][ft_strlen(v[1]) - 3] != 'b'
		&& v[1][ft_strlen(v[1]) - 4] != '.')
		return (1);
	return (0);
}

void	p_er(char *er)
{
	write(2, "Error\n", 6);
	write(2, er, ft_strlen(er));
}

int	main(int c, char **v)
{
	t_inf	i;

	if (c != 2)
		return (p_er("INVALID NUMBER OF ARGUMENTS."), 1);
	if (check_filename(v))
		return (p_er("FILENAME INVALID."), 1);
	i = data_init(v[1]);
	drawing(&i);
	mlx_key_hook(i.w, handle_inp, &i);
	mlx_hook(i.w, 17, 0, clean_free_everything, &i);
	mlx_loop(i.cnx);
	return (0);
}
