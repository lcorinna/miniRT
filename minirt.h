/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:21:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/29 15:02:19 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "mlx/mlx.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/* shapes */
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

/*  window */
# define WIDTH 800
# define HEIGHT 600

/* color */
# define BLACK 0
# define WHITE 16777215
# define RED 16711680
# define GREEN 65280
# define BLUE 255

/* buttons */
# define ESC 53

typedef struct s_vec3
{
	float			x;
	float			y;
	float			z;
}	t_vec3;

typedef struct s_ambient
{
	float			bright;
	t_vec3			clr;
}	t_ambient;

typedef struct s_camera
{
	t_vec3			origin;
	t_vec3			direction;
	float			fov;
	float			angle_y;
	float			angle_z;
}	t_camera;

typedef struct s_light
{
	t_vec3			pos;
	float			bright;
	t_vec3			clr;
}	t_light;

typedef struct s_shapes
{
	int					type;
	t_vec3				pos; //sphere plane cylinder
	t_vec3				clr; //sphere plane cylinder
	float				rad; //sphere
	t_vec3				direction; //plane
	float				diameter; //cylinder
	float				height; //cylinder
	struct s_shapes		*next;
}	t_shapes;

typedef struct s_scene
{
	t_ambient		amb;
	t_camera		cam;
	t_light			lght;
	t_shapes		sh;
	float			width;
	float			height;
}	t_scene;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;

	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_mlx;

typedef struct s_main
{
	int				fd;
	char			*n_wndw;
	char			**maps;
	t_scene			scene;
	t_mlx			mlx;
}	t_main;

/* parser */
int			ft_parser(int argc, char **argv, t_main *data);

/* vec3_one */
t_vec3		ft_new_vec3(float x, float y, float z);
t_vec3		ft_sub(t_vec3 *a, t_vec3 *b);
float		ft_length(t_vec3 a);
t_vec3		ft_norm(t_vec3 *a);
float		ft_dot(t_vec3 *a, t_vec3 *b);

/* vec3_two */
t_vec3		ft_add(t_vec3 *a, t_vec3 *b);
t_vec3		ft_add3(t_vec3 *a, t_vec3 *b, t_vec3 *c);
t_vec3		ft_mul(t_vec3 *a, t_vec3 *b);
t_vec3		ft_s_mul(t_vec3 *a, float value);
t_vec3		ft_cross(t_vec3 *a, t_vec3 *b);
float		ft_dist(t_vec3 a, t_vec3 b);
t_vec3		reflect(t_vec3 *rd, t_vec3 *n);

/* shapes */
t_shapes	ft_new_sphere(t_vec3 *center, t_vec3 *color, float rad);
void		ft_shape_add_front(t_shapes **lst, t_shapes *new);
t_shapes	*ft_shape_last(t_shapes *lst);
void		ft_shape_add_back(t_shapes **lst, t_shapes *new);

/* draw */
int			ft_initialization(t_main *data);
void		ft_draw_loop(t_main *data, t_scene *scene, t_mlx *mlx);

/* camera */
t_camera	ft_new_camera(t_vec3 *origin, t_vec3 *direction, float fov);

/* light */
t_ambient	ft_new_amb(float bright, t_vec3 *clr);
t_light		ft_new_light(t_vec3 *position, float bright, t_vec3 *color);

/* scene */
t_scene		ft_new_scene(t_ambient *ambient, t_camera *cam, t_light *light, t_shapes *sh);

/* calibration */
void		ft_calibration(t_main *data, t_scene *scene, t_camera *cam);

void		ft_ray_tracing(t_main *data, void *mlx, void *window, t_scene *scene);

// t_vec2		ft_sphere_intersect(t_camera *cam, t_vec3 *ray, t_sphere *sphere);
int			ft_pxl_color(t_main *data, t_scene *scene, t_shapes *sh, t_vec3 *ray);

/* buttons */
int			ft_buttons(int key, t_main *data);
int			ft_exit_cross(int key, t_main *data);

/* program_completion */
int			ft_exit(char *str, int flag);

#endif

/*  */