#include "../include/minirt.h"
/*
static double	ft_get_fractional(char *str)
{
	double	fract;
	double	divisor;
	int		i;

	fract = 0.0;
	divisor = 10.0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		fract += (str[i] - '0') / divisor;
		divisor *= 10.0;
		i++;
	}
	return (fract);
}

double	ft_str_to_float(char *str)
{
	double	result;
	double	sign;
	int		i;

	if (!str)
		return (0.0);
	i = 0;
	sign = 1.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	result = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		result += ft_get_fractional(&str[i + 1]);
	return (result * sign);
}
*/
static double	ft_get_num(char *str, int *i)
{
	double	num;
	double	divisor;

	num = 0.0;
	divisor = 10.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num += (str[*i] - '0') / divisor;
		divisor *= 10.0;
		(*i)++;
	}
	return (num);
}

int	ft_str_to_float(char *str, double *out)
{
	double	result;
	double	sign;
	int		i;

	if (!str || !out || !*str)
		return (1);
	i = 0;
	sign = 1.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	if (!str[i] || (str[i] < '0' && str[i] > '9' && str[i] != '.'))
		return (1);
	result = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		if (result > 1e6)
			return (1);
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		result += ft_get_num(str, &i);
	}
	if (str[i] != '\0')
		return (1);
	*out = result * sign;
	return (0);
}

int	ft_str_to_vec3(char *str, t_vec3 *vec, int is_dir)
{
	char	**split;

	if (!str || !vec)
		return (1);
	split = ft_split(str, ',');
	if (!split)
		return (1);
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (ft_free_tab(split), 1);
	if (ft_str_to_float(split[0], &vec->x) != 0
		|| ft_str_to_float(split[1], &vec->y) != 0
		|| ft_str_to_float(split[2], &vec->z) != 0)
		return (ft_free_tab(split), 1);
	ft_free_tab(split);
	if (is_dir)
	{
		if (vec->x < -1.0 || vec->x > 1.0 || vec->y < -1.0 || vec->y > 1.0
			|| vec->z < -1.0 || vec->z > 1.0)
			return (1);
		if (vec->x == 0.0 && vec->y == 0.0 && vec->z == 0.0)
			return (1); // Vecteur direction (0,0,0) interdit !
	}
	return (0); // Succès
}

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}