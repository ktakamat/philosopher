/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:00:32 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/25 18:16:28 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(size_t id, t_fork *l_fork, t_fork *r_fork, t_table *table)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->id = id;
	philo->l_fork = l_fork;
	philo->r_fork = r_fork;
	philo->n_ate = 0;
	philo->table = table;
	return (philo);
}

void	delete_philos(t_philo **philos, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		delete_fork(philos[i]->l_fork);
		free(philos[i]);
		i++;
	}
	free(philos);
}

t_philo	**create_philos(t_fork **forks, t_table *table)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo *) * table->config.n_philos);
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < table->config.n_philos)
	{
		philos[i] = new_philo(i + 1, forks[i],
				forks[(i + 1) % table->config.n_philos],
				table);
		if (philos[i] == NULL)
		{
			delete_philos(philos, i);
			return (NULL);
		}
		i++;
	}
	free(forks);
	return (philos);
}
