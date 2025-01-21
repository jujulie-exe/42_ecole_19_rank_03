/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:03:40 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/21 16:37:27 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_data 
{
	int	width;
	int	height;
	char	*matrice;
	char	background;
}	t_data;

typedef struct s_circle
{
	char	mode;
	float	x;
	float	y;
	float	radius;
	char	color;
}	t_circle;

int	init_data(t_data *data, FILE *file)
{
	if (fscanf(file, "%d %d %c\n", &data->width, &data->height, &data->background) != 3)
		return (1);
	if (data->width <= 0 || data->width > 300 || data->height <= 0 || data->height > 300)
		return (1);
	if (!(data->matrice = malloc(sizeof(char) * (data->width * data->height))))
		return (1);
	memset(data->matrice, data->background, data->width * data->height);
	return (0);
}

int	is_circle(float x, float y, t_circle circle)
{
	float	distance;
	float	distance_sqrt;

	distance_sqrt = sqrt((x - circle.x) * (x - circle.x) + (y - circle.y) * (y -circle.y));
	distance = distance_sqrt - circle.radius;
	if (distance > 0.00000000)
		return (0);
	if (circle.mode == 'C')
		return (1);
	if (distance > -1.00000000)
		return (1);
	return (0);
}

int	process(t_data *data, FILE *file)
{
	t_circle circle;

	int	x;
	int	y;

	x = 0;
	while (fscanf(file, "%c %f %f %f %c\n", &circle.mode, &circle.x, &circle.y, &circle.radius, &circle.color) == 5)
	{
		if ((circle.mode != 'c' && circle.mode != 'C') || circle.radius<= 0.00000000)
			return (1);
		x = 0;
		while (x < data->width)
		{
			y = 0;
			while (y < data->height)
			{
				if (is_circle((float)x, (float)y, circle))
					data->matrice[y * data->width + x] = circle.color;
				y++;
			}
			x++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	FILE *file;
	t_data	data;

	int	y;

	y = 0;

	if (argc != 2)
		return (write(1, "Error: argument\n", 16), 1);
	if (!(file = fopen(argv[1], "r")) || init_data(&data, file))
		return (write(1, "Error: Operation file corrupted\n", 32), 1);
	if (process(&data, file))
		return (free(data.matrice), fclose(file), write(1, "Error: Operation file corrupeted\n", 32), 1);
	while (y < data.height)
	{
		write(1, y * data.width + data.matrice, data.width);
		write(1, "\n", 1);
		y++;
	}
	return (free(data.matrice), fclose(file), 0);
}

