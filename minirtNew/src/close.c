/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 00:00:00 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <errno.h>
#include <stdio.h>

void	ft_free_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_objects(t_obj **list)
{
	t_obj	*current;
	t_obj	*next;

	if (!list)
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

void	ft_error(char *message, t_scene *scene)
{
	write(2, "Error\n", 6);
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	ft_clean_exit(scene);
}

int	ft_clean_exit(t_scene *scene)
{
	if (!scene)
		exit(EXIT_FAILURE);
	if (scene->mlx_ptr)
	{
		if (scene->img_ptr && scene->img_ptr->p)
		{
			mlx_destroy_image(scene->mlx_ptr, scene->img_ptr->p);
			scene->img_ptr->p = NULL;
		}
		if (scene->win_ptr)
			mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
		scene->win_ptr = NULL;
		mlx_destroy_display(scene->mlx_ptr);
		free(scene->mlx_ptr);
		scene->mlx_ptr = NULL;
	}
	if (scene->img_ptr)
		ft_free_null((void **)&scene->img_ptr);
	ft_free_objects(&scene->objects);
	free(scene);
	exit(EXIT_SUCCESS);
}