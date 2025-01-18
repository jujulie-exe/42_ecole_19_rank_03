/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:02:21 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/17 18:45:57 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

int	lanch_tread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		if (pthread_create(&data->threads[i], NULL,
				philo_routine, &data->philo[i]))
		{
			while (--i >= 0)
				pthread_join(data->threads[i], NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		if ((get_time_stmp() - data->philo[i].last_meal_time)
			> data->time_to_die)
		{
			stamp_time("is dead", &data->philo[i], data->time_start);
			data->is_dead = true;
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		if (data->number_of_times == data->philo[i].number_of_time_to_eat)
		{
			data->is_dead = true;
			pthread_mutex_lock(&data->deat);
			printf("%ld %d %s\n", get_time_stmp() - data->time_start,
				data->philo[i].id, "is full");
			pthread_mutex_unlock(&data->deat);
			return (1);
		}
		i++;
	}
	return (0);
}

int	monitor_thread(t_data *data)
{
	pthread_create(&data->monitor_thread, NULL, monitor_routine, (void *)data);
	pthread_detach(data->monitor_thread);
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *) arg;
	while (1)
	{
		if (is_dead(data) == 1 || is_full(data) == 1)
			break ;
	}
	return (NULL);
}
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
