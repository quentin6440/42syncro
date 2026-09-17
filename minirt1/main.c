#include "../include/fractol.h"

static void	ft_set_mode(t_fractol *fp)
{
	if (fp->mode == 1)
		ft_set_mandelbrot(fp);
	else if (fp->mode == 2)
		ft_set_julia(fp);
	else
		ft_clean_exit(fp);
}

static void	ft_run_time(t_fractol *fp)
{
	if (!fp)
		exit(0);
	fp->mlx_ptr = mlx_init();
	if (!fp->mlx_ptr)
		ft_handle_error(2, fp);
	fp->win_width = 600;
	fp->win_height = 600;
	fp->display_shift = 0.1;
	fp->win_ptr = mlx_new_window(fp->mlx_ptr, fp->win_width, fp->win_height, \
"Parce que c'est Notre Projet !!");
	if (!fp->win_ptr)
		ft_handle_error(3, fp);
	ft_set_mode(fp);
	ft_put_img_to_window(fp);
	mlx_key_hook(fp->win_ptr, key_handler, fp);
	mlx_mouse_hook(fp->win_ptr, mouse_handler, fp);
	mlx_hook(fp->win_ptr, 17, 0, ft_clean_exit, fp);
	mlx_loop(fp->mlx_ptr);
}

static int	ft_check_call(t_fractol *fp, int argc, char **argv)
{
	if (!ft_strncmp("mandelbrot\0", argv[1], 11))
		fp->mode = 1;
	else if (!ft_strncmp("julia\0", argv[1], 6) && argc == 4 \
&& (ft_str_to_float(argv[2]) >= -2 && ft_str_to_float(argv[2]) <= 2 \
&& ft_str_to_float(argv[3]) >= -2 && ft_str_to_float(argv[3]) <= 2))
	{
		fp->mode = 2;
		fp->c_real = ft_str_to_float(argv[2]);
		fp->c_im = ft_str_to_float(argv[3]);
	}
	else
	{
		ft_notify_wrong_usage(fp);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	*fp;

	fp = NULL;
	fp = ft_calloc(1, sizeof(t_fractol));
	if (!fp)
		ft_handle_error(0, NULL);
	fp->img_ptr = ft_calloc(1, sizeof(t_img));
	if (!fp->img_ptr)
		ft_handle_error(1, fp);
	fp->img_ptr->p = NULL;
	fp->img_ptr->data = NULL;
	fp->img_ptr->bits_per_pixel = 0;
	fp->img_ptr->line_len = 0;
	fp->img_ptr->endian = 0;
	if (argc < 2 || argc > 4 || ft_check_call(fp, argc, argv))
		ft_notify_wrong_usage(fp);
	ft_run_time(fp);
	ft_clean_exit(fp);
	return (0);
}
