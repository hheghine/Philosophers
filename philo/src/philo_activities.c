/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:29:44 by hbalasan          #+#    #+#             */
/*   Updated: 2023/12/03 21:54:19 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pick_forks(t_philo *philo)
{
	if (philo->id == philo->data->nb_philo) // && != 1
	{
		pthread_mutex_lock(philo->r_fork);
		ft_print(philo, TAKE_FORK_R, ft_gettime());
		pthread_mutex_lock(philo->l_fork);
		ft_print(philo, TAKE_FORK_L, ft_gettime());
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		ft_print(philo, TAKE_FORK_L, ft_gettime());
		pthread_mutex_lock(philo->r_fork);
		ft_print(philo, TAKE_FORK_R, ft_gettime());
	}
}

void	philo_activity(t_philo *philo)
{
	while (!is_dead(philo))
	{
		pick_forks(philo);
		ft_print(philo, EAT, ft_gettime());
		pthread_mutex_lock(&philo->mutex_last_eat);
		philo->last_eat = ft_gettime();
		pthread_mutex_unlock(&philo->mutex_last_eat);
		ft_usleep(philo, philo->data->time_to_eat);
		ft_print(philo, SLEEP, ft_gettime());
		pthread_mutex_lock(&philo->mutex_meal_count);
		philo->meal_count++;
		pthread_mutex_unlock(&philo->mutex_meal_count);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		ft_usleep(philo, philo->data->time_to_sleep);
		ft_print(philo, THINK, ft_gettime());
	}
}

void	*routine(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	pthread_mutex_lock(&philo->mutex_last_eat);
	philo->last_eat = ft_gettime();
	pthread_mutex_unlock(&philo->mutex_last_eat);
	if (philo->id % 2 == 0)
		usleep(1000);
	philo_activity(philo);
	philo->finished = 1;
	return (0);
}