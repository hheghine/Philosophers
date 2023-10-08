/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:38:45 by hbalasan          #+#    #+#             */
/*   Updated: 2023/10/09 01:19:19 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	int	flag;
	
	pthread_mutex_lock(philo->mutex_die);
	flag = *(philo->is_dead);
	pthread_mutex_unlock(philo->mutex_die);
	return (flag);
}

void	rip_philos(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->mutex_die);
	pthread_mutex_destroy(&data->mutex_print_msg);
	while (++i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].mutex_last_eat);
		pthread_mutex_destroy(&data->philos[i].mutex_meal_count);
		pthread_mutex_destroy(&data->forks[i]);
	}
	free(data->philos);
	free(data->forks);
}