/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 00:00:00 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	ft_normalize_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			line[i] = ' ';
		i++;
	}
}

static int	ft_is_identifier(char *identifier, char *expected)
{
	return (ft_strncmp(identifier, expected, ft_strlen(expected) + 1) == 0);
}

int	ft_parse_line(char **tokens, t_scene *scene)
{
	if (!tokens || !tokens[0] || !scene)
		return (-1);
	if (ft_is_identifier(tokens[0], "A"))
	{
		if (scene->has_ambient)
			return (ft_putstr_fd("Error\nDuplicate ambient\n", 2), -1);
		if (ft_parse_ambient(tokens, scene) < 0)
			return (-1);
		scene->has_ambient = 1;
		return (0);
	}
	if (ft_is_identifier(tokens[0], "C"))
	{
		if (scene->has_camera)
			return (ft_putstr_fd("Error\nDuplicate camera\n", 2), -1);
		if (ft_parse_camera(tokens, scene) < 0)
			return (-1);
		scene->has_camera = 1;
		return (0);
	}
	if (ft_is_identifier(tokens[0], "L"))
	{
		if (scene->has_light)
			return (ft_putstr_fd("Error\nDuplicate light\n", 2), -1);
		if (ft_parse_light(tokens, scene) < 0)
			return (-1);
		scene->has_light = 1;
		return (0);
	}
	if (ft_is_identifier(tokens[0], "sp"))
		return (ft_parse_obj(tokens, scene, SPHERE));
	if (ft_is_identifier(tokens[0], "pl"))
		return (ft_parse_obj(tokens, scene, PLANE));
	if (ft_is_identifier(tokens[0], "cy"))
		return (ft_parse_obj(tokens, scene, CYLINDER));
	ft_putstr_fd("Error\nUnknown element\n", 2);
	return (-1);
}
int	ft_parse_rt(int fd, t_scene *scene)
{
	char	*raw_line;
	char	*clean_line;
	char	**tokens;
	int		result;

	if (fd < 0 || !scene)
		return (-1);
	raw_line = get_next_line(fd);
	while (raw_line)
	{
		clean_line = ft_strtrim(raw_line, " \t\r\n\v\f");
		free(raw_line);
		if (!clean_line)
			return (-1);
		if (clean_line[0] != '\0' && clean_line[0] != '#')
		{
			ft_normalize_spaces(clean_line);
			tokens = ft_split(clean_line, ' ');
			if (!tokens)
				return (free(clean_line), -1);
			result = ft_parse_line(tokens, scene);
			ft_free_tab(tokens);
			free(clean_line);
			if (result < 0)
				return (-1);
		}
		else
			free(clean_line);
		raw_line = get_next_line(fd);
	}
	if (!scene->has_ambient || !scene->has_camera || !scene->has_light)
	{
		ft_putstr_fd("Error\nMissing mandatory scene element\n", 2);
		return (-1);
	}
	return (0);
}