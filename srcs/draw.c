/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:38:49 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/25 20:53:35 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_mlx	ft_new_mlx(t_main *data)
{
	t_mlx	new;

	new = (t_mlx){};
	new.mlx = mlx_init();
	if (!new.mlx)
		ft_exit("mlx_init error\n", 2);
	new.win = mlx_new_window(new.mlx, WIDTH, HEIGHT, "miniRT"); //change
	if (!new.win)
		ft_exit("mlx_new_window error\n", 2);
	return (new);
}

int	ft_initialization(t_main *data)
{
	data->mlx = ft_new_mlx(data);
	mlx_hook(data->mlx.win, 2, 1L << 0, ft_buttons, data);
	mlx_hook(data->mlx.win, 17, 0, ft_exit_cross, data);
	// mlx_hook(mlx->win_ptr, 02, 1L << 0, esc_key, (void *)mlx);
	return (0);
}

void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *) dest = color;
}

void	ft_new_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		ft_exit("mlx_new_image error\n", 2);
	mlx->addr = mlx_get_data_addr(mlx->img, \
							mlx->bits_per_pixel, mlx->line_length, mlx->endian);
	if (mlx->addr == NULL)
		ft_exit("mlx_get_data_addr error\n", 2);
}

t_vec3	ft_find_dir(float dst, int x, int y, t_vec3	cam_dir)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;
	t_vec3	dir;

	a = ft_new_vec3(dst, x - WIDTH / 2, -(y - HEIGHT / 2));
	b = ft_new_vec3(-(x - WIDTH / 2), dst, -(y - HEIGHT / 2));
	c = ft_new_vec3(-(y - HEIGHT / 2), x - WIDTH / 2, dst);
	a = ft_s_mul(&a, cam_dir.x);
	b = ft_s_mul(&b, cam_dir.y);
	c = ft_s_mul(&c, cam_dir.z);
	dir = ft_add3(&a, &b, &c);
	return (dir);
}

t_vec3	ft_rotate_dir(t_camera *cam, t_vec3 *dir)
{
	float	n_x; //почему n? 
	float	n_y;
	float	n_z;
	float	cut;

	cut = cam->angle_y;
	n_x = dir->x * cos(cut) - dir->z * sin(cut); //это нужно?
	n_z = dir->x * sin(cut) + dir->z * cos(cut);
	cut = cam->angle_z;
	n_x = dir->x * cos(cut) - dir->y * sin(cut);
	n_y = dir->x * sin(cut) + dir->y * cos(cut);
	*dir = ft_new_vec3(n_x, n_y, dir->z);
	*dir = ft_norm(dir);
	return (*dir);
}

float	ft_plane_interect(t_shapes *plane, t_vec3 *cam_origin, t_vec3 *direction)
{
	float	res;
	float	t;
	t_vec3	subtraction;
	float	dot_product_1;
	float	dot_product_2;

	res = ft_dist(cam_origin, &plane->pos);
	subtraction = ft_sub(cam_origin, &plane->pos);
	dot_product_1 = ft_dot(&subtraction, &plane->direction);
	dot_product_2 = ft_dot(direction, &plane->direction);
	t = -(dot_product_1 / dot_product_2);
	return (t);
}

float	ft_calc_t(float ca_co_cp, float cadir, float caca, float res)
{
	float	t;

	if (res < 0)
		t = (0 - ca_co_cp) / cadir;
	else
		t = (caca - ca_co_cp) / cadir;
	return (t);
}

float	ft_cylinder_intersect(t_shapes *cyl, t_vec3 *cam_origin, t_vec3 *direction)
{
	float	res; //сделать доп функцию которая вернет результат
	float	a; //почему такие названия переменных? дискриминант?
	float	b; ////сделать еще одну структуру =D //см. пересечение со сферой
	float	c;
	t_vec3	ca;
	t_vec3	tmp;

	tmp = ft_s_mul(&cyl->direction, cyl->height);
	tmp = ft_add(&cyl->pos, &tmp);
	ca = ft_sub(&tmp, &cyl->pos);
	a = ft_dot(&ca, &ca) - ft_dot(&ca, direction) * ft_dot(&ca, direction);
	tmp = ft_sub(cam_origin, &cyl->pos);
	b = ft_dot(&ca, &ca) * ft_dot(&tmp, direction) - ft_dot(&ca, &tmp) * ft_dot(&ca, direction);
	tmp = ft_sub(cam_origin, &cyl->pos);
	c = ft_dot(&ca, &ca) * ft_dot(&tmp, &tmp) - ft_dot(&ca, &tmp) * ft_dot(&ca, &tmp) - cyl->rad * cyl->rad * ft_dot(&ca, &ca);
	if ((b * b - a * c) < 0)
		return (0);
	tmp = ft_sub(cam_origin, &cyl->pos);
	res = ft_dot(&ca, &tmp) + ((-b - sqrt((b * b - a * c))) / a) * ft_dot(&ca, direction);
	if (res > 0 && res < ft_dot(&ca, &ca))
		return (((-b - sqrt((b * b - a * c))) / a));
	tmp = ft_sub(cam_origin, &cyl->pos);
	res = ft_calc_t(ft_dot(&ca, &tmp), ft_dot(&ca, direction), ft_dot(&ca, &ca), res);
	if (fabs(b + a * res) < sqrt((b * b - a * c)))
		return (res);
	return (0);
}

float	ft_find_dist(t_shapes *sh, t_vec3 *cam_origin, t_vec3 *direction)
{
	float	distance;

	distance = 0;
	if (sh->type == SPHERE)
		distance = ft_sphere_intersect(sh, cam_origin, direction);
	else if (sh->type == PLANE)
		distance = ft_plane_intersect(sh, cam_origin, direction);
	else if (sh->type == CYLINDER)
		distance = ft_cylinder_intersect(sh, cam_origin, direction);
	return (distance);
}

int	ft_lighting(t_main *data, t_shapes *tmp, t_vec3 *direction, float dist)
{
	
	return (0); //clr
}


int	ft_intersection(t_main *data, t_shapes *sh, t_vec3 direction)
{
	float		dist;
	float		dist_min;
	t_vec3		clr;
	int			color;
	t_shapes	*tmp;

	dist_min = MAXFLOAT;
	color = BLACK;
	tmp = sh;
	while (tmp)
	{
		dist = ft_find_dist(tmp, &data->scene.cam.origin, &direction);
		if (dist > 0 && dist < dist_min)
		{
			dist_min = dist;
			// clr = tmp->clr; //это нужно тестировать
			color = ft_lighting(data, tmp, &direction, dist);
		}
		tmp = tmp->next;
	}
	// color = ft_get_color(&clr); //это нужно тестировать
	return (color);
}

void	ft_draw_loop(t_main *data, t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;
	int		clr;
	t_vec3	direction;
	float	dst;

	y = -1;
	ft_new_image(mlx);
	dst = WIDTH / (2 * tanf(scene->cam.fov * M_PI / 360));
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			direction = ft_find_dir(dst, x, y, ft_norm(&scene->cam.direction));
			direction = ft_rotate_dir(&scene->cam, &direction);
			clr = ft_intersection(data, &data->scene.sh, direction);
			ft_mlx_pixel_put(&data->mlx, x, y, clr);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->img, mlx->addr);
}
