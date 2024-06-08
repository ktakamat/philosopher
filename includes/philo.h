/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:52:57 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/30 18:33:28 by ktakamat         ###   ########.fr       */
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

# define ERROR_CREATE_PTHREAD "pthread fail\n"
# define MES_DIED "%ld %d died\n"
# define MES_TAKE_LEFT_FORK "%ld %d has taken a fork\n"
# define MES_TAKE_RIGHT_FORK "%ld %d has taken a fork\n"
# define MES_EATTING "%ld %d is eating\n"
# define ERROR_MES_FAILD_INIT "Initializtion faild\n"
# define SUCCESS 0
# define ERROR 1
# define MES_SLEEPING "%ld %d is sleeping\n"
# define MES_THINKING "%ld %d is thinking\n"

typedef struct s_config {
	long	n_philos;
	long	die_time;
	long	eat_time;
	long	sleep_time;
	long	eat_count;
}	t_config;

typedef struct s_table {
	pthread_mutex_t	get_data;
	pthread_mutex_t	print_message;
	t_config		config;
	int				n_philos_ate;
	long			start_time;
	bool			is_dead;
	bool			is_success;
	bool			is_error;
}	t_table;

typedef struct s_fork{
	pthread_mutex_t	n_fork;
	int				l_e_philo;
}	t_fork;

typedef struct s_philo {
	int			id;
	t_fork		*r_fork;
	t_fork		*l_fork;
	int			n_ate;
	t_table		*table;
	long		l_e_time;
	pthread_t	living;
	int			state;
}	t_philo;

bool	check_num(char *str);
int		assign_time(int argc, char **argv, t_config *config);
int		l_e_philo(t_fork *fork);
bool	already_dead(t_table *table);
bool	get_success(t_table *table);
bool	check_died(t_philo *philo);
void	time_eat(t_philo *philos);
void	eating(t_philo *philos);
t_fork	**create_forks(int n_philos);
t_fork	*new_fork(void);
void	delete_fork(t_fork *fork);
void	delete_forks(t_fork **forks);
int		ft_isspace(const char c);
long	ft_long(const char *str, int sign);
long	ft_atoi(const char *str);
t_philo	*new_philo(size_t id, t_fork *l_fork, t_fork *r_fork, t_table *table);
t_table	*new_table(t_config config);
void	delete_philos(t_philo **philos, int index);
void	delete_table(t_table *table);
t_philo	**create_philos(t_fork **forks, t_table *table);
int		start_simulation(t_philo **philos);
long	get_start_time(t_table *table);
int		end_simulation(t_philo **philos, int index);
void	sleeping(t_philo *philos);
void	thinking(t_philo *philo);
long	time_get(void);
long	time_pass(long start_usec);
void	time_sleep(t_philo *philo, long end_time);
void	print_info(t_philo *philos, char *print_message);
size_t	ft_strlen(const char *str);
void	dying_message(t_philo *philos);
bool	get_error(t_table *table);

#endif
