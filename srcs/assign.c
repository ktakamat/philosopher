/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:50:20 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/30 16:51:04 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (true);
	return (false);
}

int	check_and_assign(char *arg, long *config_value)
{
	if (check_num(arg) == false)
		return (-1);
	*config_value = ft_atoi(arg);
	if (*config_value <= 0)
		return (-1);
	return (0);
}

int	assign_time(int argc, char **argv, t_config *config)
{
	if (argc != 5 && argc != 6)
		return (-1);
	if (check_and_assign(argv[1], &config->n_philos) == -1)
		return (-1);
	if (check_and_assign(argv[2], &config->die_time) == -1)
		return (-1);
	if (check_and_assign(argv[3], &config->eat_time) == -1)
		return (-1);
	if (check_and_assign(argv[4], &config->sleep_time) == -1)
		return (-1);
	if (argc == 6)
	{
		if (check_and_assign(argv[5], &config->eat_count) == -1)
			return (-1);
	}
	else
	{
		config->eat_count = -1;
	}
	return (0);
}
