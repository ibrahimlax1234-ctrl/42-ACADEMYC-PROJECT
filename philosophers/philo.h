/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:34:36 by librahim          #+#    #+#             */
/*   Updated: 2024/12/13 10:29:35 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H 
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

# define NO 7
# define YES 8
# define EAT 12
# define NOT_EAT 220
# define THINK 13
# define SLEEP 14
# define DIE 15
# define LIFTFORK 16

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx			fork;
}				t_fork;

typedef struct s_table	t_table;

typedef struct s_philo
{
	int			id;
	int			meals_count;
	int			state;
	long		last_meal_t;
	t_fork		*first_f;
	t_fork		*second_f;
	t_mtx		philo_mtx;
	pthread_t	pth_id;
	t_table		*t_ptr;
}				t_philo;

typedef struct s_table
{
	int				philo_nbr;
	int				time_to_sleep;
	int				time_to_die;
	int				time_to_eat;
	int				max_meals;
	int				ready_go;
	int				end_sim;
	long			time;
	t_mtx			print_mtx;
	t_mtx			table_mutex;
	t_mtx			sync_start;
	t_mtx			end_mtx;
	pthread_t		mon;
	t_fork			*fork_array;
	t_philo			*philo_array;
}					t_table;

int			parse_input(t_table	*t, char **v);
void		print_error(char	*s);
int			data_init(t_table	*t);
void		print_state(t_philo *p, int state);
void		gerer_pth_err(int st, int oc);
void		philo_init(t_table	*t);
void		assign_forks(t_philo *p, t_fork	*forks);
void		free_data(t_table *t);
void		wait_everyone(t_table	*t);
void		*monit_routine(void *d);
void		*the_routine(void	*d);
int			launch_simu(t_table *t);
long int	gettime(void);
void		end_sim(t_table *t);
long		ft_atol(char *nptr);
int			check_endsim(t_table *t);
void		dyin_msg(t_philo *p);

#endif
