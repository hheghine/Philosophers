/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:51:42 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/30 22:52:18 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*free_single(void **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = 0;
	}
	return (0);
}

void	*free_all_mem(t_philos *philos)
{
	sem_close(philos->forks);
	sem_close(philos->print);
	sem_close(philos->finish);
	sem_close(philos->end);
	free_single((void *)&(philos->limits));
	free_single((void *)&(philos->philo_list));
	free_single((void *)&(philos));
	return (NULL);
}