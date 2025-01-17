/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:21:27 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/17 18:43:14 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/

#include "philo.h"

void	finish_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
}

int	err_argv(void)
{
	printf("Error: Invalid arguments. Please ");
	printf("ensure the following conditions:\n");
	printf("1. The number of philosophers must be");
	printf(" greater than 0 and less than or equal to 800.\n");
	printf("2. Time to die, time to sleep, and time to eat must be");
	printf(" valid positive integers within the acceptable range.\n");
	printf("3. Values cannot exceed the maximum ");
	printf("allowable integer size (INT_MAX).\n");
	return (1);
}

int	numeric(char **str)
{
	size_t	i;
	size_t	e;

	e = 0;
	i = 0;
	while (str[e])
	{
		i = 0;
		while (str[e][i] != '\0')
		{
			if (str[e][i] > '9' || str[e][i] < '0')
				return (1);
			i++;
		}
		e++;
	}
	return (0);
}

int	check_argv(char **argv)
{
	if (numeric(argv) == 1)
		return (1);
	if (ft_atol(argv[0]) > 200 || ft_atol(argv[0]) == 0)
		return (1);
	if (ft_atol(argv[1]) > INT_MAX || ft_atol(argv[1]) == 0)
		return (1);
	if (ft_atol(argv[2]) > INT_MAX || ft_atol(argv[2]) == 0)
		return (1);
	if (ft_atol(argv[3]) > INT_MAX || ft_atol(argv[3]) == 0)
		return (1);
	if (argv[4] && (ft_atol(argv[4]) > INT_MAX || ft_atol(argv[4]) == 0))
		return (1);
	return (0);
}

int	ft_extit_clean(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->deat);
	while (i < data->number_of_philosophe)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_unlock(&data->deat);
	pthread_mutex_destroy(&data->deat);
	if (data->forks != NULL)
		free(data->forks);
	if (data->philo != NULL)
		free(data->philo);
	if (data->threads != NULL)
		free(data->threads);
	return (0);
}
/*♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥*/
