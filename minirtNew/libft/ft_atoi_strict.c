/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
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

int	ft_atoi_strict(char *str, int *out)
{
	int		i;
	long	value;

	if (!str || !out || !str[0])
		return (1);
	i = 0;
	value = 0;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (ft_is_digit(str[i]))
	{
		value = value * 10 + (str[i] - '0');
		if (value > 255)
			return (1);
		i++;
	}
	if (str[i] != '\0')
		return (1);
	*out = (int)value;
	return (0);
}