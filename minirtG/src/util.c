#include "../include/minirt.h"

void	ft_notify_wrong_usage(t_scene *scene)
{
	ft_putendl_fd("Error\nUsage: ./miniRT <scene.rt>", 2);
	ft_clean_exit(scene);
}

void	ft_free_null(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}
/*
int	ft_clean_exit(t_scene *scene)
{
	if (!scene)
		exit(0);
	if (scene->mlx_ptr)
	{
		if (scene->img_ptr && scene->img_ptr->p)
		{
			mlx_destroy_image(scene->mlx_ptr, scene->img_ptr->p);
			scene->img_ptr->p = NULL;
		}
		if (scene->win_ptr)
		{
			mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
			scene->win_ptr = NULL;
		}
		mlx_destroy_display(scene->mlx_ptr);
		scene->mlx_ptr = NULL;
	}
	if (scene->img_ptr)
		ft_free_null((void **)&scene->img_ptr);
	ft_free_null((void **)&scene);
	ft_putendl_fd("Clean exit OK, Good bye.", 1);
	exit(0);
}
*/

#include "../include/minirt.h"

void	ft_handle_error(int err_code, t_scene *scene)
{
	ft_putstr_fd("Error\n", 2);
	if (err_code == 0)
		ft_putendl_fd("Failed to allocate memory for t_scene", 2);
	else if (err_code == 1)
		ft_putendl_fd("Failed to allocate memory for t_img", 2);
	else if (err_code == 2)
		ft_putendl_fd("Failed to initialize MiniLibX", 2);
	else if (err_code == 3)
		ft_putendl_fd("Failed to create MiniLibX window", 2);
	else if (err_code == 4)
		ft_putendl_fd("Failed to create MiniLibX image", 2);
	else if (err_code == 5)
		ft_putendl_fd("Parsing error in .rt scene file", 2);
	else
		ft_putendl_fd("An unexpected error occurred", 2);
	ft_clean_exit(scene);
}

void	ft_free_objects(t_obj **lst)
{
	t_obj	*current;
	t_obj	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	ft_clean_exit(t_scene *scene)
{
	if (!scene)
		exit(0);
	if (scene->mlx_ptr)
	{
		if (scene->img_ptr && scene->img_ptr->p)
		{
			mlx_destroy_image(scene->mlx_ptr, scene->img_ptr->p);
			scene->img_ptr->p = NULL;
		}
		if (scene->win_ptr)
		{
			mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
			scene->win_ptr = NULL;
		}
		mlx_destroy_display(scene->mlx_ptr);
		free(scene->mlx_ptr);
		scene->mlx_ptr = NULL;
	}
	if (scene->img_ptr)
		ft_free_null((void **)&scene->img_ptr);
	if (scene->objects)
		ft_free_objects(&scene->objects);
	ft_free_null((void **)&scene);
	ft_putendl_fd("Clean exit OK, Good bye.", 1);
	exit(0);
}

/*

int clean_exit(t_game *game, int exit_code)
{
    if (!game)
        exit(exit_code);

    // 1. Image
    if (game->img.ptr)
        mlx_destroy_image(game->mlx, game->img.ptr);

    // 2. Fenêtre
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);

    // 3. Display (spécifique à Linux / MLX)
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }

    // 4. Structures internes
    free_map(game); // Libération de votre carte/mémoire si nécessaire

    exit(exit_code);
    return (0);
}*/