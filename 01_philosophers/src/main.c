/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:21:28 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/10 19:21:30 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//è un inizio
//
//
//

#include "philo.h"
void	print_arg(void)
{
	printf("%c", "number_of_philosophe\n");
	printf("%c","time_to_die\n");
	printf("%c","time_to_eat\n");
	printf("%c","time_to_sleep\n");
	exit(0);
}


void	prendere_forchetta(t_data *data)
{
	while (1 && data->simulation_running) //verificha se é morto***
	{
		pthread_mutex_lock(&data->philo[i].first_fork);
		pthread_mutex_lock(&data->philo[i].second_fork);
	}
}


int	main(int argc char **argv)
{
	t_data	data;
	t_philo	philo;

	if (argc != 4)
		print_arg();
	init_arg(&argc, data);
	write(1, "Error\n", 6);
}
