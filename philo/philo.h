/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:37:08 by mkaplan           #+#    #+#             */
/*   Updated: 2023/10/24 23:52:05 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_arg
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_full;
	int				number_of_philosophers;
	int				number_of_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				full;
	long			first_time;
	int				died;
	int				write_died;
	int				count;
}	t_arg;

typedef struct s_philo
{
	pthread_t		thread;
	int				left_f;
	int				right_f;
	int				id;
	int				eat_count;
	long			last_eat;
	t_arg			*args;
}	t_philo;

long		get_time(void);
int			ft_atoi(const char *str);
int			arg_check(t_arg *args, int argc);
void		arg_parser(char **argv, t_arg *args, int argc);
int			init_threads(t_philo *philos, int philo_count);
void		init_philo(t_arg *args, t_philo *philos);
int			init_forks(t_philo *philos, int philo_count);
int			inits(t_arg	*args, t_philo *philos);
int			eating(t_philo *philos);
void		*dinner(void *arg);
void		write_term(int philo_num, int ans, t_philo *philos);
void		*view(void *arg);
int			check_food(t_philo *philos, int i);
void		wait_time(t_philo *philos, int wait_time);
int			one_die_check(t_philo *philos);
int			check(char **argv);
void		free_memory(t_philo *philos, int ans);
int			sleep_and_think(t_philo *philos);
void		eating_next(t_philo *philos);
void		view_next(t_philo *philos);
int			free_forks(pthread_mutex_t *mutex, t_philo *philos, int ans);

#endif