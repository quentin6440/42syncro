/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 12:00:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/20 12:00:00 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	ft_obj_add_back(t_obj **lst, t_obj *new_obj)
{
	t_obj	*curr;

	if (!lst || !new_obj)
		return ;
	if (!*lst)
	{
		*lst = new_obj;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new_obj;
}

static int	ft_fill_sphere_or_plane(t_obj *obj, char **tokens)
{
	if (obj->type == SPHERE)
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
			return (-1);
		if (ft_str_to_vec3(tokens[1], &obj->pos, 0) != 0)
			return (-1);
		if (ft_str_to_float(tokens[2], &obj->diameter) != 0 || obj->diameter <= 0)
			return (-1);
		if (ft_str_to_vec3(tokens[3], &obj->color, 0) != 0)
			return (-1);
	}
	else if (obj->type == PLANE)
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
			return (-1);
		if (ft_str_to_vec3(tokens[1], &obj->pos, 0) != 0)
			return (-1);
		if (ft_str_to_vec3(tokens[2], &obj->dir, 1) != 0) // 1 = vecteur direction !
			return (-1);
		if (ft_str_to_vec3(tokens[3], &obj->color, 0) != 0)
			return (-1);
	}
	return (0);
}

static int	ft_fill_obj_data(t_obj *obj, char **tokens)
{
	if (obj->type == SPHERE || obj->type == PLANE)
		return (ft_fill_sphere_or_plane(obj, tokens));
	if (obj->type == CYLINDER)
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || !tokens[4]
			|| !tokens[5] || tokens[6])
			return (-1);
		if (ft_str_to_vec3(tokens[1], &obj->pos, 0) != 0)
			return (-1);
		if (ft_str_to_vec3(tokens[2], &obj->dir, 1) != 0) // 1 = vecteur direction !
			return (-1);
		if (ft_str_to_float(tokens[3], &obj->diameter) != 0 || obj->diameter <= 0)
			return (-1);
		if (ft_str_to_float(tokens[4], &obj->height) != 0 || obj->height <= 0)
			return (-1);
		if (ft_str_to_vec3(tokens[5], &obj->color, 0) != 0)
			return (-1);
	}
	return (0);
}

int	ft_parse_obj(char **tokens, t_scene *scene, t_type type)
{
	t_obj	*new_obj;

	new_obj = ft_calloc(1, sizeof(t_obj));
	if (!new_obj)
		return (-1);
	new_obj->type = type;
	if (ft_fill_obj_data(new_obj, tokens) < 0)
	{
		free(new_obj);
		return (-1);
	}
	ft_obj_add_back(&scene->objects, new_obj);
	return (0);
}