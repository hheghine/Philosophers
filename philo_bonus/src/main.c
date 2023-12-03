/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:47:53 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/30 22:48:53 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_philos	*philos;

	if (argc < 5 || argc > 6)
		return (quit(E_ARGSUM, NULL));
	philos = init_philos();
	if (!philos)
		return (EXIT_FAILURE);
	if (parse_args(argv, philos))
		return (EXIT_FAILURE);
	if (philos_routine(philos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}