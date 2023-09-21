/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_opr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:45:12 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/21 13:33:07 by mkaplan          ###   ########.fr       */
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

int	null_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

int	arg_check(int argc, char **argv)
{
	int	i1;
	int	i2;

	i1 = 1;
	i2 = 0;
	if (!null_check(argc, argv))
		return (0);
	while (i1 < argc)
	{
		while (argv[i1][i2] != '\0')
		{
			if (argv[i1][i2] >= '0' && argv[i1][i2] <= '9')
				i2++;
			else
				return (0);
		}
		i1++;
		i2 = 0;
	}
	return (1);
}
