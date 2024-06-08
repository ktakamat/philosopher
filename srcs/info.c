/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:31:08 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/25 18:13:25 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_info(t_philo *philos, char *print_message)
{
	pthread_mutex_lock(&(philos->table->print_message));
	if (!(already_dead(philos->table) || get_error(philos->table)))
	{
		printf(print_message, time_pass(get_start_time(philos->table)),
			philos->id);
	}
	pthread_mutex_unlock(&(philos->table->print_message));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
