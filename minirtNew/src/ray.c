#include "../include/minirt.h"

typedef struct s_basis
{
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;
}	t_basis;

static t_vec3	ft_get_world_up(t_vec3 forward)
{
	if (fabs(forward.y) > 0.999)
	{
		if (forward.y > 0.0)
			return (vec_new(0.0, 0.0, -1.0));
		return (vec_new(0.0, 0.0, 1.0));
	}
	return (vec_new(0.0, 1.0, 0.0));
}

static t_basis	ft_build_basis(t_vec3 forward)
{
	t_basis	basis;
	t_vec3	world_up;

	world_up = ft_get_world_up(forward);
	basis.forward = forward;
	basis.right = vec_normalize(vec_cross(world_up, forward));
	basis.up = vec_cross(forward, basis.right);
	return (basis);
}

static t_vec3	ft_build_ray_dir(t_basis basis, double u, double v,
		t_camera *cam, t_scene *scene)
{
	double	aspect_ratio;
	double	fov_adjustment;
	t_vec3	direction;

	aspect_ratio = (double)scene->win_width / scene->win_height;
	fov_adjustment = tan((cam->fov * M_PI / 180.0) / 2.0);
	direction = vec_add(
			vec_scale(basis.right,
				(2.0 * u - 1.0) * aspect_ratio * fov_adjustment),
			vec_scale(basis.up,
				(1.0 - 2.0 * v) * fov_adjustment));
	direction = vec_add(basis.forward, direction);
	return (vec_normalize(direction));
}

t_ray	ft_generate_ray(t_camera *cam, double u, double v, t_scene *scene)
{
	t_ray	ray;
	t_basis	basis;

	basis = ft_build_basis(vec_normalize(cam->dir));
	ray.origin = cam->pos;
	ray.dir = ft_build_ray_dir(basis, u, v, cam, scene);
	return (ray);
}
