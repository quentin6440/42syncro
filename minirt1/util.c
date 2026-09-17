#include "../include/minirt.h"

void	ft_notify_wrong_usage(t_fractol *fp)
{
	ft_putendl_fd("WRONG USAGE, read the freaking manual mate", 2);
	ft_putendl_fd("Try: ./fractol mandelbrot or ./fractol julia <real> <imag>", \
2);
	ft_putendl_fd("where <real> and <imag> are between -2.0 and +2.0", 1);
	ft_clean_exit(fp);
}

void	ft_free_null(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

int	ft_clean_exit(t_fractol *fp)
{
	if (!fp)
		exit (0);
	if (fp->mlx_ptr)
	{
		if (fp->img_ptr && fp->img_ptr->p)
		{
			mlx_destroy_image(fp->mlx_ptr, fp->img_ptr->p);
			fp->img_ptr->p = NULL;
		}
		if (fp->win_ptr)
		{
			mlx_destroy_window(fp->mlx_ptr, fp->win_ptr);
			fp->win_ptr = NULL;
		}
		mlx_destroy_display(fp->mlx_ptr);
		fp->mlx_ptr = NULL;
	}
	if (fp->img_ptr)
		ft_free_null((void **)&fp->img_ptr);
	ft_putendl_fd("MLX instance/context freed successfully", 1);
	ft_free_null((void **)&fp);
	exit (0);
}

void	ft_handle_error(int n, t_fractol *fp)
{
	if (n == 0)
	{
		ft_putendl_fd("error 0", 2);
		exit(0);
	}
	ft_putstr_fd("error numero ", 2);
	ft_putnbr_fd(n, 2);
	ft_putchar_fd('\n', 2);
	ft_clean_exit(fp);
}

double	ft_str_to_float(char *s)
{
	double	nb;
	int		precision_factor;
	int		sign;
	int		i;

	nb = 0.0;
	precision_factor = 1;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
		nb = 10 * nb + (s[i++] - 48);
	if (s[i] == '.' || s[i] == ',')
		i++;
	while (s[i] >= 48 && s[i] <= 57)
	{
		nb = 10 * nb + (s[i++] - 48);
		precision_factor *= 10;
	}
	return (sign * nb / precision_factor);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s  = "-13.28";
	printf("str = %s and then : %f\n", s, ft_strToFloat(s));
	return (0);
}*/
