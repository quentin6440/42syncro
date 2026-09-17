#include "../include/mimirt.h"

void	ft_put_pixel(int x, int y, unsigned int color, t_fractol *fp)
{
	int		i;
	int		bytes_per_pixel;
	char	*pixel;

	if (!fp || !fp->img_ptr || !fp->img_ptr->data)
		return ;
	if (x < 0 || y < 0 || x >= fp->win_width || y >= fp->win_height)
		return ;
	bytes_per_pixel = fp->img_ptr->bits_per_pixel / 8;
	if (bytes_per_pixel <= 0)
		return ;
	i = y * fp->img_ptr->line_len + x * bytes_per_pixel;
	pixel = fp->img_ptr->data + i;
	*(unsigned int *)pixel = color;
}

static void	ft_run_mode(t_fractol *fp)
{
	if (fp->mode == 1)
		ft_run_mandelbrot(fp);
	else if (fp->mode == 2)
		ft_run_julia(fp);
	else
		ft_handle_error(6, fp);
}

int	ft_put_img_to_window(t_fractol *fp)
{
	if (fp->img_ptr->p)
		mlx_destroy_image(fp->mlx_ptr, fp->img_ptr->p);
	fp->img_ptr->p = mlx_new_image(fp->mlx_ptr, fp->win_width, fp->win_height);
	if (!fp->img_ptr->p)
		ft_handle_error(4, fp);
	fp->img_ptr->bits_per_pixel = 1;
	fp->img_ptr->line_len = 1;
	fp->img_ptr->endian = 1;
	fp->img_ptr->data = mlx_get_data_addr(fp->img_ptr->p, \
&fp->img_ptr->bits_per_pixel, &fp->img_ptr->line_len, &fp->img_ptr->endian);
	if (!fp->img_ptr->data)
		ft_handle_error(5, fp);
	ft_run_mode(fp);
	mlx_put_image_to_window(fp->mlx_ptr, fp->win_ptr, fp->img_ptr->p, 0, 0);
	return (0);
}
