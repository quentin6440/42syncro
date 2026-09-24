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

#define EPSILON 1e-6

/* 3. STRUCTURES */

typedef struct s_img
{
	void	*p;
	char	*data;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
}	t_img;

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

typedef struct s_ambient
{
	double	ratio;
	t_vec3	color;
}	t_ambient;

typedef struct s_light
{
	t_vec3	pos;
	double	ratio;
	t_vec3	color;
}	t_light;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_obj
{
	t_type			type;
	t_vec3			pos;
	t_vec3			dir;
	double			diameter;
	double			height;
	t_vec3			color;
	struct s_obj	*next;
}	t_obj;

typedef struct s_scene
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img_ptr;
	int			win_width;
	int			win_height;
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_obj		*objects;
}	t_scene;

/* 4. PROTOTYPES */

/* --- PARSING --- */
int		ft_parse_rt(int fd, t_scene *scene);
int		ft_parse_line(char **tokens, t_scene *scene);
int		ft_parse_ambient(char **tokens, t_scene *scene);
int		ft_parse_camera(char **tokens, t_scene *scene);
int		ft_parse_light(char **tokens, t_scene *scene);
int		ft_parse_obj(char **tokens, t_scene *scene, t_type type);

/* --- RAYTRACING & RENDERING --- */
void	ft_render_scene(t_scene *scene);
t_ray	ft_generate_ray(t_camera *cam, double u, double v, t_scene *scene);
t_vec3	ft_get_normal(t_obj *obj, t_vec3 hit_p, t_ray ray);

double	ft_hit_sphere(t_obj *sp, t_ray ray);
double	ft_hit_plane(t_obj *pl, t_ray ray);
double	ft_hit_cylinder(t_obj *cy, t_ray ray);
double	ft_hit_cylinder_caps(t_obj *obj, t_ray ray, t_vec3 *out_norm);
double	ft_hit_cylinder_side(t_obj *obj, t_ray ray);

/* mlx / render utils */
int		ft_put_img_to_window(t_scene *scene);
void	ft_mlx_pixel_put(t_scene *scene, int x, int y, int color);

/* --- EVENTS & HOOKS --- */
int		key_handler(int key, void *param);
int		mouse_handler(int button, int x, int y, void *param);

/* --- CLEAN & MEMORY UTILS --- */
void	ft_free_tab(char **tab);
void	ft_free_objects(t_obj **lst);
void	ft_free_null(void **p);
int		ft_clean_exit(t_scene *scene);
void	ft_error(char *msg, t_scene *scene);

/* --- PARSING CONVERSIONS --- */
int	ft_str_to_float(char *str, double *out);
int	ft_str_to_vec3(char *str, t_vec3 *vec, int is_dir);

#endif