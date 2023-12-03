/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:53:01 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/30 23:01:38 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	print_msg(t_philos *philos, t_philo *philo, char *msg, int flag)
{
	uint64_t	time;

	sem_wait(philos->end);
	time = ft_gettime();
	if (flag == FLG_EAT)
	{
		philo->last_meal = time;
		philo->eat_lim++;
	}
	if (!philos->die_flag)
	{
		sem_wait(philos->print);
		printf("[%lu ms] %i %s\n", time, (philo->id + 1), msg);
		// printf("[%llu ms] %i %s\n", time, (philo->id + 1), msg);
		sem_post(philos->print);
	}
	if (philos->limits->eat_lim != -1
		&& philos->limits->eat_lim == philo->eat_lim)
	{
		sem_post(philos->forks);
		sem_post(philos->forks);
		sem_post(philos->end);
		return (EXIT_FAILURE);
	}
	sem_post(philos->end);
	return (EXIT_SUCCESS);
}

void	print_death_msg(t_philos *philos, t_philo *philo, uint64_t time)
{
	sem_wait(philos->print);
	philos->die_flag = 1;
	printf("[%lu ms] %i %s\n", time, (philo->id + 1), MSG_DIE);
	// printf("[%llu ms] %i %s\n", time, (philo->id + 1), MSG_DIE);
	sem_post(philos->finish);
}