/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:17:50 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/25 15:14:43 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

# define TAKEN_FORK "has taken a fork"
# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define DIE "died"

typedef struct s_philo
{
	pthread_mutex_t	*mutex_fork;
	pthread_t		*thread;
	uint64_t		time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				forks;
	int				id;
}	t_philo;

void		argument_placer(int argc, char **argv, t_argv *philo);

int			ft_atoi(const char *str);
int			arg_control(t_philo *philo, int argc);
uint64_t	elapsed_time(void);

#endif
