/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:29:34 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/25 18:13:15 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_died(t_philo *philos)
{
	if (already_dead(philos->table))
		return (true);
	if (time_pass(philos->l_e_time) >= philos->table->config.die_time)
	{
		dying_message(philos);
		return (true);
	}
	return (false);
}

void	dying_message(t_philo *philos)
{
	pthread_mutex_lock(&(philos->table->print_message));
	if (!(already_dead(philos->table)))
		printf(MES_DIED, time_pass(philos->table->start_time),
			philos->id);
	pthread_mutex_lock(&(philos->table->get_data));
	philos->table->is_dead = true;
	pthread_mutex_unlock(&(philos->table->get_data));
	pthread_mutex_unlock(&(philos->table->print_message));
}
