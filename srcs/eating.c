/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:22:11 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/30 20:57:30 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_eat(t_philo *philos)
{
	philos->l_e_time = time_get();
	time_sleep(philos, philos->table->config.eat_time * 1000);
	if (philos->table->config.eat_count != -1)
	{
		if (already_dead(philos->table))
			return ;
		pthread_mutex_lock(&(philos->table->get_data));
		philos->n_ate++;
		if (philos->table->config.eat_count == philos->n_ate)
			philos->table->n_philos_ate++;
		if (philos->table->n_philos_ate == philos->table->config.n_philos)
			philos->table->is_dead = true;
		pthread_mutex_unlock(&(philos->table->get_data));
	}
}

void	eating(t_philo *philos)
{
	if ((philos->id == l_e_philo(philos->l_fork)
			|| philos->id == l_e_philo(philos->r_fork)))
		return ;
	pthread_mutex_lock(&(philos->l_fork->n_fork));
	print_info(philos, MES_TAKE_LEFT_FORK);
	pthread_mutex_lock(&(philos->r_fork->n_fork));
	print_info(philos, MES_TAKE_RIGHT_FORK);
	print_info(philos, MES_EATTING);
	time_eat(philos);
	philos->l_fork->l_e_philo = philos->id;
	pthread_mutex_unlock(&(philos->l_fork->n_fork));
	philos->r_fork->l_e_philo = philos->id;
	pthread_mutex_unlock(&(philos->r_fork->n_fork));
	return ;
}
