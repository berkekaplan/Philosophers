/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:37:03 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/26 14:43:48 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	s;

	s = 0;
	while (*str >= '0' && *str <= '9')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s);
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

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	wait_time(t_philo *philos, int wait_time)
{
	long	time;

	time = get_time();
	pthread_mutex_lock(&philos->args->mutex_die);
	while (!philos->args->died)
	{
		pthread_mutex_unlock(&philos->args->mutex_die);
		usleep(40);
		if (get_time() - time >= wait_time)
		{
			pthread_mutex_lock(&philos->args->mutex_die);
			break ;
		}
		pthread_mutex_lock(&philos->args->mutex_die);
	}
	pthread_mutex_unlock(&philos->args->mutex_die);
}
