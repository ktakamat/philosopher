/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:52:16 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/11 17:17:13 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	new_fork(t_table *table)
{
	pthread_mutex_t		*fork;
	int				i;

	fork = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (fork == NULL)
		exit(1);
	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&(fork[i]), NULL) != 0)
			exit(1);
		i++;
	}
	table->n_fork = fork;
}

void	delete_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_destroy(&table->n_fork[i]) != 0)
			exit(1);
		i++;
		printf("destroyed %d\n", i);
	}
	free(table->n_fork);
}

int    main(int argc, char **argv)
{
    t_table table;

    (void)argc;
    table.n_philos = atoi(argv[1]);
    new_fork(&table);
    delete_forks(&table);
    return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }