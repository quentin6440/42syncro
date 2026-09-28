/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 17:37:31 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	ft_parse_unique(char **tokens, t_scene *scene,
		t_parse_error *error, int *seen,
		int (*parser)(char **, t_scene *, t_parse_error *))
{
	if (*seen)
		return (ft_parse_fail(error, "duplicate scene element"));
	if (parser(tokens, scene, error) < 0)
		return (-1);
	*seen = 1;
	return (0);
}

static int	ft_parse_global(char **tokens, t_scene *scene,
		t_parse_error *error)
{
	if (tokens[0][0] == 'A' && tokens[0][1] == '\0')
		return (ft_parse_unique(tokens, scene, error,
				&scene->has_ambient, ft_parse_ambient));
	if (tokens[0][0] == 'C' && tokens[0][1] == '\0')
		return (ft_parse_unique(tokens, scene, error,
				&scene->has_camera, ft_parse_camera));
	if (tokens[0][0] == 'L' && tokens[0][1] == '\0')
		return (ft_parse_unique(tokens, scene, error,
				&scene->has_light, ft_parse_light));
	return (1);
}

int	ft_parse_line(char **tokens, t_scene *scene,
		t_parse_error *error)
{
	int	result;

	if (!tokens || !tokens[0] || !scene)
		return (ft_parse_fail(error, "invalid scene line"));
	result = ft_parse_global(tokens, scene, error);
	if (result != 1)
		return (result);
	if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (ft_parse_obj(tokens, scene, SPHERE, error));
	if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (ft_parse_obj(tokens, scene, PLANE, error));
	if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (ft_parse_obj(tokens, scene, CYLINDER, error));
	return (ft_parse_fail(error, "unknown scene element"));
}