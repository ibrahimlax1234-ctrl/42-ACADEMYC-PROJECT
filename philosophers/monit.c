/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:39:42 by librahim          #+#    #+#             */
/*   Updated: 2024/12/13 08:48:13 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	monit_check(t_philo *p, t_table *t)
{
	pthread_mutex_lock(&p->philo_mtx);
	if (p->state != EAT
		&& (gettime() - p->last_meal_t) >= t->time_to_die)
	{
		pthread_mutex_unlock(&p->philo_mtx);
		pthread_mutex_lock(&t->table_mutex);
		dyin_msg(p);
		t->end_sim = YES;
		pthread_mutex_unlock(&t->table_mutex);
		return (1);
	}
	pthread_mutex_unlock(&p->philo_mtx);
	pthread_mutex_lock(&p->philo_mtx);
	if (p->meals_count == t->max_meals)
		return (pthread_mutex_unlock(&p->philo_mtx), 1);
	pthread_mutex_unlock(&p->philo_mtx);
	return (0);
}

void	*monit_routine(void *d)
{
	t_table	*t;
	t_philo	*p;
	int		i;

	t = (t_table *)d;
	p = t->philo_array;
	wait_everyone(t);
	usleep(50000);
	while (1)
	{
		i = 0;
		if (t->philo_nbr == 1)
			break ;
		while (i < t->philo_nbr)
		{
			if (monit_check(&p[i], t) == 1)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
