#ifndef MINIRT_H
# define MINIRT_H

/* 1. INCLUDES */
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "vector.h"

/* 2. DEFINES & KEYCODES */
# define ESC 65307
# define ESC_1 53
# define KEY_C 99
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* 3. STRUCTURES */

// Image MLX
typedef struct s_img
{
	void	*p;
	char	*data;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
}	t_img;

// Optique & Rayons
typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;
}	t_camera;

// Formes géométriques
typedef struct s_sphere
{
	t_vec3	center;
	double	diameter;
	double	radius;
	t_vec3	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_vec3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	diameter;
	double	height;
	t_vec3	color;
}	t_cylinder;

// Scène Globale MLX
typedef struct s_scene
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img_ptr;
	int			win_width;
	int			win_height;
	int			x;
	int			y;
	int			color;
	t_camera	camera;
}	t_scene;

/* 4. PROTOTYPES */

// Rendering & MLX
void	ft_render_scene(t_scene *scene);
void	ft_put_pixel(int x, int y, unsigned int color, t_scene *scene);
int		ft_put_img_to_window(t_scene *scene);

// Ray-tracing Engine
t_ray	ft_generate_ray(t_camera *cam, double u, double v);
double	ft_hit_sphere(t_sphere sp, t_ray ray);
double	ft_hit_plane(t_plane pl, t_ray ray);
double	ft_hit_cylinder(t_cylinder cy, t_ray ray);

// Events & Utils
int		key_handler(int key, t_scene *scene);
int		mouse_handler(int button, int x, int y, t_scene *scene);
double	ft_str_to_float(char *s);
int		ft_clean_exit(t_scene *scene);
void	ft_handle_error(int n, t_scene *scene);
void	ft_free_null(void **p);
void	ft_notify_wrong_usage(t_scene *scene);

#endif