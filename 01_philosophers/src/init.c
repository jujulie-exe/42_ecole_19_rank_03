/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:30 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/11 19:24:30 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(char **argv, t_data *data)
{
	struct timeval start;

	gettimeofday(&start, NULL);
	data->number_of_philosophe = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_thinking = (data->time_to_die - (data->time_to_sleep + data->time_to_eat));
	data->time_start = start.tv_sec * 1000 + start.tv_usec / 1000;
//	if (data->argv5 == true)
//		data->number_of_times = ft_atol(argv[5]);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->threads = (pthread_t *)malloc(data->number_of_philosophe * sizeof(pthread_t));
		if (data->threads == NULL)
    			exit(0);
	data->philo =((t_philo *)malloc(data->number_of_philosophe * sizeof(t_philo)));
		if(data->philo == NULL)
			exit(0);
	while (i < data->number_of_philosophe)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		if(i == data->number_of_philosophe - 1)
		{
			data->philo[i].first_fork = &data->forks[0];
			data->philo[i].second_fork = &data->forks[i];
		}
		else
		{
			data->philo[i].first_fork = &data->forks[i];
			data->philo[i].second_fork = &data->forks[i + 1];
		}
		pthread_create(&data->threads[i], NULL, philo_routine, &data->philo[i]);
		i++;
	}
	//pthread_create(&monitor_thread, NULL, monitor_routine,);
}

void init_fork(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *) malloc (data->number_of_philosophe *sizeof(pthread_mutex_t));
		if (data->forks == NULL)
			exit (0);
	while (i < data->number_of_philosophe)
	{
	 	pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}
