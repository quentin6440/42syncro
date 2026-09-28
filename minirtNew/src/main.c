/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:32:26 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/28 00:00:00 by quentin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <fcntl.h>
#include <stdio.h>

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

static int	ft_open_scene(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCannot open .rt file\n", 2);
		return (-1);
	}
	return (fd);
}

static int	ft_init_scene(t_scene **scene)
{
	*scene = ft_calloc(1, sizeof(t_scene));
	if (!*scene)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		return (-1);
	}
	(*scene)->img_ptr = ft_calloc(1, sizeof(t_img));
	if (!(*scene)->img_ptr)
	{
		ft_destroy_scene(*scene);
		*scene = NULL;
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		return (-1);
	}
	return (0);
}

static int	ft_load_scene(char *path, t_scene **scene)
{
	t_parse_error	error;
	int				fd;

	fd = ft_open_scene(path);
	if (fd < 0)
		return (-1);
	if (ft_init_scene(scene) < 0)
	{
		close(fd);
		return (-1);
	}
	if (ft_parse_rt(fd, *scene, &error) < 0)
	{
		close(fd);
		ft_print_parse_error(&error);
		ft_destroy_scene(*scene);
		*scene = NULL;
		return (-1);
	}
	close(fd);
	return (0);
}

static void	ft_print_objects(t_scene *scene)
{
	t_obj	*obj;
	int		i;

	printf("--- Objets dans la liste ---\n");
	obj = scene->objects;
	i = 1;
	while (obj)
	{
		if (obj->type == SPHERE)
			printf("[%d] SPHERE: pos=[%.1f,%.1f,%.1f], diam=%.1f\n",
				i, obj->pos.x, obj->pos.y, obj->pos.z,
				obj->diameter);
		else if (obj->type == PLANE)
			printf("[%d] PLANE: pos=[%.1f,%.1f,%.1f]\n",
				i, obj->pos.x, obj->pos.y, obj->pos.z);
		else if (obj->type == CYLINDER)
			printf("[%d] CYLINDER: pos=[%.1f,%.1f,%.1f], diam=%.1f, h=%.1f\n",
				i, obj->pos.x, obj->pos.y, obj->pos.z,
				obj->diameter, obj->height);
		obj = obj->next;
		i++;
	}
}

static void	ft_print_scene_info(t_scene *scene)
{
	printf("=== CONTENU DE LA SCENE ===\n");
	printf("Ambient: ratio=%.2f, color=[%.0f,%.0f,%.0f]\n",
		scene->ambient.ratio, scene->ambient.color.x,
		scene->ambient.color.y, scene->ambient.color.z);
	printf("Camera: pos=[%.1f,%.1f,%.1f], dir=[%.1f,%.1f,%.1f]\n",
		scene->camera.pos.x, scene->camera.pos.y,
		scene->camera.pos.z, scene->camera.dir.x,
		scene->camera.dir.y, scene->camera.dir.z);
	printf("Camera FOV: %.0f\n", scene->camera.fov);
	printf("Light: pos=[%.1f,%.1f,%.1f], ratio=%.2f\n",
		scene->light.pos.x, scene->light.pos.y,
		scene->light.pos.z, scene->light.ratio);
	ft_print_objects(scene);
}

static void	ft_run_time(t_scene *scene)
{
	if (!scene)
		exit(EXIT_FAILURE);
	scene->win_width = 800;
	scene->win_height = 600;
	scene->mlx_ptr = mlx_init();
	if (!scene->mlx_ptr)
		ft_runtime_error(scene, "Failed to initialize MiniLibX");
	scene->win_ptr = mlx_new_window(scene->mlx_ptr,
			scene->win_width, scene->win_height,
			"miniRT - Raytracer");
	if (!scene->win_ptr)
		ft_runtime_error(scene, "Failed to create MiniLibX window");
	if (ft_put_img_to_window(scene) != 0)
		ft_runtime_error(scene, "Failed to create MiniLibX image");
	ft_render_scene(scene);
	mlx_put_image_to_window(scene->mlx_ptr, scene->win_ptr,
		scene->img_ptr->p, 0, 0);
	mlx_key_hook(scene->win_ptr, key_handler, scene);
	mlx_hook(scene->win_ptr, 17, 0, ft_clean_exit, scene);
	mlx_loop(scene->mlx_ptr);
}
/*
static void	ft_run_time(t_scene *scene)
{
	if (!scene)
		exit(EXIT_FAILURE);
	scene->win_width = 800;
	scene->win_height = 600;
	scene->mlx_ptr = mlx_init();
	if (!scene->mlx_ptr)
		ft_runtime_error(scene, "Failed to initialize MiniLibX");
	scene->win_ptr = mlx_new_window(scene->mlx_ptr,
			scene->win_width, scene->win_height,
			"miniRT - Raytracer");
	if (!scene->win_ptr)
		ft_runtime_error(scene, "Failed to create MiniLibX window");
	if (ft_put_img_to_window(scene) != 0)
		ft_runtime_error(scene, "Failed to create MiniLibX image");
	ft_render_scene(scene);
	mlx_put_image_to_window(scene->mlx_ptr, scene->win_ptr,
		scene->img_ptr->p, 0, 0);
	mlx_key_hook(scene->win_ptr, key_handler, scene);
	mlx_hook(scene->win_ptr, 17, 0, ft_clean_exit, scene);
	mlx_loop(scene->mlx_ptr);
}*/

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = NULL;
	if (ft_check_args(argc, argv))
	{
		ft_putstr_fd("Error\nUsage: ./miniRT <scene.rt>\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_load_scene(argv[1], &scene) < 0)
		return (EXIT_FAILURE);
	ft_print_scene_info(scene);
	ft_run_time(scene);
	ft_destroy_scene(scene);
	return (EXIT_SUCCESS);
}