/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launching_the_dinner.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:31:01 by librahim          #+#    #+#             */
/*   Updated: 2024/12/13 08:46:09 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_the_threads(t_table *t)
{
	int	i;

	i = -1;
	while (++i < t->philo_nbr)
	{
		if (pthread_join(t->philo_array[i].pth_id, NULL))
			return (1);
	}
	return (0);
}

int	launch_simu(t_table *t)
{
	int	i;

	i = -1;
	if (t->max_meals == 0)
		return (1);
	t->time = gettime();
	while (++i < t->philo_nbr)
	{
		if (pthread_create(&(t->philo_array[i].pth_id), NULL,
				the_routine, (void *)&t->philo_array[i]))
			return (1);
	}
	if (pthread_create(&t->mon, NULL, monit_routine, (void *)t))
		return (1);
	pthread_mutex_lock(&t->sync_start);
	t->ready_go = YES;
	pthread_mutex_unlock(&t->sync_start);
	if (join_the_threads(t))
		return (1);
	if (pthread_join(t->mon, NULL))
		return (1);
	return (0);
}
