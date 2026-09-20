
#include "../include/minirt.h"
#include <fcntl.h>
#include <stdio.h>

static void	ft_run_time(t_scene *scene)
{
	if (!scene)
		exit(0);
	scene->mlx_ptr = mlx_init();
	if (!scene->mlx_ptr)
		ft_error("Failed to initialize MiniLibX", scene);
	scene->win_width = 800;
	scene->win_height = 600;
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, scene->win_width,
		scene->win_height, "miniRT - Raytracer");
	if (!scene->win_ptr)
		ft_error("Failed to create MiniLibX window", scene);
	if (ft_put_img_to_window(scene))
		ft_error("Failed to create MiniLibX image", scene);

	ft_render_scene(scene);

	mlx_put_image_to_window
	(scene->mlx_ptr, scene->win_ptr,
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

void	ft_print_scene_info(t_scene *scene)
{

	t_obj	*obj;
	int		i;

	printf("=== CONTENU DE LA SCENE ===\n");
	printf("Ambient: ratio=%.2f, color=[%.0f,%.0f,%.0f]\n",
		scene->ambient.ratio, scene->ambient.color.x,
		scene->ambient.color.y, scene->ambient.color.z);
	printf("Camera : pos=[%.1f,%.1f,%.1f], dir=[%.1f,%.1f,%.1f], fov=%.0f\n",
		scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z,
		scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z,
		scene->camera.fov);
	printf("Light  : pos=[%.1f,%.1f,%.1f], ratio=%.2f\n",
		scene->light.pos.x, scene->light.pos.y, scene->light.pos.z,
		scene->light.ratio);
	
	printf("--- Objets dans la liste ---\n");
	obj = scene->objects;
	i = 1;
	while (obj)
	{
		if (obj->type == SPHERE)
			printf("[%d] SPHERE   : pos=[%.1f,%.1f,%.1f], diam=%.1f, color=[%.0f,%.0f,%.0f]\n",
				i, obj->pos.x, obj->pos.y, obj->pos.z, obj->diameter, obj->color.x, obj->color.y, obj->color.z);
		else if (obj->type == PLANE)
			printf("[%d] PLANE    : pos=[%.1f,%.1f,%.1f], dir=[%.1f,%.1f,%.1f], color=[%.0f,%.0f,%.0f]\n",
				i, obj->pos.x, obj->pos.y, obj->pos.z, obj->dir.x, obj->dir.y, obj->dir.z, obj->color.x, obj->color.y, obj->color.z);
		else if (obj->type == CYLINDER)
			printf("[%d] CYLINDER : pos=[%.1f,%.1f,%.1f], diam=%.1f, h=%.1f\n",
				i, obj->pos.x, obj->pos.y, obj->pos.z, obj->diameter, obj->height);
		obj = obj->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_scene	*scene;
	int		fd;

	if (ft_check_args(argc, argv))
	{
		ft_putstr_fd("Error\nUsage: ./miniRT <scene.rt>\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCannot open .rt file\n", 2);
		return (1);
	}
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (close(fd), 1);
	scene->img_ptr = ft_calloc(1, sizeof(t_img));
	if (!scene->img_ptr)
		return (close(fd), free(scene), 1);

	if (ft_parse_rt(fd, scene) < 0)
	{
		close(fd);
		ft_clean_exit(scene);
	}
	close(fd);

// Test temporaire de contrôle

t_obj *curr = scene->objects;
int i = 0;
while (curr)
{
    printf("Objet %d: type=%d, pos=[%.1f, %.1f, %.1f]\n", 
           i++, curr->type, curr->pos.x, curr->pos.y, curr->pos.z);
    curr = curr->next;
}
//fin
	ft_print_scene_info(scene);

	ft_run_time(scene);
	ft_clean_exit(scene);
	return (0);
}
