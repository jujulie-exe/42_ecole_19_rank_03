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

int	take_fork(t_philo *philo, time_t time)
{
	short	err;
	short	err2;
	short	tentativo;

	tentativo = 0;
	while (tentativo <= 2)
	{
		err = pthread_mutex_lock(philo->first_fork);
		err2 = pthread_mutex_lock(philo->second_fork);
		if (err == 0 || err2 == 0)
			take_a_fork(philo, time);
		if (tentativo >= 2 && (err < 0 || err2 < 0))
		{
			if(err < 0)
				pthread_mutex_unlock(philo->first_fork);
			else
				pthread_mutex_unlock(philo->second_fork);
		}
		if (err == 0 && err2 == 0)
			return (1);
		usleep(45);
		tentativo++;
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	int	i;
	t_philo *philo = (t_philo *) arg;
	time_t	time;

	time = philo->data->time_start;

	i = 0;
	while (1)
	{
		thinking(philo,time);
		if (take_fork(philo, time))
		{
			eating(philo, time);
			i++;
		}
		sleeping(philo, time);
	}
}


/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
