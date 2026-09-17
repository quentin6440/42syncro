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
	// 1. Libérer la liste chaînée des objets géométriques
	ft_free_objects(&scene->objects);

	// 2. Nettoyer les éléments MiniLibX s'ils ont été initialisés
	if (scene->img_ptr && scene->mlx_ptr)
		mlx_destroy_image(scene->mlx_ptr, scene->img_ptr);
	if (scene->win_ptr && scene->mlx_ptr)
		mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
	if (scene->mlx_ptr)
	{
		mlx_destroy_display(scene->mlx_ptr);
		free(scene->mlx_ptr);
	}

	// 3. Quitter proprement le programme
	exit(0);
	return (0);
}

void	ft_handle_error(int n, t_scene *scene)
{
	if (n == 0)
	{
		ft_putendl_fd("Error: Memory allocation failed", 2);
		exit(1);
	}
	ft_putstr_fd("Error code: ", 2);
	ft_putnbr_fd(n, 2);
	ft_putchar_fd('\n', 2);
	ft_clean_exit(scene);
}
