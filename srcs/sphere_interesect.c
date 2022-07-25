/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_interesect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:51:29 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/25 20:52:24 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	ft_sphere_intersect(t_shapes *sphere, t_vec3 *cam_origin, t_vec3 *direction)
{
	float	b; //сделать еще одну структуру =D //см. пересечение цилиндра
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
