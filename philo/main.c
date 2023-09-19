/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:27:45 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/19 16:56:32 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	u_int64_t	time;
	t_philo		phil;

	if (argc != 5 || argc != 6)
		return (0);
	phil.philos = (t_argv *)malloc(sizeof(t_argv));
	if (!check_args(argc, argv))
		return (0);
	argument_placer(argc, argv, phil.philos);
	return (0);
}
