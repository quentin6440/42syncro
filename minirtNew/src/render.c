#include "../include/minirt.h"

static int	ft_get_pixel_color(t_scene *scene, t_ray ray)
{
	t_hit	hit;

	hit = ft_intersect_scene(scene, ray);
	if (!hit.valid)
		return (0x000000);
	return (ft_compute_light(scene, hit));
}

static void	ft_render_row(t_scene *scene, int y)
{
	int		x;
	double	u;
	double	v;
	t_ray	ray;
	int		color;

	x = 0;
	while (x < scene->win_width)
	{
		u = ((double)x + 0.5) / scene->win_width;
		v = ((double)y + 0.5) / scene->win_height;
		ray = ft_generate_ray(&scene->camera, u, v, scene);
		color = ft_get_pixel_color(scene, ray);
		ft_mlx_pixel_put(scene, x, y, color);
		x++;
	}
}

void	ft_render_scene(t_scene *scene)
{
	int	y;

	if (!scene)
		return ;
	y = 0;
	while (y < scene->win_height)
	{
		ft_render_row(scene, y);
		y++;
	}
}
