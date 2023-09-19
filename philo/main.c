/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:27:45 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/19 15:36:06 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    u_int64_t   time;
    philo_t     phil;

    if(argc != 5 || argc != 6)
        return 0;

    phil.philos = (argv_t *)malloc(sizeof(argv_t));
    argument_placer(argc, argv, phil.philos);
    
}