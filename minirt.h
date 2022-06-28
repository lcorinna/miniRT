/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:21:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/28 18:02:13 by lcorinna         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define MOVE 10

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

typedef struct s_sphere
{
	t_vec3			*center;
	float			rad;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_camera
{
	t_vec3			*origin;
	t_vec3			*direction;
	float			fov;
}	t_camera;

typedef struct s_scene
{
	t_camera		*cams;
	t_sphere		*sphere;
	float			width;
	float			height;
}	t_scene;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
}	t_mlx;

typedef struct s_main
{
	t_mlx			*mlx;
	t_scene			*scene;
	char			*name_win; //поставить в окно запуска программы
}	t_main;

/*vec3_one*/
t_vec3		*ft_new_vec3(float x, float y, float z);
t_vec3		*ft_sub(t_vec3 *a, t_vec3 *b);
float		ft_length(t_vec3 *a);
void		ft_norm(t_vec3 *a);
float		ft_dot(t_vec3 *a, t_vec3 *b);

/*vec3_two*/
t_vec3		*ft_add(t_vec3 *a, t_vec3 *b);
t_vec3		*ft_mul(t_vec3 *a, t_vec3 *b);
t_vec3		*ft_s_mul(t_vec3 *a, float value);
t_vec3		*ft_cross(t_vec3 *a, t_vec3 *b);
t_vec3		*reflect(t_vec3 *rd, t_vec3 *n);

/*sphere*/
t_sphere	*ft_new_sphere(t_vec3 *center, float rad);
void		ft_sphere_add_front(t_sphere **lst, t_sphere *new);
t_sphere	*ft_sphere_last(t_sphere *lst);
void		ft_sphere_add_back(t_sphere **lst, t_sphere *new);

t_camera	*ft_new_camera(t_vec3 *origin, t_vec3 *direction, float fov);

t_scene		*ft_new_scene(t_camera *cam, t_sphere *sphere);

t_vplane	*ft_get_view_plane(float width, float height, float fov);

void		ray_tracing(void *mlx, void *window, t_scene *scene);

int			ft_sphere_intersect(t_camera *cam, t_vec3 *ray, t_sphere *sphere);

#endif

/**/