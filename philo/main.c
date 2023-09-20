/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:27:45 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/20 19:34:33 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	u_int64_t	time;
	t_philo		phil;

	if (argc != 5 || argc != 6)
		return (0);
	if (ft_atoi(argv) == -1)
		return (0);
	phil.philos = (t_argv *)malloc(sizeof(t_argv));
	time = elapsed_time();
	argument_placer(argc, argv, phil.philos);
	return (0);
}
