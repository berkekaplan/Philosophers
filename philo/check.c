/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:36:23 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/24 22:10:43 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	arg_parser(char **argv, t_arg *args, int argc)
{
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->number_of_must_eat = 0;
	if (argc == 6)
		args->number_of_must_eat = ft_atoi(argv[5]);
}

int	arg_check(t_arg *args, int argc)
{
	if (argc == 6)
	{
		if (args->number_of_must_eat == 0 || args->time_to_die == 0
			|| args->number_of_philosophers == 0 || args->time_to_eat == 0
			|| args->time_to_sleep == 0)
			return (0);
	}
	else if (argc == 5)
	{
		if (args->number_of_philosophers == 0 || args->time_to_die == 0
			|| args->time_to_eat == 0 || args->time_to_sleep == 0)
			return (0);
	}
	return (1);
}

int	check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			write(2, "Error\n", 7);
			return (1);
		}
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				write(2, "Error\n", 7);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
