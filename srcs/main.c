/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:09:12 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/30 19:24:32 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**set_philos(int argc, char **argv)
{
	t_philo		**philos;
	t_fork		**forks;
	t_table		*table;
	t_config	config;

	if (assign_time(argc, argv, &config) == -1)
		return (NULL);
	table = new_table(config);
	if (table == NULL)
		return (NULL);
	forks = create_forks(table->config.n_philos);
	if (forks == NULL)
	{
		delete_table(table);
		return (NULL);
	}
	philos = create_philos(forks, table);
	if (philos == NULL)
	{
		delete_forks(forks);
		delete_table(table);
		return (NULL);
	}
	return (philos);
}

int	main(int argc, char **argv)
{
	t_philo	**philos;
	int		index;

	philos = set_philos(argc, argv);
	if (philos == NULL)
	{
		write(STDERR_FILENO, ERROR_MES_FAILD_INIT,
			ft_strlen(ERROR_MES_FAILD_INIT));
		return (ERROR);
	}
	index = start_simulation(philos);
	return (end_simulation(philos, index));
}

// __attribute__((destructor)) 
// static void destructor()
// {
//     system("leaks -q philo");
// }
