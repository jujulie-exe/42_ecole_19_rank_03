/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:30 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/10 17:15:08 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(char **argv, t_data *data)
{
	data->number_of_philosophe = atol(argv[1]);
	data->time_to_die = atol(argv[2]);
	data->time_to_sleep = atol(argv[4]);
	data->time_to_eat = atol(argv[3]);
}

void	init_philo(t_philo *data)
{
	size_t	i;


	i = 0;
	data->philo =((t_philo *)malloc(data->number_of_philosophe * sizeof(t_philo)));
		if(philo == NULL)
			exit(0);
	while (i > data->number_of_philosophe)
	{
		data->philo[i].id = i + 1;
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
	pthread_create(&monitor_thread, NULL, monitor_routine,);
}

void	init_threads(void)
{
}

void init_fork(t_data *data)
{
	size_t	i;

	i = 0;
	data->fork = (pthread_mutex_t *) malloc (data->number_of_philosophe *sizeof(pthread_mutex_t))
		if (fork == NULL)
			exit (0);
	while (i < data->number_of_philosophe)
	 	pthread_mutex_init(&data->fork[i], NULL);
}
