#include "../include/minirt.h"

/*bleme de sens ??
t_ray	ft_generate_ray(t_camera *cam, double u, double v, t_scene *scene)
{
	t_ray	ray;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;
	t_vec3	world_up;
	double	aspect_ratio;
	double	fov_adj;

	aspect_ratio = (double)scene->win_width / (double)scene->win_height;
	fov_adj = tan((cam->fov * M_PI / 180.0) / 2.0);

	// Axe z local de la caméra (Forward)
	forward = vec_normalize(cam->dir);

	// Vecteur vertical global pour calculer Right
	world_up = vec_new(0, 1, 0);
	if (fabs(forward.y) > 0.99) // Sécurité si la caméra regarde direct en haut/bas
		world_up = vec_new(0, 0, 1);

	// Construction de la base orthonormée (Right & Up)
	right = vec_normalize(vec_cross(forward, world_up));
	up = vec_cross(right, forward);

	// Direction du rayon dans l'espace 3D
	ray.origin = cam->pos;
	ray.dir = vec_add(
		vec_add(
			vec_scale(right, (2.0 * u - 1.0) * aspect_ratio * fov_adj),
			vec_scale(up, (1.0 - 2.0 * v) * fov_adj)
		),
		forward
	);
	ray.dir = vec_normalize(ray.dir);
	return (ray);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 23:00:00 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/17 23:00:00 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_ray	ft_generate_ray(t_camera *cam, double u, double v, t_scene *scene)
{
	t_ray	ray;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;
	t_vec3	world_up;
	double	aspect_ratio;
	double	fov_adj;

	aspect_ratio = (double)scene->win_width / (double)scene->win_height;
	fov_adj = tan((cam->fov * M_PI / 180.0) / 2.0);
	forward = vec_normalize(cam->dir);
	
	// Sécurité si la caméra regarde exactement vers le haut ou le bas (0, 1, 0 ou 0, -1, 0)
	world_up = vec_new(0, 1, 0);
	if (fabs(forward.y) > 0.999)
		world_up = vec_new(0, 0, (forward.y > 0) ? -1 : 1);

	// Axe X (Right) : forward x world_up oriente l'axe X vers la DROITE
	right = vec_normalize(vec_cross(world_up, forward));
	// Axe Y (Up) : right x forward complète la base orthonormée
	up = vec_cross(forward, right);
	//up = vec_cross(world_up, forward);

	ray.origin = cam->pos;
	
	// Projection : u va de 0 à 1 (gauche -> droite), v de 0 à 1 (haut -> bas)
	ray.dir = vec_add(
		vec_add(
			vec_scale(right, (2.0 * u - 1.0) * aspect_ratio * fov_adj),
			vec_scale(up, (1.0 - 2.0 * v) * fov_adj)
		),
		forward
	);
	ray.dir = vec_normalize(ray.dir);
	return (ray);
}