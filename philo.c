/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:00:32 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/11 19:03:05 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_philo	*new_philo(size_t id, int l_fork, int r_fork, t_table *table)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		exit(1);
	philo->id = id;
	philo->r_l_forks[0] = r_fork;
	philo->r_l_forks[1] = l_fork;
	philo->n_ate = 0;
	philo->table = table;
	return(philo);
}

void	delete_philos(t_philo **philos, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		delete_forks(philos[i]->r_l_forks[0]);
		delete_forks(philos[i]->r_l_forks[1]);
		free(philos[i]);
		i++;
	}
	free(philos);
}

t_philo **create_philos(t_table *table)
{
	t_philo **philos;
	int i;

	philos = malloc(sizeof(t_philo *) * table->n_philos);
	if (philos == NULL)
		exit(1);

	i = 0;
	while (i < table->n_philos)
		philos[i] = new_philo(i + 1, i % table->n_philos, (i + 1) % table->n_philos, table);
	{
		if (philos[i] == NULL)
		{
			delete_philos(philos, i);
			return (NULL);
		}
		i++;
	}
	return (philos);
}
