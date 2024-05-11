/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:52:57 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/11 18:05:11 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

typedef struct s_table {
	pthread_mutex_t	*n_fork;
	int				n_philos;
}	t_table;

typedef struct e_philo {
	int			id;
	int			r_l_forks[2];
	int			n_ate;
	t_table		*table;
}	t_philo;

void	new_fork(t_table *table);
void	delete_forks(t_table *table);
int    main(int argc, char **argv);

#endif
