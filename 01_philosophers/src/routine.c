/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:09:42 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/11 19:20:59 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

void pose_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

int	take_a_fork_and_eat(t_philo *philo, time_t time)
{
	
	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_lock(philo->first_fork);
	take_a_fork(philo, time);
	pthread_mutex_lock(philo->second_fork);
	take_a_fork(philo, time);
	pthread_mutex_unlock(&philo->data->lock);
	stamp_time("is eating", philo, time);
	usleep(philo->time_eat);
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_unlock(philo->first_fork);
	return (0);
}

void	*philo_routine(void *arg)
{
	time_t	time;
	t_philo *philo = (t_philo *) arg;
	time = philo->time;

	if(philo->id % 2 == 0)
		usleep(philo->time_eat / 2);
	while (1)
	{
		if(take_a_fork_and_eat(philo, time) == 0)
		{
			sleeping(philo, philo->time);
			thinking(philo,time);
		}
		usleep(45);
	}
}


/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
