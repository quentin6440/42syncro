/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 22:45:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:33:06 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
/*
static double	ft_check_height(t_obj *cy, t_ray ray, double t)
{
	t_vec3	hit_point;
	double	m;

	if (t < 0.0)
		return (-1.0);
	hit_point = vec_add(ray.origin, vec_scale(ray.dir, t));
	m = vec_dot(vec_sub(hit_point, cy->pos), cy->dir);
	if (m >= -cy->height / 2.0 && m <= cy->height / 2.0)
		return (t);
	return (-1.0);
}

double	ft_hit_cylinder(t_obj *cy, t_ray ray)
{
	t_vec3	oc;
	t_vec3	v1;
	t_vec3	v2;
	double	abc[3];
	double	disc;
	double	t[2];

	oc = vec_sub(ray.origin, cy->pos);
	v1 = vec_sub(ray.dir, vec_scale(cy->dir, vec_dot(ray.dir, cy->dir)));
	v2 = vec_sub(oc, vec_scale(cy->dir, vec_dot(oc, cy->dir)));
	abc[0] = vec_dot(v1, v1);
	abc[1] = 2.0 * vec_dot(v1, v2);
	abc[2] = vec_dot(v2, v2) - ((cy->diameter / 2.0) * (cy->diameter / 2.0));
	disc = abc[1] * abc[1] - 4.0 * abc[0] * abc[2];
	if (disc < 0.0)
		return (-1.0);
	t[0] = (-abc[1] - sqrt(disc)) / (2.0 * abc[0]);
	t[1] = (-abc[1] + sqrt(disc)) / (2.0 * abc[0]);
	t[0] = ft_check_height(cy, ray, t[0]);
	if (t[0] > 0.0)
		return (t[0]);
	return (ft_check_height(cy, ray, t[1]));
}*/

double	ft_hit_cylinder(t_obj *obj, t_ray ray)
{
	double	t_side;
	double	t_cap;
	t_vec3	dummy_norm;

	t_side = ft_hit_cylinder_side(obj, ray); // Intersection corps latéral
	t_cap = ft_hit_cylinder_caps(obj, ray, &dummy_norm); // Intersection bouchons

	if (t_side > 0.0001 && (t_cap <= 0.0001 || t_side < t_cap))
		return (t_side);
	if (t_cap > 0.0001)
		return (t_cap);
	return (-1.0);
}