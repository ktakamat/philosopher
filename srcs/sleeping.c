/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:22:45 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/30 16:51:35 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philos)
{
	if (philos->id == l_e_philo(philos->l_fork)
		&& philos->id == l_e_philo(philos->r_fork))
	{
		print_info(philos, MES_SLEEPING);
		time_sleep(philos, philos->table->config.sleep_time * 1000);
	}
}
