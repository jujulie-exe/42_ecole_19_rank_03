/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:09:42 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/14 18:51:33 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

int pose_fork(t_philo *philo)
{
	if(pthread_mutex_unlock(philo->first_fork) != 0)
	if(pthread_mutex_unlock(philo->second_fork) != 0)
	return (0);
}

int	take_a_fork_and_eat(t_philo *philo, time_t time)
{
	
	if (pthread_mutex_lock(&philo->data->lock) != 0)
		return (1);
	if(pthread_mutex_lock(philo->first_fork) != 0)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	take_a_fork(philo, time);
	if (pthread_mutex_lock(philo->second_fork) != 0)
	{
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	take_a_fork(philo, time);
	pthread_mutex_unlock(&philo->data->lock);
	stamp_time("is eating", philo, time);
	ft_usleep(philo->time_eat);
	return (pose_fork(philo));
}

void	*philo_routine(void *arg)
{
	time_t	time;
	t_philo *philo = (t_philo *) arg;
	time = philo->time;

	if(philo->id % 2)
		ft_usleep(philo->time_eat);
	while (1)
	{
		if (take_a_fork_and_eat(philo, time) == 0)
			sleeping(philo, philo->time);
		thinking(philo,time);
		usleep(45);
	}
	return (NULL);
}


/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
