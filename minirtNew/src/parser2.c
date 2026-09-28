/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 15:42:43 by qcyril-a         ###   ########.fr       */
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
int	ft_parse_line(char **tokens, t_scene *scene,
		t_parse_error *error)
{
	if (!tokens || !tokens[0] || !scene)
		return (ft_parse_fail(error, "invalid scene line"));

	if (ft_is_identifier(tokens[0], "A"))
	{
		if (scene->has_ambient)
			return (ft_parse_fail(error,
					"duplicate ambient element"));
		if (ft_parse_ambient(tokens, scene, error) < 0)
			return (-1);
		scene->has_ambient = 1;
		return (0);
	}
	if (ft_is_identifier(tokens[0], "C"))
	{
		if (scene->has_camera)
			return (ft_parse_fail(error,
					"duplicate camera element"));
		if (ft_parse_camera(tokens, scene, error) < 0)
			return (-1);
		scene->has_camera = 1;
		return (0);
	}
	if (ft_is_identifier(tokens[0], "L"))
	{
		if (scene->has_light)
			return (ft_parse_fail(error,
					"duplicate light element"));
		if (ft_parse_light(tokens, scene, error) < 0)
			return (-1);
		scene->has_light = 1;
		return (0);
	}
	if (ft_is_identifier(tokens[0], "sp"))
		return (ft_parse_obj(tokens, scene, SPHERE, error));
	if (ft_is_identifier(tokens[0], "pl"))
		return (ft_parse_obj(tokens, scene, PLANE, error));
	if (ft_is_identifier(tokens[0], "cy"))
		return (ft_parse_obj(tokens, scene, CYLINDER, error));
	return (ft_parse_fail(error, "unknown scene element"));
}
int	ft_parse_rt(int fd, t_scene *scene, t_parse_error *error)
{
	char	*raw_line;
	char	*clean_line;
	char	**tokens;
	int		result;
	int		line_number;

	if (fd < 0 || !scene || !error)
		return (-1);
	error->line = 0;
	error->message = NULL;
	line_number = 0;
	raw_line = get_next_line(fd);
	while (raw_line)
	{
		line_number++;
		clean_line = ft_strtrim(raw_line, " \t\r\n\v\f");
		free(raw_line);
		if (!clean_line)
		{
			error->line = line_number;
			return (ft_parse_fail(error, "memory allocation failed"));
		}
		if (clean_line[0] == '\0' || clean_line[0] == '#')
		{
			free(clean_line);
			raw_line = get_next_line(fd);
			continue ;
		}
		ft_normalize_spaces(clean_line);
		tokens = ft_split(clean_line, ' ');
		if (!tokens)
		{
			free(clean_line);
			error->line = line_number;
			return (ft_parse_fail(error, "memory allocation failed"));
		}
		result = ft_parse_line(tokens, scene, error);
		ft_free_tab(tokens);
		free(clean_line);
		if (result < 0)
		{
			error->line = line_number;
			return (-1);
		}
		raw_line = get_next_line(fd);
	}
	if (!scene->has_ambient
		|| !scene->has_camera
		|| !scene->has_light)
	{
		error->line = 0;
		return (ft_parse_fail(error,
				"missing mandatory scene element"));
	}
	return (0);
}