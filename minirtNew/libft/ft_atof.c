/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 00:00:00 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atof(char *str, double *out)
{
	int		i;
	int		sign;
	int		digits;
	double	value;
	double	factor;

	if (!str || !out || !str[0])
		return (1);
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	value = 0.0;
	digits = 0;
	while (ft_is_digit(str[i]))
	{
		value = value * 10.0 + (str[i] - '0');
		if (value > 1000000.0)
			return (1);
		digits++;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		factor = 0.1;
		while (ft_is_digit(str[i]))
		{
			value += (str[i] - '0') * factor;
			factor *= 0.1;
			digits++;
			i++;
		}
	}
	if (!digits || str[i] != '\0')
		return (1);
	*out = value * sign;
	return (0);
}