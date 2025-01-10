/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:20:51 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/10 19:12:37 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time_stmp(t_data *data)
{
	struct timeval start;
	struct timeval	now;
	long long	time_start_mille;
	long long	time_now_mille;
	long long	stamp;

	gettimeofday(&start, NULL);
	time_start_mille = start.tv_sec * 1000 + start.tv_usec / 1000;
	gettimeofday(&now, NULL);
	time_now_mille = now.tv_sec * 1000 + now.tv_usec / 1000;
	stamp = time_start_mille - time_now_mille;
	printf("sono un time stamp",stamp);
}
