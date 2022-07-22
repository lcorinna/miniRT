/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_interesect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:51:29 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/22 20:29:09 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// float	ft_sphere_intersect(t_camera *cam, t_vec3 *ray, t_shapes *sphere)
float	ft_sphere_intersect(t_shapes *sphere, t_vec3 *cam_origin, t_vec3 *direction)
{
	float	b; //сделать еще одну структуру =D
	float	c;
	float	discr;
	float	dist_1;
	float	dist_2;
	float	min;
	float	max;
	float	res;
	t_vec3	cam_sphere;

	cam_sphere = ft_sub(cam_origin, &sphere->pos);
	b = 2 * (ft_dot(&cam_sphere, direction));
	c = ft_dot(&cam_sphere, &cam_sphere) - (sphere->rad * sphere->rad);
	discr = (b * b) - (4 * c);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	min = fminf(dist_1, dist_2);
	max = fmaxf(dist_1, dist_2);
	if (min >= 0)
		res = min;
	else
		res = max;
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
	t_vec3		light_dir;

	tmp = sh->sp;
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
	color = ft_get_color(&check.color);
	return (color);
}
