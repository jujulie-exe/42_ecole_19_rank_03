/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:58:08 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/11 19:27:55 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>


struct s_data;

typedef struct s_philo	{
	int		id;
	int		number_of_time_to_eat;
	long	last_meal_time;
	struct s_data	*data;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
} t_philo;

typedef struct s_data {
	int	number_of_philosophe;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times;
	int	time_to_thinking;
	time_t	time_start;
	bool	argv5;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_t	*threads;
	t_philo	*philo;
} t_data;


//time.c    ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
time_t	get_time_stmp(const time_t time_start);
int	random_muber(t_philo *philo);
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	take_a_fork(t_philo *philo);
//routine.c  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
void	pose_fork(t_philo *philo);
int	take_fork(t_philo *philo);
void	*philo_routine(void *arg);
//init.c   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
void	init_arg(char **argv, t_data *data);
void	init_philo(t_data *data);
void	init_fork(t_data *data);
//main.c   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
//ft_atol ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
long long	ft_atol(const char *str);

#endif
