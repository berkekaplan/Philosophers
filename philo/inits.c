/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:36:44 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/26 14:44:12 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	init_threads(t_philo *philos, int philo_count)
{
	pthread_t	tview;
	int			i;

	i = 0;
	while (i < philo_count)
	{
		if (pthread_create(&philos[i].thread, NULL, &dinner, &philos[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&tview, NULL, view, philos) != 0)
		return (1);
	i = 0;
	while (i < philo_count)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(tview, NULL) != 0)
		return (1);
	return (0);
}

void	init_philo(t_arg *args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		philos[i].id = (i +1);
		philos[i].left_f = i;
		philos[i].right_f = i +1;
		philos[i].eat_count = 0;
		philos[i].last_eat = get_time();
		philos[i].args = args;
		i++;
	}
	philos[i -1].right_f = 0;
}

int	init_forks(t_philo *philos, int philo_count)
{
	int	i;

	philos->args->forks = malloc(sizeof(pthread_mutex_t) * philo_count);
	if (!philos->args->forks)
		return (free(philos), 1);
	if (pthread_mutex_init(&philos->args->write, NULL) != 0)
		return (free_forks(&philos->args->write, philos, 0));
	if (pthread_mutex_init(&philos->args->mutex_die, NULL) != 0)
		return (free_forks(&philos->args->mutex_die, philos, 0));
	if (pthread_mutex_init(&philos->args->mutex_eat, NULL) != 0)
		return (free_forks(&philos->args->mutex_eat, philos, 0));
	if (pthread_mutex_init(&philos->args->mutex_last_eat, NULL) != 0)
		return (free_forks(&philos->args->mutex_last_eat, philos, 0));
	if (pthread_mutex_init(&philos->args->mutex_full, NULL) != 0)
		return (free_forks(&philos->args->mutex_full, philos, 0));
	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_init(&philos->args->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	inits(t_arg	*args, t_philo *philos)
{
	args->died = 0;
	args->full = 0;
	args->write_died = 0;
	init_philo(args, philos);
	if (init_forks(philos, args->number_of_philosophers))
		return (1);
	if (init_threads(philos, args->number_of_philosophers))
	{
		free_memory(philos, 2);
		return (1);
	}
	return (0);
}
