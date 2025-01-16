/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:58:08 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/16 12:56:17 by jfranco          ###   ########.fr       */
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
# include <stdatomic.h>


struct s_data;

typedef struct s_philo	{
	int		id;
	int		number_of_time_to_eat;
	time_t	last_meal_time;
	time_t	time;
	int	time_die;
	int	time_sleep;
	int	time_eat;
	int	time_thinking;
	struct s_data	*data;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
} t_philo;

typedef struct s_data {
	int	number_of_philosophe;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_times;
	long	time_to_thinking;
	time_t	time_start;
	volatile atomic_bool	is_dead;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	pthread_mutex_t	deat;
	pthread_mutex_t	monitoring;
	pthread_mutex_t	*forks;
	pthread_t	*threads;
	pthread_t	monitor_thread;
	t_philo	*philo;
} t_data;


//time.c    ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
time_t	get_time_stmp(void);
void	stamp_time(char *str, t_philo *philo, time_t time);
int	ft_usleep(time_t time);
//int	random_muber(t_philo *philo);
void	thinking(t_philo *philo, time_t time);
void	eating(t_philo *philo, time_t time);
void	sleeping(t_philo *philo, time_t time);
void	take_a_fork(t_philo *philo, time_t time);
//routine.c  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
int	take_a_fork_and_eat(t_philo *philo, time_t time);
int	pose_fork(t_philo *philo);
int	take_fork(t_philo *philo, time_t time);
void	*philo_routine(void *arg);
//init.c   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
int	init_philo(t_data *data);
int	init_mutex(t_data *data);
void	init_arg(char **argv, t_data *data);
//main.c   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
//ft_atol.c ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
long long	ft_atol(const char *str);
//threads.c  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
void	finish_threads(t_data *data);
void	*monitor_routine(void *arg);
int	init_all(t_data *data, char **argv);
int	monitor_thread(t_data *data);
int	lanch_tread(t_data *data);
//err.c  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥
int	check_argv(char **str);
int	err_argv(void);
int	ft_extit_clean(t_data *data);
#endif
