/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micor_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:39:09 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/21 18:28:09 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct s_data
{
	int	width;
	int	height;
	char	*matrice;
	char	backgraund;
}	t_data;

typedef	struct	s_rectagle
{
	char	mode;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}	t_rectagle;

int	init_data(t_data *data, FILE *file)
{
	if (fscanf(file, "%d %d %c\n", &data->width, &data->height, &data->backgraund) != 3)
		return (1);
	if (data->width <= 0 || data->width > 300 || data->height <= 0 || data->height > 300)
		return (1);
	if (!(data->matrice = malloc(sizeof(char) * (data->width * data->height))))
		return (1);
	memset(data->matrice, data->backgraund, data->width * data->height);
	return (0);
}

int	is_ret(float x, float y, t_rectagle rect)
{
	if (x < rect.x || rect.x + rect.width < x || y < rect.y || rect.y + rect.height < y)
		return (0);
	if (rect.mode == 'R')
		return (1);
	if (x - rect.x < 1.00000000 || rect.x + rect.width - x < 1.00000000 || y - rect.y < 1.00000000 || rect.y + rect.height - y < 1.00000000)
		return (1);
	return (0);
}

int	process(t_data *data, FILE *file)
{
	t_rectagle rect;
	int	x;
	int	y;


	while(fscanf(file, "%c %f %f %f %f %c\n", &rect.mode, &rect.x, &rect.y, &rect.width, &rect.height, &rect.color) == 6)
	{
		if((rect.mode != 'r' && rect.mode != 'R') || rect.width <= 0.00000000 || rect.height <= 0.00000000)
			return (1);
		x = 0;
		while (x < data->width)
		{
			y = 0;
			while (y < data->height)
			{
				if(is_ret((float)x, (float)y, rect))
					data->matrice[y * data->width + x] = rect.color;
				y++;
			}
			x++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;
	FILE *file;
	int	y;

	y = 0;
	if (argc != 2)
		return (write(1, "Error: argument\n", 16), 1);
       if (!(file = fopen(argv[1], "r")) || init_data(&data, file))	       
	       return (write(1, "Error: Operation file corrupetd\n", 32), 1);
       if(process(&data, file))
	       return (free(data.matrice), fclose(file), write(1, "Error: Operation file corrupted\n", 32), 1);
       while (y < data.height)
       {
	       write(1, y * data.width + data.matrice, data.width);
	       write(1, "\n", 1);
	       y++;
       }
       return (free(data.matrice), fclose(file), 0);
}
