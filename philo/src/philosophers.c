/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:23:56 by hbalasan          #+#    #+#             */
/*   Updated: 2023/10/07 23:13:33 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data  data;
	int		i;
	
	input_check(argc, argv);
	data_init(argc, argv, &data);
	i = -1;
	ft_gettime();
	while (++i < data.nb_philo)
		pthread_create(&data.philos[i].philo, NULL, &routine,
			(void *)&data.philos[i]);
	while (1)
		if (die_check(&data) || eat_limit_check(&data))
			break ;
	i = -1;
	while (++i < data.nb_philo && data.nb_philo != 1)
		pthread_join(data.philos[i].philo, NULL);
	rip_philos(&data);
	return (0);
}