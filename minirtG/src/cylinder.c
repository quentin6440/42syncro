#include "../include/minirt.h"
#include <math.h>

static double	ft_check_height(t_cylinder cy, t_ray ray, double t)
{
	t_vec3	hit_point;
	double	m;

	if (t < 0.0)
		return (-1.0);
	hit_point = vec_add(ray.origin, vec_scale(ray.dir, t));
	// Projection sur l'axe pour verifier si on est entre -height/2 et +height/2
	m = vec_dot(vec_sub(hit_point, cy.center), cy.axis);
	if (m >= -cy.height / 2.0 && m <= cy.height / 2.0)
		return (t);
	return (-1.0);
}

double	ft_hit_cylinder(t_cylinder cy, t_ray ray)
{
	t_vec3	oc;
	t_vec3	v1;
	t_vec3	v2;
	double	abc[3]; // a, b, c
	double	disc;
	double	t1;
	double	t2;

	oc = vec_sub(ray.origin, cy.center);
	v1 = vec_sub(ray.dir, vec_scale(cy.axis, vec_dot(ray.dir, cy.axis)));
	v2 = vec_sub(oc, vec_scale(cy.axis, vec_dot(oc, cy.axis)));
	abc[0] = vec_dot(v1, v1);
	abc[1] = 2.0 * vec_dot(v1, v2);
	abc[2] = vec_dot(v2, v2) - ((cy.diameter / 2.0) * (cy.diameter / 2.0));
	disc = abc[1] * abc[1] - 4.0 * abc[0] * abc[2];
	if (disc < 0.0)
		return (-1.0);
	t1 = (-abc[1] - sqrt(disc)) / (2.0 * abc[0]);
	t2 = (-abc[1] + sqrt(disc)) / (2.0 * abc[0]);
	t1 = ft_check_height(cy, ray, t1);
	if (t1 > 0.0)
		return (t1);
	return (ft_check_height(cy, ray, t2));
}