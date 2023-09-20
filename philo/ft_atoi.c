/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:03:05 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/20 19:41:10 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num(const	char *str)
{
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	s;

	s = 0;
	if (!check_num(str))
		return (-1);
	while (*str != '\0')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s);
}
