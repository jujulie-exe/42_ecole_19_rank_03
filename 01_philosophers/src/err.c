
#include "philo.h"

int	err_argv(void)
{
	printf("Error: Invalid arguments. Please ensure the following conditions:\n");
	printf("1. The number of philosophers must be greater than 0 and less than or equal to 800.\n");
	printf("2. Time to die, time to sleep, and time to eat must be valid positive integers within the acceptable range.\n");
	printf("3. Values cannot exceed the maximum allowable integer size (INT_MAX).\n");
	return(1);
}

int	numeric(char **str)
{
	size_t	i;
	size_t	e;

	e = 0;
	i = 0;
	while(str[e][i])
	{
		i = 0;
		while(str[e][i] != '\0')
		{
			if(str[e][i] > '9' || str[e][i] < '0')
				return (1);
			i++;
		}
	e++;
	}
	return (0);
}

int	check_argv(char **argv)
{
	if(numeric(argv) == 1)
		return(1);
	if (ft_atol(argv[1]) > MAX_PHILO || argv[1] < 1)
		return(1);
	if (ft_atol(argv[2]) > INT_MAX)
		return(1);
	if (ft_atol(argv[4]) > INT_MAX)
		return(1);
	if (ft_atol(argv[3]) > INT_MAX)
		return(1);
	if (argv[5] && (ft_atol(argv[5]) > INT_MAX))
		return(1);
	return (0);
}

