/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:10:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/20 13:10:00 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_vec3	ft_get_sphere_normal(t_obj *obj, t_vec3 hit_p)
{
	t_vec3	n;

	n = vec_sub(hit_p, obj->pos);
	return (vec_normalize(n));
}

static t_vec3	ft_get_plane_normal(t_obj *obj, t_ray ray)
{
	t_vec3	n;

	n = vec_normalize(obj->dir);
	// Si le rayon frappe le plan par derrière, on inverse la normale
	if (vec_dot(ray.dir, n) > 0.0)
		n = vec_scale(n, -1.0);
	return (n);
}

static t_vec3	ft_get_cylinder_normal(t_obj *obj, t_vec3 hit_p)
{
	t_vec3	v;
	double	m;
	t_vec3	p_proj;
	t_vec3	n;

	v = vec_sub(hit_p, obj->pos);
	m = vec_dot(v, obj->dir);
	p_proj = vec_add(obj->pos, vec_scale(obj->dir, m));
	n = vec_sub(hit_p, p_proj);
	return (vec_normalize(n));
}
t_vec3	ft_get_normal(t_obj *obj, t_vec3 hit_p, t_ray ray)
{
	t_vec3	n;

	n = vec_new(0, 0, 0);
	if (obj->type == SPHERE)
		n = ft_get_sphere_normal(obj, hit_p);
	else if (obj->type == PLANE)
		n = ft_get_plane_normal(obj, ray);
	else if (obj->type == CYLINDER)
		n = ft_get_cylinder_normal(obj, hit_p);
	return (n);
}