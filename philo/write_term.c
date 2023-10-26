/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:37:20 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/26 14:44:31 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	write_term(int philo_num, int ans, t_philo *philos)
{
	pthread_mutex_lock(&philos->args->write);
	if (philos->args->write_died == 1)
	{
		pthread_mutex_unlock(&philos->args->write);
		return ;
	}
	printf("%ld ms", get_time() - philos->args->first_time);
	printf(" %d", philo_num);
	if (ans == 1)
		printf(" has taken a fork");
	else if (ans == 2)
		printf(" is eating");
	else if (ans == 3)
		printf(" is sleeping");
	else if (ans == 4)
		printf(" is thinking");
	else if (ans == 5)
	{
		philos->args->write_died = 1;
		printf(" died");
		pthread_mutex_unlock(&philos->args->write);
	}
	printf("\n");
	if (philos->args->write_died != 1)
		pthread_mutex_unlock(&philos->args->write);
}
