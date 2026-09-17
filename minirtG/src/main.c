
#include "../include/minirt.h"
/*
static unsigned int	ft_get_sphere_color(t_ray ray, double t, t_sphere sp)
{
	t_vec3	hit_point;
	t_vec3	normal;
	t_vec3	light_dir;
	double	light_intensity;
	int		color_val;

	hit_point = vec_add(ray.origin, vec_scale(ray.dir, t));
	normal = vec_normalize(vec_sub(hit_point, sp.center));
	light_dir = vec_normalize(vec_new(-1.0, 1.0, 1.0));
	light_intensity = vec_dot(normal, light_dir);
	if (light_intensity < 0.1)
		light_intensity = 0.1;
	color_val = (int)(255.0 * light_intensity);
	return ((color_val << 16) | (0 << 8) | 0);
}

static void	ft_render_scene(t_scene *scene)
{
	int			x;
	int			y;
	double		u;
	double		v;
	double		t;
	double		aspect_ratio;
	t_ray		ray;
	t_sphere	sp;

	aspect_ratio = (double)scene->win_width / (double)scene->win_height;
	scene->camera.pos = vec_new(0, 0, 0);
	sp.center = vec_new(0, 0, -5.0);
	sp.radius = 1.5;

	y = 0;
	while (y < scene->win_height)
	{
		x = 0;
		while (x < scene->win_width)
		{
			u = (2.0 * ((x + 0.5) / scene->win_width) - 1.0) * aspect_ratio;
			v = (1.0 - 2.0 * ((y + 0.5) / scene->win_height));
			ray = ft_generate_ray(&scene->camera, u, v);
			t = ft_hit_sphere(sp, ray);
			if (t > 0.0)
				ft_put_pixel(x, y, ft_get_sphere_color(ray, t, sp), scene);
			else
				ft_put_pixel(x, y, 0x80B2FF, scene);
			x++;
		}
		y++;
	}
}*/
/* Renvoie 1 si le rayon touche une sphere au centre (0, 0, -5) de rayon 1.0 
static int	ft_hit_sphere(t_vec3 center, double radius, t_ray ray)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec_sub(ray.origin, center);
	a = vec_dot(ray.dir, ray.dir);
	b = 2.0 * vec_dot(oc, ray.dir);
	c = vec_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4.0 * a * c;
	return (discriminant >= 0);
}

static void	ft_render_scene(t_scene *scene)
{
	int		x;
	int		y;
	double	u;
	double	v;
	double	aspect_ratio;
	t_ray	ray;
	t_vec3	sphere_center;

	aspect_ratio = (double)scene->win_width / (double)scene->win_height;
	scene->camera.pos = vec_new(0, 0, 0);
	sphere_center = vec_new(0, 0, -5.0); // Sphere placee a 5 unites devant la camera

	y = 0;
	while (y < scene->win_height)
	{
		x = 0;
		while (x < scene->win_width)
		{
			u = (2.0 * ((x + 0.5) / scene->win_width) - 1.0) * aspect_ratio;
			v = (1.0 - 2.0 * ((y + 0.5) / scene->win_height));
			ray = ft_generate_ray(&scene->camera, u, v);
			
			if (ft_hit_sphere(sphere_center, 1.5, ray))
				ft_put_pixel(x, y, 0xFF0000, scene); // Disque/Sphere Rouge
			else
				ft_put_pixel(x, y, 0x80B2FF, scene); // Bleu Ciel
			x++;
		}
		y++;
	}
}*/
/* #include "../include/minirt.h"

static unsigned int	ft_get_sky_color(double t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (unsigned int)((1.0 - t) * 255.0 + t * 128.0);
	g = (unsigned int)((1.0 - t) * 255.0 + t * 178.0);
	b = (unsigned int)((1.0 - t) * 255.0 + t * 255.0);
	return ((r << 16) | (g << 8) | b);
}

// Trace un vecteur 'dir' a partir de 'origin' point par point en rouge 
static void	ft_draw_vector(t_scene *scene, t_vec3 origin, t_vec3 dir, double length)
{
	t_vec3	norm_dir;
	t_vec3	p;
	double	i;

	norm_dir = vec_normalize(dir);
	i = 0;
	while (i < length)
	{
		p = vec_add(origin, vec_scale(norm_dir, i));
		ft_put_pixel((int)p.x, (int)p.y, 0xFF0000, scene); // 0xFF0000 = Rouge
		i += 0.5; // Pas fin pour eviter les trous
	}
}

static void	ft_render_scene(t_scene *scene)
{
	int				x;
	int				y;
	double			t;

	// 1. Affiche le fond bleu ciel
	y = 0;
	while (y < scene->win_height)
	{
		t = (double)y / (double)(scene->win_height - 1);
		x = 0;
		while (x < scene->win_width)
		{
			ft_put_pixel(x, y, ft_get_sky_color(t), scene);
			x++;
		}
		y++;
	}

	// 2. Dessine un vecteur rouge au centre de l'ecran
	t_vec3	center = vec_new(scene->win_width / 2.0, scene->win_height / 2.0, 0);
	t_vec3	dir = vec_new(1.0, -1.0, 0); // Diagonale vers le haut-droite

	ft_draw_vector(scene, center, dir, 150.0);
} */

static void	ft_run_time(t_scene *scene)
{
	if (!scene)
		exit(0);
	scene->mlx_ptr = mlx_init();
	if (!scene->mlx_ptr)
		ft_handle_error(2, scene);
	scene->win_width = 800;
	scene->win_height = 600;
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, scene->win_width, \
		scene->win_height, "miniRT - Raytracer");
	if (!scene->win_ptr)
		ft_handle_error(3, scene);
	if (ft_put_img_to_window(scene))
		ft_handle_error(4, scene);
	ft_render_scene(scene);
	mlx_put_image_to_window(scene->mlx_ptr, scene->win_ptr, \
		scene->img_ptr->p, 0, 0);
	mlx_key_hook(scene->win_ptr, key_handler, scene);
	mlx_hook(scene->win_ptr, 17, 0, ft_clean_exit, scene);
	mlx_loop(scene->mlx_ptr);
}

static int	ft_check_args(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (1);
	len = ft_strlen(argv[1]);
	if (len < 3 || ft_strncmp(argv[1] + len - 3, ".rt", 3) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (ft_check_args(argc, argv))
	{
		ft_putstr_fd("Error\nUsage: ./miniRT <scene.rt>\n", 2);
		return (1);
	}
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		ft_handle_error(0, NULL);
	scene->img_ptr = ft_calloc(1, sizeof(t_img));
	if (!scene->img_ptr)
		ft_handle_error(1, scene);

	// TODO (Jour 7) : ft_parse_file(argv[1], scene);

	ft_run_time(scene);
	ft_clean_exit(scene);
	return (0);
}