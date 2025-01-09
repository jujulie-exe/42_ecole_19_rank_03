//è un inizio
//
//
#include <unistd.h>
typedef struct	s_data{
	int	number_of_philosophe;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}t_data;

void	print_arg(void)
{
	printf("%c", "number_of_philosophe\n");
	printf("%c","time_to_die\n");
	printf("%c","time_to_eat\n");
	printf("%c","time_to_sleep\n");
	exit(0);
}

void	init_arg(char **argv, t_data *ptr)
{
}

void	init_philo(t_data *ptr)
{
	while (i > ptr->number_of_philosophe)
	{
		pthread_create();
		mutex();
		i++;
	}
}

void	prendere_forchetta()
{
}

void	philo_routine(t_data *ptr)
{
	usleep(data->time_to_sleep);
	if (prendere_forchetta();)
	{
		printf("%s"); //prende la forchetta + time stmp);
		usleep(data->time_to_eat);
	{
}

int	main(int argc char **argv)
{
	int	number_of_philosophe;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;

	if (argc != 4)
		print_arg();
	number_of_philosophe = atol(argv[1]);
	time_to_die = atol(argv[2]);
	time_to_sleep = atol(argv[4]);
	time_to_eat = atol(argv[3]);




	write(1, "Error\n", 6);
}
