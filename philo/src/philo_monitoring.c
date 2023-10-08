/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:16:19 by hbalasan          #+#    #+#             */
/*   Updated: 2023/10/09 00:52:31 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	die_check(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philos[i].mutex_last_eat);
		if (ft_gettime() - data->philos[i].last_eat > data->time_to_die)
		{
			pthread_mutex_lock(&data->mutex_die);
			data->is_dead = 1;
			pthread_mutex_unlock(&data->mutex_die);
			pthread_mutex_lock(&data->mutex_print_msg);
			printf("[%lu ms] %d %s\n", ft_gettime(), (i + 1), DIED);
			pthread_mutex_unlock(&data->mutex_print_msg);
			pthread_mutex_unlock(&data->philos[i].mutex_last_eat);
			return (true);
		}
		pthread_mutex_unlock(&data->philos[i].mutex_last_eat);
	}
	return (false);
}

bool	eat_limit_check(t_data *data)
{
	int	i;

	i = -1;
	while (data->eat_limit != -1 && ++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philos[i].mutex_meal_count);
		if (data->philos[i].meal_count < data->eat_limit)
		{
			pthread_mutex_unlock(&data->philos[i].mutex_meal_count);
			break;
		}
		pthread_mutex_unlock(&data->philos[i].mutex_meal_count);
	}
	if (i == data->nb_philo)
	{
		pthread_mutex_lock(&data->mutex_die);
		data->is_dead = 1;
		pthread_mutex_unlock(&data->mutex_die);
		return (true);
	}
	return (false);
}
