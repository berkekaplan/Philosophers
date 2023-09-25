/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:03:05 by mkaplan           #+#    #+#             */
/*   Updated: 2023/09/25 15:24:25 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	s;

	s = 0;
	if (!ft_isnum(str))
		return (0);
	while (*str != '\0')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s);
}

int	ft_isnum(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
