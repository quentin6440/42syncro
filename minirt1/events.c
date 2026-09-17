#include "../include/fractol.h"

int	mouse_handler(int button, int x, int y, t_fractol *fp)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = x / fp->zoom_x + fp->x_min;
	tmp_y = y / fp->zoom_y + fp->y_min;
	if (button == SCROLL_UP)
	{
		fp->zoom_x *= 1.1;
		fp->zoom_y *= 1.1;
		fp->display_shift /= 1.1;
	}
	if (button == SCROLL_DOWN)
	{
		fp->zoom_x /= 1.1;
		fp->zoom_y /= 1.1;
		fp->display_shift *= 1.1;
	}
	fp->x_min = tmp_x - (x / fp->zoom_x);
	fp->y_min = tmp_y - (y / fp->zoom_y);
	ft_put_img_to_window(fp);
	return (0);
}

int	key_handler(int key, t_fractol *fp)
{
	if (key == ESC || key == ESC_1)
		ft_clean_exit(fp);
	if (key == KEY_C)
		fp->color += 0xF0a0F0;
	if (key == ARROW_UP)
		fp->y_min -= fp->display_shift;
	if (key == ARROW_DOWN)
		fp->y_min += fp->display_shift;
	if (key == ARROW_LEFT)
		fp->x_min -= fp->display_shift;
	if (key == ARROW_RIGHT)
		fp->x_min += fp->display_shift;
	ft_put_img_to_window(fp);
	return (0);
}
