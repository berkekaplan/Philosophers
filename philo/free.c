/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:36:50 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/30 18:27:35 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	free_memory(t_philo *philos, int ans)
{
	int	i;

	i = 0;
	while (i < philos->args->number_of_philosophers)
	{
		pthread_mutex_destroy(&philos->args->forks[i]);
		i++;
	}
	if (ans == 2)
	{
		pthread_mutex_destroy(&philos->args->write);
		pthread_mutex_destroy(&philos->args->mutex_die);
		pthread_mutex_destroy(&philos->args->mutex_eat);
		pthread_mutex_destroy(&philos->args->mutex_last_eat);
		pthread_mutex_destroy(&philos->args->mutex_full);
	}
	free(philos->args->forks);
	free(philos);
}

int	free_forks(t_philo *philos, int ans)
{
	if (ans == 0)
		free_memory(philos, 0);
	if (ans == 1)
	{
		pthread_mutex_destroy(&philos->args->write);
		free_memory(philos, 0);
	}
	if (ans == 2)
	{
		pthread_mutex_destroy(&philos->args->write);
		pthread_mutex_destroy(&philos->args->mutex_die);
		free_memory(philos, 0);
	}
	return (1);
}

int	free_forks2(t_philo *philos, int ans)
{
	if (ans == 3)
	{
		pthread_mutex_destroy(&philos->args->write);
		pthread_mutex_destroy(&philos->args->mutex_die);
		pthread_mutex_destroy(&philos->args->mutex_eat);
		free_memory(philos, 0);
	}
	if (ans == 4)
	{
		pthread_mutex_destroy(&philos->args->write);
		pthread_mutex_destroy(&philos->args->mutex_die);
		pthread_mutex_destroy(&philos->args->mutex_eat);
		pthread_mutex_destroy(&philos->args->mutex_last_eat);
		free_memory(philos, 0);
	}
	return (1);
}
