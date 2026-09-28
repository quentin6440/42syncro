/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cl_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 00:00:00 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	ft_check_height(t_obj *obj, t_ray ray, double t)
{
	t_vec3	point;
	t_vec3	relative;
	double	projection;
	double	half_height;

	if (t <= EPSILON)
		return (0);
	point = vec_add(ray.origin, vec_scale(ray.dir, t));
	relative = vec_sub(point, obj->pos);
	projection = vec_dot(relative, obj->dir);
	half_height = obj->height / 2.0;
	if (projection < -half_height || projection > half_height)
		return (0);
	return (1);
}

static double	ft_nearest_valid_t(t_obj *obj, t_ray ray,
		double t1, double t2)
{
	int	valid_t1;
	int	valid_t2;

	valid_t1 = ft_check_height(obj, ray, t1);
	valid_t2 = ft_check_height(obj, ray, t2);
	if (valid_t1 && valid_t2)
	{
		if (t1 < t2)
			return (t1);
		return (t2);
	}
	if (valid_t1)
		return (t1);
	if (valid_t2)
		return (t2);
	return (-1.0);
}

double	ft_hit_cylinder_side(t_obj *obj, t_ray ray)
{
	t_vec3	relative;
	double	axis_ray;
	double	axis_origin;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t1;
	double	t2;

	relative = vec_sub(ray.origin, obj->pos);
	axis_ray = vec_dot(ray.dir, obj->dir);
	axis_origin = vec_dot(relative, obj->dir);
	a = vec_dot(ray.dir, ray.dir) - axis_ray * axis_ray;
	b = 2.0 * (vec_dot(ray.dir, relative)
			- axis_ray * axis_origin);
	c = vec_dot(relative, relative)
		- axis_origin * axis_origin
		- (obj->diameter / 2.0) * (obj->diameter / 2.0);
	if (fabs(a) < EPSILON)
		return (-1.0);
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0)
		return (-1.0);
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	return (ft_nearest_valid_t(obj, ray, t1, t2));
}