/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:27:45 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/25 15:27:09 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;

	if (argc != 5 || argc != 6)
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	elapsed_time();
	argument_placer(argc, argv, philo);
	if (!arg_control(philo, argc))
		return (0);
	return (0);
}
