/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 12:55:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:33:17 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	ft_parse_ambient(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || tokens[3])
		return (ft_putstr_fd("Error\nBad Ambient format\n", 2), -1);
	if (ft_str_to_float(tokens[1], &scene->ambient.ratio) != 0)
		return (ft_putstr_fd("Error\nBad Ambient ratio\n", 2), -1);
	if (scene->ambient.ratio < 0.0 || scene->ambient.ratio > 1.0)
		return (ft_putstr_fd("Error\nAmbient ratio out of bounds\n", 2), -1);
	if (ft_str_to_vec3(tokens[2], &scene->ambient.color, 0) != 0)
		return (ft_putstr_fd("Error\nBad Ambient color\n", 2), -1);
	return (0);
}

int	ft_parse_camera(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (ft_putstr_fd("Error\nBad Camera format\n", 2), -1);
	if (ft_str_to_vec3(tokens[1], &scene->camera.pos, 0) != 0)
		return (ft_putstr_fd("Error\nBad Camera pos\n", 2), -1);
	if (ft_str_to_vec3(tokens[2], &scene->camera.dir, 1) != 0) // 1 = direction [-1, 1]
		return (ft_putstr_fd("Error\nBad Camera direction\n", 2), -1);
	scene->camera.dir = vec_normalize(scene->camera.dir);
	if (ft_str_to_float(tokens[3], &scene->camera.fov) != 0)
		return (ft_putstr_fd("Error\nBad Camera FOV\n", 2), -1);
	if (scene->camera.fov < 0.0 || scene->camera.fov > 180.0)
		return (ft_putstr_fd("Error\nCamera FOV out of bounds\n", 2), -1);
	return (0);
}

int	ft_parse_light(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (ft_putstr_fd("Error\nBad Light format\n", 2), -1);
	if (ft_str_to_vec3(tokens[1], &scene->light.pos, 0) != 0)
		return (ft_putstr_fd("Error\nBad Light pos\n", 2), -1);
	if (ft_str_to_float(tokens[2], &scene->light.ratio) != 0)
		return (ft_putstr_fd("Error\nBad Light ratio\n", 2), -1);
	if (scene->light.ratio < 0.0 || scene->light.ratio > 1.0)
		return (ft_putstr_fd("Error\nLight ratio out of bounds\n", 2), -1);
	if (ft_str_to_vec3(tokens[3], &scene->light.color, 0) != 0)
		return (ft_putstr_fd("Error\nBad Light color\n", 2), -1);
	return (0);
}