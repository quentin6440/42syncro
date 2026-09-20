#include "libft.h"
#include <math.h>

static double	ft_get_fraction(char *str, int *i)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	if (str[*i] == '.')
		(*i)++;
	while (str[*i] >= 48 && str[*i] <= 57)
	{
		fraction += (str[*i] - 48) / divisor;
		divisor *= 10.0;
		(*i)++;
	}
	return (fraction);
}

int	ft_atof(char *str, double *out)
{
	int		i;
	int		sign;
	double	integer_part;
	double	fraction_part;

	if (!str || !out)
		return (1);
	i = 0;
	sign = 1;
	integer_part = 0.0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i] || (str[i] < 48 && str[i] > 57 && str[i] != '.'))
		return (1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		integer_part = integer_part * 10.0 + (str[i] - '0');
		if (integer_part > 1e6) // Limite de sécurité pour éviter les floats géants
			return (1);
		i++;
	}
	fraction_part = ft_get_fraction(str, &i);
	if (str[i]) // S'il reste des caractères non lus (ex: "12.34a") -> ERREUR
		return (1);
	*out = (integer_part + fraction_part) * sign;
	return (0);
}