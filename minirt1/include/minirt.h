#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define ESC 65307
# define ESC_1 53
# define KEY_C 99
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_img
{
	void	*p;
	char	*data;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img_ptr;
	int		mode;
	int		win_width;
	int		win_height;
	int		img_x;
	int		img_y;
	int		color;
	int		iteration;
	int		max_iteration;
	int		x;
	int		y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom_x;
	double	zoom_y;
	double	z_real;
	double	z_im;
	double	c_real;
	double	c_im;
	double	temp;
	float	display_shift;
}	t_fractol;

double	ft_str_to_float(char *s);
int		ft_clean_exit(t_fractol *fp);
void	ft_handle_error(int n, t_fractol *fp);
void	ft_free_null(void **p);
void	ft_notify_wrong_usage(t_fractol *fp);
int		mouse_handler(int button, int x, int y, t_fractol *fp);
int		key_handler(int key, t_fractol *fp);
void	ft_put_pixel(int x, int y, unsigned int color, t_fractol *fp);
int		ft_put_img_to_window(t_fractol *fp);

#endif
