/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:22:19 by ktakamat          #+#    #+#             */
/*   Updated: 2024/05/25 18:17:02 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philos)
{
	print_info(philos, MES_THINKING);
	while ((philos->id == l_e_philo(philos->r_fork)
			|| philos->id == l_e_philo(philos->l_fork)))
	{
		if (check_died(philos))
			break ;
		usleep(300);
	}
}
