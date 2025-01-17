/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:46:19 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/17 18:47:43 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *) malloc (data->number_of_philosophe
			* sizeof(pthread_mutex_t));
	if (data->forks == NULL)
		return (1);
	while (i < data->number_of_philosophe)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->deat, NULL);
	return (0);
}

int	init_all(t_data *data, char **argv)
{
	init_arg(argv, data);
	if (init_mutex(data) == 1)
		return (1);
	if (init_philo(data) == 1)
		return (2);
	return (0);
}
