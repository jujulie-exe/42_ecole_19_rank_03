/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:58:08 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/10 20:17:48 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_philo	{
	int		id;
	long	last_meal_time;
	t_data	*data;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
} t_philo;

typedef struct s_data {
	int	number_of_philosophe;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	bool	simulation_running;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_t	*threads;
	t_philo	*philosophers;
} t_data;


//time.c    ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
void	get_time_stmp(t_data *data);
//routine.c  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
void	philo_routine(t_data *data);
//init.c   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
void	init_arg(char **argv, t_data *data);
void	init_philo(t_philo *data);
void	init_fork(t_data *data);
//main.c   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
//ft_atol ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
long long	ft_atol(const char *str);
