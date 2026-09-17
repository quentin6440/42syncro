#include "../include/minirt.h"

int	mouse_handler(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int	key_handler(int key, void *param)
{
	if (key == ESC || key == ESC_1)
		ft_clean_exit(param);
	return (0);
}