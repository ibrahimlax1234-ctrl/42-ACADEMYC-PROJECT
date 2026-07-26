/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 04:37:09 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 03:27:43 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_header.h"

int	checks(char **res)
{
	if (check_if_rectang(res) || check_map_chars(res)
		|| check_if_map_enclosed(res)
		|| check_collectibles_map(res) == -1
		|| check_exit_map(res)
		|| check_player_map(res))
	{
		free_2dim_arr(res);
		return (1);
	}
	else
		return (0);
}

char	**read_map(char *filename)
{
	int		d;
	char	*bigline;
	char	*line;
	char	**res;

	bigline = ft_strdup("");
	d = open(filename, O_RDONLY);
	if (d == -1)
	{
		p_er("COULD NOT OPEN FILENAME");
		return (free(bigline), NULL);
	}
	line = get_next_line(d);
	while (line)
	{
		bigline = ftr_strjoin(bigline, line);
		line = get_next_line(d);
	}
	close(d);
	if (!bigline[0] || check_nl(bigline))
		return (free(bigline), NULL);
	res = ft_split(bigline, '\n');
	if (checks(res))
		return (free(bigline), NULL);
	return (free(bigline), res);
}

int	chek_imgs(t_inf	*q)
{
	if (!q->img_coll || !q->img_exit
		|| !q->img_fl || !q->img_pl
		|| !q->img_wall)
		return (1);
	return (0);
}

t_inf	data_init(char *filename)
{
	t_inf	i;

	i.map = read_map(filename);
	if (!(i.map))
	{
		p_er("INVALID MAP.");
		exit (1);
	}
	i.filled_map = read_map(filename);
	i.count_col = check_collectibles_map(i.map);
	i.cnx = mlx_init();
	if (!(i.cnx))
	{
		p_er("FAILED THE MLX INITIALIZATION.");
		clean_free_everything(&i, 1);
	}
	i.height = ft_dim_len(i.map);
	i.width = ft_strlen(i.map[0]);
	i.w = mlx_new_window(i.cnx, i.width * 50, i.height * 50, "so_long");
	more_data_init(&i);
	return (i);
}

void	more_data_init(t_inf *i)
{
	int	x;
	int	y;

	i->img_pl = mlx_xpm_file_to_image(i->cnx, PLAYER, &x, &y);
	i->img_fl = mlx_xpm_file_to_image(i->cnx, FLOOR, &x, &y);
	i->img_wall = mlx_xpm_file_to_image(i->cnx, WALL, &x, &y);
	i->img_exit = mlx_xpm_file_to_image(i->cnx, DOOR, &x, &y);
	i->img_coll = mlx_xpm_file_to_image(i->cnx, ORANGE, &x, &y);
	i->p_y = retrieve_player_pos(i->map, &(i->p_x));
	i->moves = 0;
	if (chek_imgs(i))
	{
		p_er("COULD NOT READ XPM FILES\n");
		clean_free_everything(i, 0);
	}
	if (check_map_path(i))
	{
		p_er("INVALID MAP.");
		clean_free_everything(i, 1);
	}
}
