/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:20:51 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/14 16:05:50 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

time_t	get_time_stmp(const time_t time_start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec * 1000) + (now.tv_usec / 1000)) - time_start);
}

void	stamp_time(char *str, t_philo *philo, time_t time)
{
	time_t	stmp;
	stmp = get_time_stmp(time);
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ", stmp);
	printf("%d ", philo->id);
	printf("%s\n", str);
	pthread_mutex_unlock(&philo->data->print);
}
void	ft_usleep(time_t time_in_ms)
{
	time_t	start_time;

	start_time = get_time_stmp(0);
	while ((get_time_stmp(0) - start_time < time_in_ms))
		usleep(time_in_ms / 10);
}

void	thinking(t_philo *philo, time_t time)
{
	int	thinking;

	thinking = philo->time_thinking;
	ft_usleep(thinking);	
	stamp_time("is thinking", philo, time);
}

void	eating(t_philo *philo, time_t time)
{

	stamp_time("is eating", philo, time);
	ft_usleep(philo->time_eat);
	pose_fork(philo);
}

void	sleeping(t_philo *philo, time_t time)
{
	stamp_time("is sleeping", philo, time);
	ft_usleep(philo->time_sleep);
}

void	take_a_fork(t_philo *philo, time_t time)
{
	stamp_time("has taken a fork", philo, time);
}

/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
