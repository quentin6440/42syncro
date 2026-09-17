#include "../include/minirt.h"

t_ray	ft_generate_ray(t_camera *cam, double u, double v)
{
	t_ray	ray;
	t_vec3	pixel_target;

	ray.origin = cam->pos;
	// Le pixel cible sur le plan d'imagerie situe a Z = -1.0
	pixel_target = vec_new(u, v, -1.0);
	// Direction = vecteur de la camera vers le pixel (normalise)
	ray.dir = vec_normalize(vec_sub(pixel_target, cam->pos));
	return (ray);
}