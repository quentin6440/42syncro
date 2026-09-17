#include "../include/minirt.h"

/* Structure temporaire pour stocker les objets de notre scène de test */
typedef struct s_test_scene
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
}	t_test_scene;

static unsigned int	ft_get_object_color(t_ray ray, double t, t_vec3 normal, unsigned int base_color)
{
(void)t;   // Indique explicitement au compilateur que t est inutilise pour l'instant
	(void)ray; // Indique explicitement que ray est inutilise si besoin

	t_vec3	light_dir;
	double	light_intensity;
	int		r;
	int		g;
	int		b;

	// Direction d'une lumière fictive (haut-gauche)
	light_dir = vec_normalize(vec_new(-1.0, 1.0, 1.0));
	
	// Éclairage de Lambert
	light_intensity = vec_dot(normal, light_dir);
	if (light_intensity < 0.15) // Lumière ambiante minimale
		light_intensity = 0.15;

	r = (int)(((base_color >> 16) & 0xFF) * light_intensity);
	g = (int)(((base_color >> 8) & 0xFF) * light_intensity);
	b = (int)((base_color & 0xFF) * light_intensity);

	return ((r << 16) | (g << 8) | b);
}

static unsigned int	ft_trace_ray(t_ray ray, t_test_scene *objs)
{
	double	t_min;
	double	t;
	t_vec3	normal;
	unsigned int	color;
	t_vec3	hit_p;

	t_min = 1e30;
	color = 0x80B2FF; // Couleur de fond (Ciel)

	// 1. Check Sphère (Rouge)
	t = ft_hit_sphere(objs->sp, ray);
	if (t > 0.001 && t < t_min)
	{
		t_min = t;
		hit_p = vec_add(ray.origin, vec_scale(ray.dir, t));
		normal = vec_normalize(vec_sub(hit_p, objs->sp.center));
		color = ft_get_object_color(ray, t, normal, 0xFF0000);
	}

	// 2. Check Plan / Sol (Gris/Vert)
	t = ft_hit_plane(objs->pl, ray);
	if (t > 0.001 && t < t_min)
	{
		t_min = t;
		normal = objs->pl.normal;
		color = ft_get_object_color(ray, t, normal, 0x44AA44);
	}

	// 3. Check Cylindre (Bleu)
	t = ft_hit_cylinder(objs->cy, ray);
	if (t > 0.001 && t < t_min)
	{
		t_min = t;
		hit_p = vec_add(ray.origin, vec_scale(ray.dir, t));
		// Normale approximative du cylindre pour le test
		t_vec3 proj = vec_add(objs->cy.center, vec_scale(objs->cy.axis, vec_dot(vec_sub(hit_p, objs->cy.center), objs->cy.axis)));
		normal = vec_normalize(vec_sub(hit_p, proj));
		color = ft_get_object_color(ray, t, normal, 0x3388FF);
	}

	return (color);
}

void	ft_render_scene(t_scene *scene)
{
	int				x;
	int				y;
	double			u;
	double			v;
	double			aspect;
	t_ray			ray;
	t_test_scene	objs;

	aspect = (double)scene->win_width / (double)scene->win_height;
	scene->camera.pos = vec_new(0, 0, 0);

	// Configuration des 3 objets de test
	objs.sp.center = vec_new(-1.2, 0, -4.0);
	objs.sp.radius = 0.8;

	objs.pl.point = vec_new(0, -1.0, 0);
	objs.pl.normal = vec_normalize(vec_new(0, 1, 0)); // Plan horizontal (Sol)

	objs.cy.center = vec_new(1.2, 0, -4.0);
	objs.cy.axis = vec_normalize(vec_new(0, 1, 0)); // Cylindre vertical
	objs.cy.diameter = 1.0;
	objs.cy.height = 2.0;

	y = 0;
	while (y < scene->win_height)
	{
		x = 0;
		while (x < scene->win_width)
		{
			u = (2.0 * ((x + 0.5) / scene->win_width) - 1.0) * aspect;
			v = (1.0 - 2.0 * ((y + 0.5) / scene->win_height));
			ray = ft_generate_ray(&scene->camera, u, v);
			ft_put_pixel(x, y, ft_trace_ray(ray, &objs), scene);
			x++;
		}
		y++;
	}
}