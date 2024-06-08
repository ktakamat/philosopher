/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:52:16 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/25 17:57:29 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	**create_forks(int n_philos)
{
	t_fork	**forks;
	int		i;

	forks = malloc(sizeof(t_fork) * n_philos);
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < n_philos)
	{
		forks[i] = new_fork();
		if (forks[i] == NULL)
		{
			delete_forks(forks);
			return (NULL);
		}
		if (i % 2 == 0)
			forks[i]->l_e_philo = i + 1;
		else
			forks[i]->l_e_philo = i + 2;
		i++;
	}
	if (i % 2 != 0)
		forks[i - 1]->l_e_philo = i;
	return (forks);
}

t_fork	*new_fork(void)
{
	t_fork			*fork;

	fork = malloc(sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	if (pthread_mutex_init(&(fork->n_fork), NULL))
	{
		free(fork);
		return (NULL);
	}
	return (fork);
}

void	delete_fork(t_fork *fork)
{
	pthread_mutex_destroy(&(fork->n_fork));
	free(fork);
}

void	delete_forks(t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i] != NULL)
	{
		delete_fork(forks[i]);
		i++;
	}
	free(forks);
}
