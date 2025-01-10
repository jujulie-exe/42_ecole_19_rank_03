/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:09:42 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/10 18:45:14 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

void	philo_routine(t_data *data)
{
	while (i < data->number_of_philoshoper)
	{
		usleep(45); //pensa
		if (take_fork(data->philo[i]))
		{
			usleep(data->time_to_eat);
			pose_fork();
		{
		usleep(data->time_to_sleep);
	}
}

int	take_fork(t_philo *philo)
{
	short	err;
	short	err2;
	short	tentativo;

	tentativo = 0;
	while (tentativi <= 2)
	{
		err = pthread_mutex_lock(philo->first_fork)
		err2 = pthread_mutex_lock(philo->second_fork)
		if (tentativo >= 2 && err < 0 || err2 < 0)
		{
			if(err < 0)
				pthread_mutex_unlock(philo->first_fork)
			else
				pthread_mutex_unlock(philo->second_fork)
		}
		if (err == 0 && err2 == 0)
			return (1);
		uslpeep(1000);
		tentativi++;
	}
	return (0);
}

int	pose_fork(t_data *data)
{
}
