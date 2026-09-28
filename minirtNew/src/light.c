/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 22:00:00 by qcyril-a          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static double	ft_clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

static t_vec3	ft_color_add(t_vec3 a, t_vec3 b)
{
	return (vec_new(a.x + b.x, a.y + b.y, a.z + b.z));
}

static t_vec3	ft_color_mul(t_vec3 a, t_vec3 b)
{
	return (vec_new(
			a.x * b.x / 255.0,
			a.y * b.y / 255.0,
			a.z * b.z / 255.0));
}

static t_vec3	ft_color_scale(t_vec3 color, double ratio)
{
	return (vec_new(
			color.x * ratio,
			color.y * ratio,
			color.z * ratio));
}

static t_vec3	ft_ambient_light(t_scene *scene, t_vec3 object_color)
{
	t_vec3	ambient;

	ambient = ft_color_mul(object_color, scene->ambient.color);
	return (ft_color_scale(ambient, scene->ambient.ratio));
}

static t_vec3	ft_diffuse_light(t_scene *scene, t_hit hit)
{
	t_vec3	normal;
	t_vec3	light_dir;
	t_vec3	diffuse;
	t_ray	light_ray;
	double	intensity;

	light_dir = vec_normalize(
			vec_sub(scene->light.pos, hit.point));
	light_ray.origin = scene->light.pos;
	light_ray.dir = vec_scale(light_dir, -1.0);
	normal = ft_get_normal(hit, light_ray);
	intensity = vec_dot(normal, light_dir);
	if (intensity < 0.0)
		intensity = 0.0;
	diffuse = ft_color_mul(hit.obj->color, scene->light.color);
	return (ft_color_scale(diffuse,
			scene->light.ratio * intensity));
}

int	ft_compute_light(t_scene *scene, t_hit hit)
{
	t_vec3	color;
	double	r;
	double	g;
	double	b;

	if (!hit.valid || !hit.obj)
		return (0);
	color = ft_ambient_light(scene, hit.obj->color);
	if (!ft_is_shadowed(scene, hit.point))
		color = ft_color_add(color,
				ft_diffuse_light(scene, hit));
	r = ft_clamp(color.x, 0.0, 255.0);
	g = ft_clamp(color.y, 0.0, 255.0);
	b = ft_clamp(color.z, 0.0, 255.0);
	return (((int)r << 16) | ((int)g << 8) | (int)b);
}

