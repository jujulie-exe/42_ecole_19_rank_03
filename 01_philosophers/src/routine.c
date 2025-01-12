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
	printf("pose fork %d \n", philo->id);
}

int	take_fork(t_philo *philo, time_t time)
{
	int	err;
	int	err2;
	size_t	tentativo;

	tentativo = 0;
	printf("qui4\n");
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
		usleep(random_muber(philo));
		tentativo++;
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	time_t	time;
	t_philo *philo = (t_philo *) arg;
	time = philo->time;
	

	while (1)
	{
		thinking(philo,time);
		printf("qui3\n");
		if (take_fork(philo, philo->time))
			eating(philo, philo->time);
		sleeping(philo, philo->time);
	}
}


/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
