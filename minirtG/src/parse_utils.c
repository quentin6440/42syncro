#include "../include/minirt.h"

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

t_vec3	ft_str_to_vec3(char *str)
{
	char	**split;
	t_vec3	vec;

	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		ft_free_tab(split);
		return (vec_new(0, 0, 0)); // Traiter l'erreur de format au parsing
	}
	vec.x = ft_str_to_float(split[0]);
	vec.y = ft_str_to_float(split[1]);
	vec.z = ft_str_to_float(split[2]);
	ft_free_tab(split);
	return (vec);
}

int	ft_parse_line(char **tokens, t_scene *scene)
{
	if (!tokens || !tokens[0])
		return (0);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		return (ft_parse_ambient(tokens, scene));
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		return (ft_parse_camera(tokens, scene));
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		return (ft_parse_light(tokens, scene));
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (ft_parse_sphere(tokens, scene));
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (ft_parse_plane(tokens, scene));
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (ft_parse_cylinder(tokens, scene));
	ft_putstr_fd("Error\nUnknown identifier in .rt file\n", 2);
	return (-1);
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
		i++;
	}
	free(tab);
}