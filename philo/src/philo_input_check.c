/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_input_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:57:52 by hbalasan          #+#    #+#             */
/*   Updated: 2023/10/09 01:00:28 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	is_correct_num(int argc, char **argv)
{
	int	i;
	
	if (ft_atoi(argv[1]) == 0)
		ft_error("\tNo philos?!\n");
	if (ft_atoi(argv[1]) > 200)
		ft_error("\tToo many philos\n");
	i = 1;
	while (++i < 5)
		if (ft_atoi(argv[i]) == 0)
			ft_error("\tZero is a bad argument\n");
	if (argc == 6)
		if (ft_atoi(argv[5]) <= 0)
			ft_error("\tNo food?!\n");
}

void	input_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		ft_error("\tWrong number of arguments\n");
	while (++i < argc)
		if (is_all_num(argv[i]))
			ft_error("\tInvalid arguments\n");
	is_correct_num(argc, argv);
}