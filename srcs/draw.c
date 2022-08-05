/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:38:49 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/05 19:05:12 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_mlx	ft_new_mlx(t_main *data)
{
	t_mlx	new;

	new = (t_mlx){};
	new.mlx = mlx_init();
	if (!new.mlx)
		ft_exit(data, "mlx_init error\n", 2);
	new.win = mlx_new_window(new.mlx, WIDTH, HEIGHT, data->n_wndw);
	if (!new.win)
		ft_exit(data, "mlx_new_window error\n", 2);
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

void	ft_new_image(t_main *data, t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		ft_exit(data, "mlx_new_image error\n", 2);
	mlx->addr = mlx_get_data_addr(mlx->img, \
							mlx->bits_per_pixel, mlx->line_length, mlx->endian);
	if (mlx->addr == NULL)
		ft_exit(data, "mlx_get_data_addr error\n", 2);
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
	float	n_x; //new 
	float	n_y;
	float	n_z;
	float	cut;

	cut = cam->angle_y;
	n_x = dir->x * cos(cut) - dir->z * sin(cut);
	n_z = dir->x * sin(cut) + dir->z * cos(cut);
	cut = cam->angle_z;
	n_x = dir->x * cos(cut) - dir->y * sin(cut);
	n_y = dir->x * sin(cut) + dir->y * cos(cut);
	*dir = ft_new_vec3(n_x, n_y, dir->z);
	*dir = ft_norm(dir);
	return (*dir);
}

float	ft_plane_intersect(t_shapes *plane, t_vec3 *cam_origin, t_vec3 *direction)
{
	float	res;
	float	t;
	t_vec3	subtraction;
	float	dot_product_1;
	float	dot_product_2;

	res = ft_dist(*cam_origin, plane->pos);
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

t_vec3	ft_cylinder_norm(t_shapes *cyl, t_vec3 *inter_point)
{
	t_vec3	norm;
	t_vec3	top_center;
	t_vec3	pt;
	t_vec3	tmp;
	float	t;

	tmp = ft_s_mul(&cyl->direction, cyl->height);
	top_center = ft_add(&cyl->pos, &tmp);
	if (ft_length(ft_sub(inter_point, &cyl->pos)) < cyl->rad)
		norm = ft_s_mul(&(cyl->pos), -1);
	else if (ft_length(ft_sub(inter_point, &top_center)) < cyl->rad)
		norm = cyl->direction;
	else
	{
		tmp = ft_sub(inter_point, &cyl->pos);
		t = ft_dot(&tmp, &(cyl->direction));
		tmp = ft_s_mul(&(cyl->direction), t);
		pt = ft_add(&(cyl->pos), &tmp);
		tmp = ft_sub(inter_point, &pt);
		norm = ft_norm(&tmp);
	}
	return (norm);
}

float	ft_drop_shadow(t_main *data, t_shapes *shape, t_vec3 *inter_point)
{
	t_vec3		dir;
	t_vec3		vec_tmp;
	t_shapes	*tmp;
	float		dist;

	vec_tmp = ft_sub(&(data->scene.lght.pos), inter_point);
	dir = ft_norm(&vec_tmp);
	tmp = data->scene.sh;
	while (tmp)
	{
		dist = ft_find_dist(tmp, inter_point, &dir);
		if (tmp->type != shape->type)
		{
			if (dist > 0 && dist < ft_dist(*inter_point, data->scene.lght.pos) \
			&& tmp != shape)
// && tmp->pos != shape->pos && tmp->clr != shape->clr) //возможно нужно больше условий
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_rgb(int color, char level)
{
	if (level == 'R')
		return ((color >> 16) & 0xFF);
	else if (level == 'G')
		return ((color >> 8) & 0xFF);
	else if (level == 'B')
		return (color & 0xFF);
	return (0);
}

int	ft_add_color3(int c1, int c2, int c3)
{
	int	res;
	int	r;
	int	g;
	int	b;

	r = rgb(c1, 'R') + rgb(c2, 'R') + rgb(c3, 'R');
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	g = rgb(c1, 'G') + rgb(c2, 'G') + rgb(c3, 'G');
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	b = rgb(c1, 'B') + rgb(c2, 'B') + rgb(c3, 'B');
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	res = (r << 16) | (g << 8) | b;
	return (res);
}

int	ft_mul_clr(t_vec3 clr, float ratio)
{
	int	res;
	int	r;
	int	g;
	int	b;

	r = clr.x * ratio;
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	g = clr.y * ratio;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	b = clr.z * ratio;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	res = (r << 16) | (g << 8) | b;
	return (res);
}

float	ft_diff_lght(t_vec3 nrmlz, t_vec3 inter_point, t_main *data)
{
	t_vec3	spot;
	t_vec3	tmp;
	float	res;

	tmp = ft_sub(&(data->scene.lght.pos), &inter_point);
	spot = ft_norm(&tmp);
	res = ft_dot(&nrmlz, &spot);
	return (res * data->scene.lght.bright);
}

float	ft_spec_lght(t_vec3	nrmlz, t_vec3 direction, t_vec3 inter_point, t_main *data)
{
	float	bright;
	t_vec3	reflect;
	t_vec3	spot;
	t_vec3	tmp;

	bright = data->scene.lght.bright;
	tmp = ft_sub(&(data->scene.lght.bright), &inter_point);
	spot = ft_norm(&tmp);
	reflect = ft_reflect(&direction, &nrmlz);
	return (pow(f_max(ft_dot(&reflect, &spot), 0), 32) * bright);
}

int	ft_lighting(t_main *data, t_shapes *shape, t_vec3 *direction, float dist)
{
	t_vec3	inter_point;
	t_vec3	nrmlz;
	t_vec3	tmp;
	float	drop;
	int		clr;

	tmp = ft_s_mul(direction, dist);
	inter_point = ft_add(&(data->scene.cam.origin), &tmp);
	if (shape->type == SPHERE)
	{
		tmp = ft_add(&inter_point, &(shape->pos));
		nrmlz = ft_norm(&tmp);
	}
	else if (shape->type == PLANE)
		nrmlz = ft_norm(&(shape->direction));
	else if (shape->type == CYLINDER)
		nrmlz = ft_cylinder_norm(shape, &inter_point);
	drop = ft_drop_shadow(data, shape, &inter_point);
	clr = ft_add_clr3(ft_mul_clr(shape->clr, data->scene.amb.bright), \
	ft_mul_clr(shape->clr, ft_diff_lght(nrmlz, inter_point, data) * DIFF), \
	ft_mul_clr(shape->clr, ft_spec_lght(nrmlz, *direction, inter_point, data) * SPEC));
	// if (drop == 0)
	// {
		
	// }
	// else if (drop == 1)
	// {
		
	// }
	return (clr);
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
	ft_new_image(data, mlx);
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
