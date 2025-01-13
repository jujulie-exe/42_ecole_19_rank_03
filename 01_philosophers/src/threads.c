#include "philo.h"

int	lanch_tread(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		if(pthread_create(&data->threads[i], NULL, philo_routine, &data->philo[i]))
		{
			while (--i >= 0)
                		pthread_join(data->threads[i], NULL);
            		return (1);
		}
		usleep(100);
		i++;
	}
	return (0);
}

int	monitor_thread()
{
	//pthread_create(&monitor_thread, NULL, monitor_routine,);
	return (0);
}

int	init_all(t_data *data, char **argv)
{

	init_arg(argv, data);
	if (init_mutex(data) == 1)
		return (1);
	if (init_philo(data) == 1)
		return (2);
	return (0);
}
