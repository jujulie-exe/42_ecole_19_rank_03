/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:28:09 by jfranco           #+#    #+#             */
/*   Updated: 2025/01/10 20:15:15 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	skip_whitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

long long	over_flow(long long result, char digit, int sign)
{
	if (result > (LLONG_MAX - (digit - '0')) / 10)
	{
		if (sign == 1)
			return (LLONG_MAX);
		else
			return (LLONG_MIN);
	}
	return (result);
}

int	get_sign(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

long long	ft_atol(const char *str)
{
	size_t			i;
	long long		sign;
	long long		result;

	i = skip_whitespace(str);
	result = 0;
	sign = get_sign(str, &i);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = over_flow(result, str[i], sign);
		if (result == LLONG_MAX || result == LLONG_MIN)
			return (result);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
