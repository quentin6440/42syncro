/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cl_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:30:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:32:59 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	ft_check_height(t_obj *obj, t_ray ray, double t)
{
	t_vec3	p;
	t_vec3	v;
	double	m;

	if (t <= 0.0001)
		return (0);
	p = vec_add(ray.origin, vec_scale(ray.dir, t));
	v = vec_sub(p, obj->pos);
	m = vec_dot(v, obj->dir);
	if (m >= 0.0 && m <= obj->height)
		return (1);
	return (0);
}

double	ft_hit_cylinder_side(t_obj *obj, t_ray ray)
{
	t_vec3	x;
	double	r;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t1;
	double	t2;

	r = obj->diameter / 2.0;
	x = vec_sub(ray.origin, obj->pos);
	a = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, obj->dir), 2);
	b = 2.0 * (vec_dot(ray.dir, x) - (vec_dot(ray.dir, obj->dir) * vec_dot(x, obj->dir)));
	c = vec_dot(x, x) - pow(vec_dot(x, obj->dir), 2) - (r * r);
	discriminant = (b * b) - (4.0 * a * c);
	if (discriminant < 0.0 || fabs(a) < 1e-6)
		return (-1.0);
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (ft_check_height(obj, ray, t1))
		return (t1);
	if (ft_check_height(obj, ray, t2))
		return (t2);
	return (-1.0);
}