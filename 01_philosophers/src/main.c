/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:21:28 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/11 17:08:59 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_arg(void)
{
	printf("%s", "number_of_philosophe\n");
	printf("%s","time_to_die\n");
	printf("%s","time_to_eat\n");
	printf("%s","time_to_sleep\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (1);
	if (check_argv(argv) == 1)
		return (err_argv());
	init_all(&data, argv);
	lanch_tread(&data);
	finish_threads(&data);
}
