/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:27:45 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/21 16:31:27 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		phil;

	if (argc != 5 || argc != 6)
		return (0);
	if (!arg_check(argc, argv))
		return (0);
	phil.philos = (t_argv *)malloc(sizeof(t_argv));
	elapsed_time();
	argument_placer(argc, argv, phil.philos);
	return (0);
}
