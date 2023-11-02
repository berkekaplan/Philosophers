/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:36:17 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/30 13:43:32 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	*dinner(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	if (philos->id % 2 != 0)
	{
		write_term(philos->id, 4, philos);
		usleep(1000);
	}
	while (1)
	{
		if (philos->eat_count < philos->args->number_of_must_eat
			|| philos->args->number_of_must_eat == 0)
		{
			if (eating(philos))
				break ;
		}
		if (sleep_and_think(philos))
			break ;
	}
	return (NULL);
}

int	eating(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->forks[philos->left_f]);
	write_term(philos->id, 1, philos);
	if (philos->args->number_of_philosophers >= 2)
	{
		pthread_mutex_lock(&philos->args->forks[philos->right_f]);
		write_term(philos->id, 1, philos);
	}
	else
	{
		pthread_mutex_unlock(&philos->args->forks[philos->left_f]);
		return (1);
	}
	eating_next(philos);
	if (philos->args->number_of_philosophers >= 2)
	{
		pthread_mutex_unlock(&philos->args->forks[philos->left_f]);
		pthread_mutex_unlock(&philos->args->forks[philos->right_f]);
	}
	return (0);
}

void	eating_next(t_philo *philos)
{
	write_term(philos->id, 2, philos);
	pthread_mutex_lock(&philos->args->mutex_last_eat);
	philos->last_eat = get_time();
	pthread_mutex_unlock(&philos->args->mutex_last_eat);
	wait_time(philos, philos->args->time_to_eat);
	pthread_mutex_lock(&philos->args->mutex_eat);
	philos->eat_count++;
	pthread_mutex_unlock(&philos->args->mutex_eat);
}

int	sleep_and_think(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->mutex_die);
	if (philos->args->died == 1 && philos->eat_count
		>= philos->args->number_of_must_eat)
	{
		pthread_mutex_unlock(&philos->args->mutex_die);
		return (1);
	}
	pthread_mutex_unlock(&philos->args->mutex_die);
	write_term(philos->id, 3, philos);
	wait_time(philos, philos->args->time_to_sleep);
	write_term(philos->id, 4, philos);
	return (0);
}
