/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:15:48 by hbalasan          #+#    #+#             */
/*   Updated: 2023/10/07 23:26:40 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/////////////////////////////////////////////////////////////////////
// struct    timeval  {											   //
//   time_t			tv_sec ;   //used for seconds				   //
//   suseconds_t	tv_usec ;   //used for microseconds			   //
// }															   //
/////////////////////////////////////////////////////////////////////
// int gettimeofday ( struct timeval *tp ,  struct timezone *tz )  //
// since 00:00:00, January 1, 1970 (Unix Epoch)				       //
/////////////////////////////////////////////////////////////////////

void	ft_usleep(t_philo *philo, uint64_t sleep_time)
{
	uint64_t	start;

	start = ft_gettime();
	while (!is_dead(philo))
	{
		if (ft_gettime() - start >= sleep_time)
			break;
		usleep(50);
	}
}

uint64_t	ft_gettime(void)
{
	struct timeval	timeval;
	static uint64_t	start;
	static int		count;
	
	if (count == 0)
	{
		gettimeofday(&timeval, NULL);
		start = (timeval.tv_sec * (uint64_t)1000) + (timeval.tv_usec / 1000);
		count++;
	}
	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * (uint64_t)1000) + (timeval.tv_usec / 1000) - start);
}
