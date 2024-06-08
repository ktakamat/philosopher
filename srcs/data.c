/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:32:20 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/22 20:26:28 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	l_e_philo(t_fork *fork)
{
	int	id;

	id = 0;
	pthread_mutex_lock(&fork->n_fork);
	id = fork->l_e_philo;
	pthread_mutex_unlock(&fork->n_fork);
	return (id);
}

bool	already_dead(t_table *table)
{
	bool	data;

	data = false;
	pthread_mutex_lock(&table->get_data);
	data = table->is_dead;
	pthread_mutex_unlock(&table->get_data);
	return (data);
}

bool	get_success(t_table *table)
{
	bool	data;

	data = false;
	pthread_mutex_lock(&table->get_data);
	data = table->is_success;
	pthread_mutex_unlock(&table->get_data);
	return (data);
}

bool	get_error(t_table *table)
{
	bool	get_data;

	get_data = false;
	pthread_mutex_lock(&table->get_data);
	get_data = table->is_error;
	pthread_mutex_unlock(&table->get_data);
	return (get_data);
}

long	get_start_time(t_table *table)
{
	long	start_time;

	start_time = 0;
	pthread_mutex_lock(&table->get_data);
	start_time = table->start_time;
	pthread_mutex_unlock(&table->get_data);
	return (start_time);
}
