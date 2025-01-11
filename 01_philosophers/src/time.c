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

void	stamp_time(char *str, t_philo *philo)
{
	time_t	stmp;
	stmp = get_time_stmp(philo->data->time_start);
	printf("%ld %s %d\n", stmp, str,philo->id);
}

int	random_muber(t_philo *philo)
{
	int	array[] = {30, 67, 38, 75, 25, 93, 53, 96, 80, 23, 40, 100, 12, 18, 9, 48};
	int	size;
	long long	random_index;

	size = sizeof(array) / sizeof(array[0]);
	random_index = get_time_stmp(philo->data->time_start) % size;
	if (random_index < 0 || random_index >= size)
		random_index = 0;	

	return (array[random_index]);
}

void	thinking(t_philo *philo)
{
	int	thinking;
//	int	mod;

	thinking = philo->data->time_to_thinking;
//	mod = random_muber(philo);
//	if (mod <= 0)
//		mod = 1;
	usleep(thinking);	
	stamp_time("thinking", philo);
}

void	eating(t_philo *philo)
{
	stamp_time("eating", philo);
	usleep(philo->data->time_to_eat);
	pose_fork(philo);
}

void	sleeping(t_philo *philo)
{
	stamp_time("sleeping", philo);
	usleep(philo->data->time_to_sleep);
}

void	take_a_fork(t_philo *philo)
{
	stamp_time("take a fork", philo);
}

/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
