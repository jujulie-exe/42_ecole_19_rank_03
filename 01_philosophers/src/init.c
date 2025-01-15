/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:30 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/14 15:34:47 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

void	init_arg(char **argv, t_data *data)
{
	struct timeval start;

	gettimeofday(&start, NULL);
	data->number_of_philosophe = ft_atol(argv[1]);
	printf("Number of philosophers: %d\n", data->number_of_philosophe);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->time_to_eat = ft_atol(argv[3]);
	usleep(15);
	data->time_to_thinking = (data->time_to_die - (data->time_to_sleep + data->time_to_eat));
	data->time_start = start.tv_sec * 1000 + start.tv_usec / 1000;
	if (argv[5])
		data->number_of_times = ft_atol(argv[5]);
	else
		data->number_of_times = INT_MIN;
}

void	init_struct_philo(t_data *data, t_philo *philo)
{
	philo->data = data;
	philo->time = data->time_start;
	philo->time_sleep = data->time_to_sleep;
	philo->time_eat = data->time_to_eat;
	philo->time_die = data->time_to_die;
	philo->time_thinking = data->time_to_thinking;
	philo->last_meal_time = get_time_stmp();
}

int	init_alloc(t_data *data)
{
	data->threads = (pthread_t *)malloc(data->number_of_philosophe  * sizeof(pthread_t));
		if (data->threads == NULL)
			return (1);
	data->philo =((t_philo *)malloc(data->number_of_philosophe * sizeof(t_philo)));
		if(data->philo == NULL)
			return (1);
	return (0);

}
/*static void forkettine(t_philo *philo, pthread_mutex_t *forks, int nb_philos)
{
    if (philo->id == nb_philos) // L'ultimo filosofo
    {
        philo->first_fork = &forks[philo->id - 1];           // Fork destro
        philo->second_fork = &forks[0];                     // Fork sinistro (prima forchetta)
    }
    else if (philo->id % 2 == 0)
    {
        philo->first_fork = &forks[philo->id - 1];          // Fork destro
        philo->second_fork = &forks[philo->id % nb_philos]; // Fork sinistro
    }
    else
    {
        philo->first_fork = &forks[philo->id % nb_philos];  // Fork sinistro
        philo->second_fork = &forks[philo->id - 1];         // Fork destro
    }
}*/

static void forkettine(t_philo *philo, pthread_mutex_t *forks, int nb_philos)
{

	else if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo->id - 1];                  // Fork destro
		philo->second_fork = &forks[philo->id % nb_philos];        // Fork sinistro
	}
	else
	{
		philo->first_fork = &forks[philo->id % nb_philos];         // Fork sinistro
		philo->second_fork = &forks[philo->id - 1];               // Fork destro
	}
}


int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	if (init_alloc(data) == 1)
		return (1);
	while (i < data->number_of_philosophe)
	{
		data->philo[i].id = i + 1;
		init_struct_philo(data, &data->philo[i]);
		forkettine(&data->philo[i], data->forks, data->number_of_philosophe);
		i++;
	}
	return (0);
}
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
int init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *) malloc (data->number_of_philosophe * sizeof(pthread_mutex_t));
		if (data->forks == NULL)
			return (1);
	while (i < data->number_of_philosophe)
	{
	 	pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->print, NULL);
//	pthread_mutex_init(&data->deat, NULL);
//	pthread_mutex_init(&data->monitoring, NULL);

	return (0);
}
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
