#include "../include/minirt.h"

int	ft_parse_ambient(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || tokens[3])
		return (ft_putstr_fd("Error\nBad Ambient format\n", 2), -1);
	scene->ambient.ratio = ft_str_to_float(tokens[1]);
	scene->ambient.color = ft_str_to_vec3(tokens[2]);
	return (0);
}

int	ft_parse_camera(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (ft_putstr_fd("Error\nBad Camera format\n", 2), -1);
	scene->camera.pos = ft_str_to_vec3(tokens[1]);
	scene->camera.dir = vec_normalize(ft_str_to_vec3(tokens[2]));
	scene->camera.fov = ft_str_to_float(tokens[3]);
	return (0);
}

int	ft_parse_light(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (ft_putstr_fd("Error\nBad Light format\n", 2), -1);
	scene->light.pos = ft_str_to_vec3(tokens[1]);
	scene->light.ratio = ft_str_to_float(tokens[2]);
	scene->light.color = ft_str_to_vec3(tokens[3]);
	return (0);
}

static void	ft_add_obj_back(t_obj **lst, t_obj *new_node)
{
	t_obj	*tmp;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

int	ft_parse_sphere(char **tokens, t_scene *scene)
{
	t_obj	*obj;

	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (ft_putstr_fd("Error\nBad Sphere format\n", 2), -1);
	obj = ft_calloc(1, sizeof(t_obj));
	if (!obj)
		return (-1);
	obj->type = SPHERE;
	obj->pos = ft_str_to_vec3(tokens[1]);
	obj->diameter = ft_str_to_float(tokens[2]);
	obj->color = ft_str_to_vec3(tokens[3]);
	ft_add_obj_back(&scene->objects, obj);
	return (0);
}

int	ft_parse_plane(char **tokens, t_scene *scene)
{
	t_obj	*obj;

	if (!tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (ft_putstr_fd("Error\nBad Plane format\n", 2), -1);
	obj = ft_calloc(1, sizeof(t_obj));
	if (!obj)
		return (-1);
	obj->type = PLANE;
	obj->pos = ft_str_to_vec3(tokens[1]);
	obj->dir = vec_normalize(ft_str_to_vec3(tokens[2]));
	obj->color = ft_str_to_vec3(tokens[3]);
	ft_add_obj_back(&scene->objects, obj);
	return (0);
}

int	ft_parse_cylinder(char **tokens, t_scene *scene)
{
	t_obj	*obj;

	if (!tokens[1] || !tokens[2] || !tokens[3] || !tokens[4] || !tokens[5] || tokens[6])
		return (ft_putstr_fd("Error\nBad Cylinder format\n", 2), -1);
	obj = ft_calloc(1, sizeof(t_obj));
	if (!obj)
		return (-1);
	obj->type = CYLINDER;
	obj->pos = ft_str_to_vec3(tokens[1]);
	obj->dir = vec_normalize(ft_str_to_vec3(tokens[2]));
	obj->diameter = ft_str_to_float(tokens[3]);
	obj->height = ft_str_to_float(tokens[4]);
	obj->color = ft_str_to_vec3(tokens[5]);
	ft_add_obj_back(&scene->objects, obj);
	return (0);
}