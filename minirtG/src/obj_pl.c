/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:33:10 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/21 13:33:11 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <math.h>

double	ft_hit_plane(t_obj *pl, t_ray ray)
{
	double	denom;
	double	t;

	denom = vec_dot(ray.dir, pl->dir);
	// Si denom est proche de 0, le rayon est parallele au plan
	if (fabs(denom) > 1e-6)
	{
		t = vec_dot(vec_sub(pl->pos, ray.origin), pl->dir) / denom;
		if (t >= 0.0)
			return (t);
	}
	return (-1.0);
}