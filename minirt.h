/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:21:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/13 19:03:10 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600
# define BLACK 0
# define WHITE 16777215
# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define ESC 53

typedef struct s_vplane
{
	float			width;
	float			height;
	float			x_pixel;
	float			y_pixel;
}	t_vplane;

typedef struct s_vec3
{
	float			x;
	float			y;
	float			z;
}	t_vec3;

// typedef struct s_ambient //добавить когда появится общий свет
// {
// 	float			bright;
// 	int				color;
// }	t_ambient;

typedef struct s_camera
{
	t_vec3			origin;
	t_vec3			direction;
	float			fov;
}	t_camera;

// typedef struct s_light //добавить когда появится точечный свет
// {
// 	t_vec3			location;
// 	float			bright;
// 	int				color;
// }	t_light:

// typedef struct s_plane //добавить когда появяться фигуры
// {
// 	t_vec3			;
// 	struct s_plane	*next;
// }	t_plane;

// typedef struct s_cylinder //добавить когда появяться фигуры
// {
// 	t_vec3			;
// 	struct s_cylinder	*next;
// } 	t_cylinder;

typedef struct s_sphere
{
	t_vec3			center;
	t_vec3			color;
	float			rad;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_shapes
{
	t_sphere		*sp;
	// t_cylinder		*cy; //добавить когда появяться фигуры
	// t_plane			*pl; //добавить когда появяться фигуры
}	t_shapes;

typedef struct s_scene
{
	// t_аmbient		*amb; //добавить когда появится общий свет
	t_camera		*cam;
	// t_light			*lght; //добавить когда появится точечный свет
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

typedef struct s_vec2
{
	float			dist;
	t_vec3			color;
}	t_vec2;

typedef struct s_main
{
	t_scene			*scene;
	char			*n_wndw; //поставить в окно запуска программы
	t_vec3			calib;
	t_mlx			*mlx;
	t_vplane		*vplane;
}	t_main;

/* parser */
int			ft_parser(int argc, char **argv, t_main *data);

/* vec3_one */
t_vec3		ft_new_vec3(float x, float y, float z);
t_vec3		ft_sub(t_vec3 *a, t_vec3 *b);
float		ft_length(t_vec3 *a);
void		ft_norm(t_vec3 *a);
float		ft_dot(t_vec3 *a, t_vec3 *b);

/* vec3_two */
t_vec3		ft_add(t_vec3 *a, t_vec3 *b);
t_vec3		ft_mul(t_vec3 *a, t_vec3 *b);
t_vec3		ft_s_mul(t_vec3 *a, float value);
t_vec3		ft_cross(t_vec3 *a, t_vec3 *b);
t_vec3		reflect(t_vec3 *rd, t_vec3 *n);

/* sphere */
t_sphere	*ft_new_sphere(t_vec3 *center, t_vec3 *color, float rad);
void		ft_sphere_add_front(t_sphere **lst, t_sphere *new);
t_sphere	*ft_sphere_last(t_sphere *lst);
void		ft_sphere_add_back(t_sphere **lst, t_sphere *new);

/* draw */
int			ft_initialization(t_main *data, t_scene *scene);
int			ft_draw(t_main *data, t_scene *scene);

t_camera	*ft_new_camera(t_vec3 *origin, t_vec3 *direction, float fov);

/* scene */
t_scene		*ft_new_scene(t_camera *cam, t_shapes *sh);
t_shapes	ft_new_shapes(t_sphere	*sp);

t_vplane	*ft_get_view_plane(float width, float height, float fov);

/* calibration */
void		ft_calibration(t_main *data, t_scene *scene, t_camera *cam);

void		ft_ray_tracing(t_main *data, void *mlx, void *window, t_scene *scene);

// float		ft_sphere_intersect(t_camera *cam, t_vec3 *ray, t_sphere *sphere);
int			ft_pxl_color(t_main *data, t_scene *scene, t_shapes *sh, t_vec3 *ray);

int			ft_buttons(int key, t_main *data);
int			ft_exit_cross(int key, t_main *data);

/* program_completion */
void		ft_program_completion(t_main *data, char *error, int flag);

#endif

/*  */