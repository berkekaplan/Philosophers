/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:37:16 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/26 15:51:12 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*view(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (!check_food(philos, 0))
	{
		philos->args->count = 0;
		while (philos->args->count < philos->args->number_of_philosophers)
		{
			pthread_mutex_lock(&philos->args->mutex_last_eat);
			if (get_time() - philos[philos->args->count++].last_eat
				> philos->args->time_to_die)
			{
				pthread_mutex_unlock(&philos->args->mutex_last_eat);
				view_next(philos);
				return (NULL);
			}
			else
				pthread_mutex_unlock(&philos->args->mutex_last_eat);
		}
		if (one_die_check(philos))
			break ;
	}
	return (NULL);
}

int	check_food(t_philo *philos, int i)
{
	if (philos->args->number_of_must_eat > 0)
	{
		while (i < philos->args->number_of_philosophers)
		{
			pthread_mutex_lock(&philos->args->mutex_eat);
			if (philos[i].eat_count >= philos->args->number_of_must_eat)
			{
				pthread_mutex_unlock(&philos->args->mutex_eat);
				philos->args->full++;
			}
			else
				pthread_mutex_unlock(&philos->args->mutex_eat);
			i++;
		}
		if (philos->args->full >= philos->args->number_of_philosophers)
		{
			pthread_mutex_lock(&philos->args->mutex_die);
			philos->args->died = 1;
			pthread_mutex_unlock(&philos->args->mutex_die);
			return (1);
		}
	}
	return (0);
}

void	view_next(t_philo *philos)
{
	write_term(philos->id, 5, philos);
	pthread_mutex_lock(&philos->args->mutex_die);
	philos->args->died = 1;
	pthread_mutex_unlock(&philos->args->mutex_die);
}

int	one_die_check(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->mutex_die);
	if (philos->args->number_of_philosophers < 2 && philos->args->died == 1)
	{
		pthread_mutex_unlock(&philos->args->mutex_die);
		return (1);
	}
	else
		pthread_mutex_unlock(&philos->args->mutex_die);
	return (0);
}
