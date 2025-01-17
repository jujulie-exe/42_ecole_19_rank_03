/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:20:51 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/17 14:44:30 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

time_t	get_time_stmp(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec * 1000) + (now.tv_usec / 1000)));
}

void	stamp_time(char *str, t_philo *philo, time_t time)
{
	time_t	stmp;
	if (philo->data->is_dead == false)
	{
		
		pthread_mutex_lock(&philo->data->print);
		stmp = get_time_stmp() - time;
		printf("%ld ", stmp);
		printf("%d ", philo->id);
		printf("%s\n", str);
		pthread_mutex_unlock(&philo->data->print);
	}
}
int	ft_usleep(time_t time_in_ms)
{
	time_t	start_time;

	start_time = get_time_stmp();
	while ((get_time_stmp() - start_time < time_in_ms))
		usleep(500);
	return (0);
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
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
