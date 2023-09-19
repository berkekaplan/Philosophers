/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_opr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:45:12 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/19 17:30:17 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	argument_placer(int argc, char **argv, t_argv *philo)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

int	check_args(int argc, char **argv)
{
	if (argc == 5)
	{
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
        || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
			return (0);
	}
	else
	{
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
        || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
        || ft_atoi(argv[5]) <= 0)
			return (0);
	}
	return (1);
}
