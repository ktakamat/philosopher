/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:58:40 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/30 20:57:16 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_get(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

long	time_pass(long start_usec)
{
	long	usec;

	usec = time_get();
	return ((usec - start_usec) / 1000);
}

void	time_sleep(t_philo *philos, long sleep_time)
{
	long	start_time;
	long	elapsed_time;

	start_time = time_get();
	while (true)
	{
		elapsed_time = time_get() - start_time;
		if (check_died(philos))
			break ;
		if (elapsed_time >= sleep_time)
			break ;
		usleep (300);
	}
}
