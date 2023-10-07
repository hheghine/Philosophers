/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:57:24 by hbalasan          #+#    #+#             */
/*   Updated: 2023/10/07 23:40:06 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <time.h>
# include <stdint.h>
# include <stdbool.h>

# define TAKE_FORK_R "has taken the right fork"
# define TAKE_FORK_L "has taken the left fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

struct	s_data;

typedef struct s_philo
{
	int				id;
	// int				*is_dead;
	int				meal_count;
	uint64_t		last_eat;
	pthread_t		philo;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	// pthread_mutex_t	*mutex_die;
	// pthread_mutex_t	*mutex_print_msg;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_meal_count;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				eat_limit;
	int				is_dead;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_print_msg;
}	t_data;

//____________________________________________________/philo_input_check.c/
void		input_check(int argc, char **argv);
void		ft_error(char *str);
//____________________________________________________/philo_init.c/
void		data_init(int argc, char **argv, t_data *data);
//____________________________________________________/philo_time.c/
uint64_t	ft_gettime(void);
void		ft_usleep(t_philo *philo, uint64_t sleep_time);
//____________________________________________________/philo_activities.c/
void		*routine(void *info);
//____________________________________________________/philo_monitoring.c/
bool		die_check(t_data *data);
bool		eat_limit_check(t_data *data);
//____________________________________________________/philo_rip.c/
int			is_dead(t_philo *philo);
void		rip_philos(t_data *data);
//____________________________________________________/philo_utils.c/
void		ft_print(t_philo *philo, char *str, uint64_t time);
int			ft_strlen(const char *str);
int			is_all_num(const char *str);
int			ft_atoi(const char *str);

#endif