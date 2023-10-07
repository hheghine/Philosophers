/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:09:22 by hbalasan          #+#    #+#             */
/*   Updated: 2023/10/07 23:12:04 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meal_count = 0;
		data->philos[i].last_eat = 0;
		// data->philos[i].is_dead = &data->is_dead;
		// data->philos[i].mutex_die = &data->mutex_die;
		// data->philos[i].mutex_print_msg = &data->mutex_print_msg;
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].mutex_last_eat, NULL);
		pthread_mutex_init(&data->philos[i].mutex_meal_count, NULL);
	}
}

void	fork_init(t_data *data)
{
	int	i;

	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
					* data->nb_philo);
	if (!data->forks)
		ft_error("\tMalloc error\n");
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philos[i].l_fork = &data->forks[i];
		if (data->nb_philo != 1)
		{
			if (i == data->nb_philo - 1)
				data->philos[i].r_fork = &data->forks[0];
			else
				data->philos[i].r_fork = &data->forks[i + 1];
		}
		else
			data->philos[i].r_fork = &data->forks[0];
	}
}

void	data_init(int argc, char **argv, t_data *data)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		ft_error("\tMalloc error\n");
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->eat_limit = -1;
	if (argc == 6)
		data->eat_limit = ft_atoi(argv[5]);
	data->is_dead = 0;
	pthread_mutex_init(&data->mutex_die, NULL);
	pthread_mutex_init(&data->mutex_print_msg, NULL);
	fork_init(data);
	philo_init(data);
}
