/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:00:00 by quentin           #+#    #+#             */
/*   Updated: 2026/09/28 15:40:53 by qcyril-a         ###   ########.fr       */
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

void	ft_runtime_error(t_scene *scene, const char *message)
{
	ft_putstr_fd("Error\n", 2);
	if (message)
	{
		ft_putstr_fd((char *)message, 2);
		ft_putchar_fd('\n', 2);
	}
	ft_destroy_scene(scene);
	exit(EXIT_FAILURE);
}

int	ft_clean_exit(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	ft_destroy_scene(scene);
	exit(EXIT_SUCCESS);
	return (0);
}