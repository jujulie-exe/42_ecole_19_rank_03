
#include "philo.h"

void finish_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philosophe)
    {
        pthread_join(data->threads[i], NULL);
        i++;
    }
}

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
		i++;
	}
	if(pthread_create(&monitor_thread, NULL, monitor_routine))
		pthread_join(data->monitor_treah, NULL);
	return (0);
}

int	monitor_thread()
{
	pthread_create(&monitor_thread, NULL, monitor_routine, &data);
	return (0);
}

void	*monitor_routine(void *arg)
{
	int	i;

	while (data->is_dead)
	{
		
	}
}

int	is_dead(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->number_of_philosophe)
	{
		if((get_time_stmp() - data->philo[i]->last_meal_time)  > data->time_to_die)
		{
			stamp_time("is dead",data->philo[i], data->start_time);
			data->is_dead = true
			return (1);
		}
		i++;
	}
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
