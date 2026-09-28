/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 00:00:00 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	ft_obj_add_back(t_obj **list, t_obj *new_obj)
{
	t_obj	*current;

	if (!list || !new_obj)
		return ;
	if (!*list)
	{
		*list = new_obj;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new_obj;
}

static int	ft_fill_sphere(t_obj *obj, char **tokens)
{
	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (-1);
	if (ft_str_to_vec3(tokens[1], &obj->pos, 0) != 0)
		return (-1);
	if (ft_str_to_float(tokens[2], &obj->diameter) != 0)
		return (-1);
	if (obj->diameter <= 0.0)
		return (-1);
	if (ft_str_to_color(tokens[3], &obj->color) != 0)
		return (-1);
	return (0);
}

static int	ft_fill_plane(t_obj *obj, char **tokens)
{
	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (-1);
	if (ft_str_to_vec3(tokens[1], &obj->pos, 0) != 0)
		return (-1);
	if (ft_str_to_vec3(tokens[2], &obj->dir, 1) != 0)
		return (-1);
	obj->dir = vec_normalize(obj->dir);
	if (ft_str_to_color(tokens[3], &obj->color) != 0)
		return (-1);
	return (0);
}

static int	ft_fill_cylinder(t_obj *obj, char **tokens)
{
	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3]
		|| !tokens[4] || !tokens[5] || tokens[6])
		return (-1);
	if (ft_str_to_vec3(tokens[1], &obj->pos, 0) != 0)
		return (-1);
	if (ft_str_to_vec3(tokens[2], &obj->dir, 1) != 0)
		return (-1);
	obj->dir = vec_normalize(obj->dir);
	if (ft_str_to_float(tokens[3], &obj->diameter) != 0)
		return (-1);
	if (obj->diameter <= 0.0)
		return (-1);
	if (ft_str_to_float(tokens[4], &obj->height) != 0)
		return (-1);
	if (obj->height <= 0.0)
		return (-1);
	if (ft_str_to_color(tokens[5], &obj->color) != 0)
		return (-1);
	return (0);
}

static int	ft_fill_obj_data(t_obj *obj, char **tokens)
{
	if (!obj || !tokens)
		return (-1);
	if (obj->type == SPHERE)
		return (ft_fill_sphere(obj, tokens));
	if (obj->type == PLANE)
		return (ft_fill_plane(obj, tokens));
	if (obj->type == CYLINDER)
		return (ft_fill_cylinder(obj, tokens));
	return (-1);
}

int	ft_parse_obj(char **tokens, t_scene *scene, t_type type)
{
	t_obj	*new_obj;

	if (!tokens || !scene)
		return (-1);
	new_obj = ft_calloc(1, sizeof(t_obj));
	if (!new_obj)
		return (-1);
	new_obj->type = type;
	if (ft_fill_obj_data(new_obj, tokens) != 0)
	{
		free(new_obj);
		return (-1);
	}
	ft_obj_add_back(&scene->objects, new_obj);
	return (0);
}