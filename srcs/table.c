/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:51:29 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/25 18:16:52 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*new_table(t_config config)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (NULL);
	if (pthread_mutex_init(&table->print_message, NULL) != 0)
	{
		free(table);
		return (NULL);
	}
	if (pthread_mutex_init(&table->get_data, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_message);
		free(table);
		return (NULL);
	}
	table->n_philos_ate = 0;
	table->is_success = false;
	table->is_error = false;
	table->is_dead = false;
	table->config = config;
	return (table);
}

void	delete_table(t_table *table)
{
	pthread_mutex_destroy(&(table->print_message));
	pthread_mutex_destroy(&(table->get_data));
	free(table);
}
