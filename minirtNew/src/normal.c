<<<<<<< Updated upstream
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:10:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:32:38 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_vec3	ft_sphere_normal(t_hit hit)
{
	t_vec3	n;

	n = vec_sub(hit.point, hit.obj->pos);
	return (vec_normalize(n));
}

static t_vec3	ft_plane_normal(t_hit hit, t_ray ray)
{
	t_vec3	n;

	n = vec_normalize(hit.obj->dir);
	if (vec_dot(n, ray.dir) > 0.0)
		n = vec_scale(n, -1.0);
	return (n);
}

static t_vec3	ft_cylinder_normal(t_hit hit)
{
	t_vec3	v;
	t_vec3	n;
	double	m;
	double	half_height;

	v = vec_sub(hit.point, hit.obj->pos);
	m = vec_dot(v, hit.obj->dir);
	half_height = hit.obj->height / 2.0;

	/*
	 * Pour l'instant on considère pos comme le centre du cylindre.
	 * Les deux cas suivants correspondent aux bouchons.
	 */
	if (fabs(m - half_height) < EPSILON)
		return (vec_normalize(hit.obj->dir));
	if (fabs(m + half_height) < EPSILON)
		return (vec_scale(vec_normalize(hit.obj->dir), -1.0));

	n = vec_sub(v,
			vec_scale(hit.obj->dir,
				vec_dot(v, hit.obj->dir)));
	return (vec_normalize(n));
}

t_vec3	ft_get_normal(t_hit hit, t_ray ray)
{
	if (!hit.valid || !hit.obj)
		return (vec_new(0, 0, 0));
	if (hit.obj->type == SPHERE)
		return (ft_sphere_normal(hit));
	if (hit.obj->type == PLANE)
		return (ft_plane_normal(hit, (t_ray){hit.point, hit.obj->dir}));
	if (hit.obj->type == CYLINDER)
		return (ft_cylinder_normal(hit));
	return (vec_new(0, 0, 0));
}

}
