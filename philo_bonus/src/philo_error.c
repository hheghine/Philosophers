/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:50:17 by hbalasan          #+#    #+#             */
/*   Updated: 2023/12/01 02:08:54 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*mem_issue(t_philos *philos)
{
	ft_error("Error during malloc\n");
	free_all_mem(philos);
	exit(E_NOMEM);
	return (NULL);
}

int	quit(int errno, t_philos *philos)
{
	if (errno == E_NEGNUM)
		ft_error("Invalid value of arguments\n");
	else if (errno == E_ARGSUM)
		ft_error("Invalid number of arguments\n");
	else if (errno == E_PROCESS)
		ft_error("Error creating child process\n");
	else if (errno == E_THREAD)
		ft_error("Error creating thread\n");
	if (philos)
		free_all_mem(philos);
	exit(EXIT_FAILURE);
}