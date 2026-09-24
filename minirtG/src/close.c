/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:32:16 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:32:17 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <errno.h>
#include <stdio.h>

void	ft_notify_wrong_usage(t_scene *scene)
{
	ft_putendl_fd("Error\nUsage: ./miniRT <scene.rt>", 2);
	ft_clean_exit(scene);
}

void	ft_error(char *msg, t_scene *scene)
{
	write(2, "Error\n", 6);
	if (errno != 0)
		perror(msg);
	else if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
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
	exit(0);
}