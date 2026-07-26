/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:18:58 by librahim          #+#    #+#             */
/*   Updated: 2024/07/31 03:31:54 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HEADER_H
# define COMMON_HEADER_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# define PLAYER "textures/player.xpm" 
# define FLOOR "textures/floor.xpm"
# define WALL "textures/wall.xpm"
# define DOOR "textures/exit.xpm"
# define ORANGE "textures/orange.xpm"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_info
{
	void	*cnx;
	void	*w;
	void	*img_pl;
	void	*img_fl;
	void	*img_wall;
	void	*img_exit;
	void	*img_coll;
	int		p_x;
	int		p_y;
	int		height;
	int		width;
	char	**map;
	char	**filled_map;
	int		count_col;
	int		oldx_moves;
	int		oldy_moves;
	int		moves;
}	t_inf;

void	flood_fill(t_inf *d, int row, int col);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_read(char *mainbuffer, int fd, int *index);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_dim_len(char **s);
char	*ftr_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
int		ft_nbr_len(int n);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	free_memory(char **arr, int size);
void	*ft_calloc(size_t blocks, size_t sizeblock);
int		ft_printf(const char *f, ...);
void	ft_printhex_len(unsigned int l, int *len);
void	ft_putchar_len(int k, int *len);
void	ft_putnbr_len(int nb, int *len);
void	ft_putnbr_u_len(unsigned int nb, int *len);
void	ft_putstr_len(char *s, int *len);
void	ft_printupperhex_len(unsigned int l, int *len);
void	ft_printadress_len(void *i, int *len);
void	man_conv(va_list a, char l, int *len);
void	free_2dim_arr(char **arr);
t_inf	data_init(char *filename);
void	more_data_init(t_inf *i);
int		chek_imgs(t_inf	*q);
char	**read_map(char *filename);
int		check_map_chars(char **s);
int		check_if_rectang(char **s);
int		check_if_map_enclosed(char **s);
int		check_collectibles_map(char **s);
int		check_player_map(char **s);
int		check_nl(char *l);
int		check_filename(char **v);
int		check_exit_map(char **s);
int		check_exit_fill_flood(char **s);
int		checkfilled_map_coll(char **s);
int		retrieve_player_pos(char **map, int *y);
int		check_map_path(t_inf *t);
int		checks(char **res);
void	p_er(char *er);
int		handle_inp(int keysym, t_inf *q);
int		handle_inp_ex(int keysym, t_inf *q);
void	refresh_moves(t_inf *q);
int		handle_inp_coll(int keysym, t_inf *q);
void	handle_inp_coll_ii(int keysym, t_inf *q);
void	handle_inp_ex_ii(int keysym, t_inf *q);
int		clean_free_everything(t_inf	*q, int seg);
void	drawing(t_inf *q);
void	drawing_ii(t_inf *q, int i, int j);

#endif