/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_interesect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:51:29 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/21 16:26:02 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec2	ft_sphere_intersect(t_camera *cam, t_vec3 *ray, t_sphere *sphere)
{
	float	b; //сделать еще одну структуру =D
	float	c;
	float	discr;
	float	dist_1;
	float	dist_2;
	t_vec3	cam_sphere;

	cam_sphere = ft_sub(&cam->origin, &sphere->center);
	b = 2 * (ft_dot(&cam_sphere, ray));
	c = ft_dot(&cam_sphere, &cam_sphere) - (sphere->rad * sphere->rad);
	discr = (b * b) - (4 * c);
	res = (t_vec2){};
	if (discr < 0)
		return (res);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist_1 > 0)
		res.dist = dist_1;
	else if (dist_2 > 0)
		res.dist = dist_2;
	if (res.dist != 0)
		res.color = sphere->color;
	return (res);
}

int	ft_get_color(t_vec3 *color)
{
	int	res;
	int	red;
	int	green;
	int	blue;

	red = (int)roundf(color->x);
	if (red > 255)
		red = 255;
	else if (red < 0)
		red = 0;
	green = (int)roundf(color->y);
	if (green > 255)
		green = 255;
	else if (green < 0)
		green = 0;
	blue = (int)roundf(color->z);
	if (blue > 255)
		blue = 255;
	else if (blue < 0)
		blue = 0;
	res = (red << 16) | (green << 8) | blue;
	return (res);
}

int	ft_pxl_color(t_main *data, t_scene *scene, t_shapes *sh, t_vec3 *ray) //ищу пересечение вех фигур
{
	int			color;
	t_sphere	*tmp;
	t_vec2		res;
	t_vec2		check;
	t_vec3		light_dir;

	tmp = sh->sp;
	check = (t_vec2){};
	check.dist = 2147483647;
	while (tmp)
	{
		res = ft_sphere_intersect(scene->cam, ray, tmp);
		if (res.dist != 0 && res.dist < check.dist)
		{
			check.dist = res.dist;
			check.color = res.color;
		}
		tmp = tmp->next;
	}
	// if (check.color.x || check.color.y || check.color.z)
	// {
	// 	light_dir = ft_norm(ft_sub(scene->lght->location, ))
	// }
	color = ft_get_color(&check.color);
	return (color);
}
