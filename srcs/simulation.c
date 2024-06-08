/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:22:15 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/30 18:56:36 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	only_one_philo(t_philo *philos)
{
	if (philos->table->config.n_philos == 1)
	{
		print_info(philos, MES_TAKE_LEFT_FORK);
		time_sleep(philos, philos->table->config.die_time * 1000);
		dying_message(philos);
	}
}

void	*simulation(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (!get_success(philos->table))
	{
		if (get_error(philos->table))
		{
			return (NULL);
		}
		usleep(100);
	}
	philos->l_e_time = philos->table->start_time;
	only_one_philo(philos);
	while (!check_died(philos))
	{
		eating(philos);
		sleeping(philos);
		thinking(philos);
		if (philos->table->config.eat_count != -1
			&& philos->n_ate == philos->table->config.eat_count)
			break ;
	}
	return (NULL);
}

int	create_pthread(t_philo **philos)
{
	int	i;
	int	p_create;

	i = 0;
	while (i < philos[0]->table->config.n_philos)
	{
		p_create = pthread_create(&philos[i]->living, NULL,
				simulation, philos[i]);
		if (p_create != 0)
		{
			write(STDERR_FILENO, ERROR_CREATE_PTHREAD,
				ft_strlen(ERROR_CREATE_PTHREAD));
			pthread_mutex_lock(&philos[i]->table->get_data);
			philos[i]->table->is_error = true;
			pthread_mutex_unlock(&philos[i]->table->get_data);
			return (i);
		}
		i++;
	}
	return (i);
}

int	start_simulation(t_philo **philos)
{
	long	start_time;
	int		index;

	index = create_pthread(philos);
	if (index == philos[0]->table->config.n_philos)
	{
		pthread_mutex_lock(&philos[0]->table->get_data);
		start_time = time_get();
		philos[0]->table->start_time = start_time;
		philos[0]->table->is_success = true;
		pthread_mutex_unlock(&philos[0]->table->get_data);
	}
	return (index);
}

int	end_simulation(t_philo **philos, int index)
{
	int	i;
	int	status;

	i = 0;
	status = index != philos[0]->table->config.n_philos;
	while (i < index)
	{
		pthread_join(philos[i]->living, NULL);
		i++;
	}
	delete_table(philos[0]->table);
	delete_philos(philos, index);
	return (status);
}
