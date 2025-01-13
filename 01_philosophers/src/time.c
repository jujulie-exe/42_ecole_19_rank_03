/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:20:51 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/11 19:27:04 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

time_t	get_time_stmp(const time_t time_start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000) - time_start);
}

void	stamp_time(char *str, t_philo *philo, time_t time)
{
	time_t	stmp;
	stmp = get_time_stmp(time);
	printf("%ld ", stmp);
	printf("%d ", philo->id);
	printf("%s\n", str);
}

int	random_muber(t_philo *philo)
{
	int	array[] = {30, 67, 38, 75, 25, 93, 53, 96, 80, 23, 40, 100, 12, 18, 9, 48};
	int	size;
	long long	random_index;

	size = sizeof(array) / sizeof(array[0]);
	random_index = get_time_stmp(philo->time) % size;
	if (random_index < 0 || random_index >= size)
		random_index = 0;	

	return (array[random_index]);
}

void	thinking(t_philo *philo, time_t time)
{
	int	thinking;

	thinking = philo->time_thinking;
	usleep(thinking);	
	stamp_time("is thinking", philo, time);
}

void	eating(t_philo *philo, time_t time)
{

	stamp_time("is eating", philo, time);
	usleep(philo->time_eat);
	pose_fork(philo);
}

void	sleeping(t_philo *philo, time_t time)
{
	stamp_time("is sleeping", philo, time);
	usleep(philo->time_sleep);
}

void	take_a_fork(t_philo *philo, time_t time)
{
	stamp_time("has taken a fork", philo, time);
}

/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
