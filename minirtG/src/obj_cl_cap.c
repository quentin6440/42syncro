/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cyl_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:20:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/20 13:20:00 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static double	ft_check_cap_plane(t_ray ray, t_vec3 cap_center, t_vec3 cap_norm, double radius)
{
	double	denom;
	double	t;
	t_vec3	hit_p;
	t_vec3	dist;

	denom = vec_dot(ray.dir, cap_norm);
	if (fabs(denom) < 1e-6)
		return (-1.0);
	t = vec_dot(vec_sub(cap_center, ray.origin), cap_norm) / denom;
	if (t < 0.0001)
		return (-1.0);
	hit_p = vec_add(ray.origin, vec_scale(ray.dir, t));
	dist = vec_sub(hit_p, cap_center);
	if (vec_dot(dist, dist) <= (radius * radius))
		return (t);
	return (-1.0);
}

double	ft_hit_cylinder_caps(t_obj *obj, t_ray ray, t_vec3 *out_norm)
{
	double	r;
	t_vec3	top_center;
	double	t_bot;
	double	t_top;

	r = obj->diameter / 2.0;
	top_center = vec_add(obj->pos, vec_scale(obj->dir, obj->height));
	
	// Test bouchon bas (normale = -dir)
	t_bot = ft_check_cap_plane(ray, obj->pos, vec_scale(obj->dir, -1.0), r);
	// Test bouchon haut (normale = dir)
	t_top = ft_check_cap_plane(ray, top_center, obj->dir, r);

	if (t_bot > 0.0001 && (t_top <= 0.0001 || t_bot < t_top))
	{
		if (out_norm)
			*out_norm = vec_scale(obj->dir, -1.0);
		return (t_bot);
	}
	if (t_top > 0.0001)
	{
		if (out_norm)
			*out_norm = obj->dir;
		return (t_top);
	}
	return (-1.0);
}