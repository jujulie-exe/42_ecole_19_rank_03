/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:09:42 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/17 16:34:45 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

int	pose_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	return (0);
}

int	take_a_fork_and_eat(t_philo *philo, time_t time)
{
	pthread_mutex_lock(philo->first_fork);
	stamp_time("has take a fork", philo, time);
	if (philo->data->number_of_philosophe == 1)
	{
		ft_usleep(philo->time_die + 3);
		pthread_mutex_unlock(philo->first_fork);
		return (1);
	}
	pthread_mutex_lock(philo->second_fork);
	stamp_time("has take a fork", philo, time);
	stamp_time("is eating", philo, time);
	ft_usleep(philo->time_eat);
	philo->last_meal_time = get_time_stmp();
	if (philo->data->number_of_times != INT_MIN)
		philo->number_of_time_to_eat++;
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	return (0);
}

void	*philo_routine(void *arg)
{
	time_t	time;
	t_philo	*philo;

	philo = (t_philo *) arg;
	time = philo->time;
	philo->last_meal_time = get_time_stmp();
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (philo->data->is_dead == false)
	{
		take_a_fork_and_eat(philo, time);
		if (philo->data->is_dead == true)
			break ;
		sleeping(philo, philo->time);
		if (philo->data->is_dead == true)
			break ;
		stamp_time("is thinking", philo, time);
		if (philo->data->is_dead == true)
			break ;
	}
	return (NULL);
}
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
