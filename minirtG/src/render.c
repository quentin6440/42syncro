/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:34:25 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:34:26 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minirt.h"

static unsigned int	ft_rgb_to_uint(t_vec3 color)
{
	int	r;
	int	g;
	int	b;

	r = (int)color.x;
	g = (int)color.y;
	b = (int)color.z;
	if (r > 255) r = 255;
	if (g > 255) g = 255;
	if (b > 255) b = 255;
	if (r < 0) r = 0;
	if (g < 0) g = 0;
	if (b < 0) b = 0;
	return ((r << 16) | (g << 8) | b);
}

static unsigned int	ft_trace_ray(t_ray ray, t_scene *scene)
{
	t_obj	*obj;
	t_obj	*closest_obj;
	double	t;
	double	closest_t;

	closest_t = 1e30;
	closest_obj = NULL;
	obj = scene->objects;
	while (obj)
	{
		t = -1.0;
		if (obj->type == SPHERE)
			t = ft_hit_sphere(obj, ray);
		else if (obj->type == PLANE)
			t = ft_hit_plane(obj, ray);
		else if (obj->type == CYLINDER)
			t = ft_hit_cylinder(obj, ray);
		if (t > 0.0001 && t < closest_t)
		{
			closest_t = t;
			closest_obj = obj;
		}
		obj = obj->next;
	}
/*
AFFICHE EN COULEUR ORIGINALE
*/
	if (closest_obj)
		return (ft_rgb_to_uint(closest_obj->color));





	return (0x000000); // Fond noir si aucun objet touché
}

void	ft_render_scene(t_scene *scene)
{
	int		x;
	int		y;
	double	u;
	double	v;
	t_ray	ray;
	int		color;

	y = 0;
	while (y < scene->win_height)
	{
		x = 0;
		while (x < scene->win_width)
		{
			// Normalisation entre 0.0 et 1.0 sur la largeur/hauteur réelles
			u = (double)x / (double)(scene->win_width - 1);
			v = (double)y / (double)(scene->win_height - 1);
			ray = ft_generate_ray(&scene->camera, u, v, scene);
			color = ft_trace_ray(ray, scene);
			
			ft_mlx_pixel_put(scene, x, y, color);
			
			x++;
		}
		y++;
	}
}