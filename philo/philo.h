/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:17:50 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/21 13:33:32 by mkaplan          ###   ########.fr       */
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

typedef struct argv
{
	int				number_of_philosophers;
	int				forks;
	int				number_of_times_each_philosopher_must_eat;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
}	t_argv;

typedef struct philo
{
	u_int64_t		start_time;
	t_argv			*philos;
}	t_philo;

void		argument_placer(int argc, char **argv, t_argv *philo);

int			ft_atoi(const char *str);
int			arg_check(int argc, char **argv);
int			null_check(int argc, char **argv);

uint64_t	elapsed_time(void);

#endif
