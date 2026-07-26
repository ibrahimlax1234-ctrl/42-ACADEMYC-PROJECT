/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:20:27 by librahim          #+#    #+#             */
/*   Updated: 2024/10/14 23:20:27 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	custom_usleep(long duration, t_table *t)
{
	long	start_time;

	(void)t;
	start_time = gettime();
	while ((gettime() - start_time) < duration
		&& !check_endsim(t))
		usleep(100);
}

void	take_forks_n_eat(t_philo *p)
{
	pthread_mutex_lock(&p->first_f->fork);
	print_state(p, LIFTFORK);
	pthread_mutex_lock(&p->second_f->fork);
	print_state(p, LIFTFORK);
	pthread_mutex_lock(&p->philo_mtx);
	p->state = EAT;
	p->meals_count++;
	p->last_meal_t = gettime();
	pthread_mutex_unlock(&p->philo_mtx);
	print_state(p, EAT);
	custom_usleep(p->t_ptr->time_to_eat, p->t_ptr);
	pthread_mutex_unlock(&p->first_f->fork);
	pthread_mutex_unlock(&p->second_f->fork);
	pthread_mutex_lock(&p->philo_mtx);
	p->state = NOT_EAT;
	pthread_mutex_unlock(&p->philo_mtx);
}

void	lone_philo_routine(t_philo *p)
{
	pthread_mutex_lock(&p->first_f->fork);
	print_state(p, LIFTFORK);
	usleep(p->t_ptr->time_to_die);
	dyin_msg(p);
	return ;
}

int	check_endsim(t_table *t)
{
	pthread_mutex_lock(&t->table_mutex);
	if (t->end_sim == YES)
	{
		pthread_mutex_unlock(&t->table_mutex);
		return (1);
	}
	pthread_mutex_unlock(&t->table_mutex);
	return (0);
}

void	*the_routine(void	*d)
{
	t_table	*t;
	t_philo	*p;

	(1) && (p = (t_philo *)d, t = p->t_ptr);
	if (t->philo_nbr == 1)
		return (lone_philo_routine(p), NULL);
	wait_everyone(t);
	if (p->id % 2)
		usleep(4000);
	pthread_mutex_lock(&p->philo_mtx);
	p->last_meal_t = gettime();
	p->state = NOT_EAT;
	pthread_mutex_unlock(&p->philo_mtx);
	while (1)
	{
		if (check_endsim(t))
			break ;
		take_forks_n_eat(p);
		print_state(p, SLEEP);
		custom_usleep(p->t_ptr->time_to_sleep, t);
		print_state(p, THINK);
		if (t->max_meals > 0 && p->meals_count == t->max_meals)
			break ;
	}
	return (NULL);
}
