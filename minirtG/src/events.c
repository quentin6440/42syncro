#include "../include/minirt.h"

int	mouse_handler(int button, int x, int y, t_scene *scene)
{
	(void)button;
	(void)x;
	(void)y;
	(void)scene;
	return (0);
}

int	key_handler(int key, t_scene *scene)
{
	if (key == ESC || key == ESC_1)
		ft_clean_exit(scene);
	return (0);
}