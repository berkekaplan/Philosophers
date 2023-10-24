/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:36:53 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/24 23:52:05 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_arg	args;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (write(2, "Error\n", 7));
	if (check(argv))
		return (1);
	args.first_time = get_time();
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philos)
		return (write(2, "Error\n", 7));
	arg_parser(argv, &args, argc);
	if (arg_check(&args, argc) == 0)
	{
		free(philos);
		write(2, "Error\n", 7);
		return (0);
	}
	if (inits(&args, philos))
		return (write(2, "Error\n", 7));
	free_memory(philos, 2);
}
