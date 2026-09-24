#include "../include/minirt.h"

static t_vec3	ft_get_sphere_normal(t_obj *obj, t_vec3 hit_p)
{
	return (vec_normalize(vec_sub(hit_p, obj->pos)));
}

static t_vec3	ft_get_plane_normal(t_obj *obj, t_ray ray)
{
	t_vec3	normal;

	normal = vec_normalize(obj->dir);
	if (vec_dot(ray.dir, normal) > 0.0)
		normal = vec_scale(normal, -1.0);
	return (normal);
}

static t_vec3	ft_get_cylinder_normal(t_obj *obj, t_vec3 hit_p)
{
	t_vec3		v;
	t_vec3		projection;
	t_vec3		normal;
	double		m;

	v = vec_sub(hit_p, obj->pos);
	m = vec_dot(v, obj->dir);

	/*
	 * The cylinder is defined from:
	 *
	 * obj->pos
	 * to
	 * obj->pos + obj->dir * obj->height
	 */

	if (m <= EPSILON)
		return (vec_scale(obj->dir, -1.0));
	if (m >= obj->height - EPSILON)
		return (obj->dir);

	/*
	 * Otherwise, the hit is on the lateral surface.
	 */
	projection = vec_add(
			obj->pos,
			vec_scale(obj->dir, m));
	normal = vec_sub(hit_p, projection);
	return (vec_normalize(normal));
}

t_vec3	ft_get_normal(t_obj *obj, t_vec3 hit_p, t_ray ray)
{
	if (!obj)
		return (vec_new(0.0, 0.0, 0.0));
	if (obj->type == SPHERE)
		return (ft_get_sphere_normal(obj, hit_p));
	if (obj->type == PLANE)
		return (ft_get_plane_normal(obj, ray));
	if (obj->type == CYLINDER)
		return (ft_get_cylinder_normal(obj, hit_p));
	return (vec_new(0.0, 0.0, 0.0));
}