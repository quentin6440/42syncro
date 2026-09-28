/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 00:00:00 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_vec3	ft_sphere_normal(t_hit hit)
{
	t_vec3	normal;

	normal = vec_sub(hit.point, hit.obj->pos);
	return (vec_normalize(normal));
}

static t_vec3	ft_plane_normal(t_hit hit)
{
	return (vec_normalize(hit.obj->dir));
}

static t_vec3	ft_cylinder_normal(t_hit hit)
{
	t_vec3	v;
	t_vec3	axis;
	t_vec3	normal;
	double	projection;
	double	half_height;

	v = vec_sub(hit.point, hit.obj->pos);
	axis = vec_normalize(hit.obj->dir);
	projection = vec_dot(v, axis);
	half_height = hit.obj->height / 2.0;
	if (fabs(projection - half_height) < EPSILON)
		return (axis);
	if (fabs(projection + half_height) < EPSILON)
		return (vec_scale(axis, -1.0));
	normal = vec_sub(v, vec_scale(axis, projection));
	return (vec_normalize(normal));
}

t_vec3	ft_get_normal(t_hit hit, t_ray ray)
{
	t_vec3	normal;

	if (!hit.valid || !hit.obj)
		return (vec_new(0.0, 0.0, 0.0));
	if (hit.obj->type == SPHERE)
		normal = ft_sphere_normal(hit);
	else if (hit.obj->type == PLANE)
		normal = ft_plane_normal(hit);
	else if (hit.obj->type == CYLINDER)
		normal = ft_cylinder_normal(hit);
	else
		return (vec_new(0.0, 0.0, 0.0));
	if (vec_dot(normal, ray.dir) > 0.0)
		normal = vec_scale(normal, -1.0);
	return (normal);
}