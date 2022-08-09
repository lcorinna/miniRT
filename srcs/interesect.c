/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interesect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:12:27 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 16:30:06 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	ft_plane_intersect(t_shapes *plane, t_vec3 *cam_origin, \
															t_vec3 *direction)
{
	float	t;
	t_vec3	subtraction;
	float	dot_product_1;
	float	dot_product_2;

	subtraction = ft_sub(cam_origin, &plane->pos);
	dot_product_1 = ft_dot(&subtraction, &plane->direction);
	dot_product_2 = ft_dot(direction, &plane->direction);
	t = -dot_product_1 / dot_product_2;
	return (t);
}

float	ft_sphere_intersect(t_shapes *sphere, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box)
{
	float	dist_1;
	float	dist_2;
	float	min;
	float	max;
	t_vec3	cam_sphere;

	cam_sphere = ft_sub(cam_origin, &sphere->pos);
	box.b = 2 * (ft_dot(&cam_sphere, direction));
	box.c = ft_dot(&cam_sphere, &cam_sphere) - (sphere->rad * sphere->rad);
	box.discr = (box.b * box.b) - (4 * box.c);
	if (box.discr < 0)
		return (0);
	dist_1 = ((box.b * (-1)) - sqrt(box.discr)) / 2;
	dist_2 = ((box.b * (-1)) + sqrt(box.discr)) / 2;
	min = fminf(dist_1, dist_2);
	max = fmaxf(dist_1, dist_2);
	if (min >= 0)
		box.res = min;
	else
		box.res = max;
	return (box.res);
}

float	ft_find_dist(t_shapes *sh, t_vec3 *cam_origin, t_vec3 *direction)
{
	float		distance;
	t_discrmn	box;

	box = (t_discrmn){};
	distance = 0;
	if (sh->type == SPHERE)
		distance = ft_sphere_intersect(sh, cam_origin, direction, box);
	else if (sh->type == PLANE)
		distance = ft_plane_intersect(sh, cam_origin, direction);
	else if (sh->type == CYLINDER)
		distance = ft_cylinder_intersect(sh, cam_origin, direction, box);
	return (distance);
}

int	ft_intersection(t_main *data, t_shapes *sh, t_vec3 direction)
{
	float		dist;
	float		dist_min;
	int			color;
	t_shapes	*tmp;
	t_shapes	*res;

	res = NULL;
	dist_min = MAXFLOAT;
	color = BLACK;
	tmp = sh;
	while (tmp)
	{
		dist = ft_find_dist(tmp, &data->scene.cam.origin, &direction);
		if (dist > 0 && dist < dist_min)
		{
			dist_min = dist;
			res = tmp;
		}
		tmp = tmp->next;
	}
	if (res != NULL)
		color = ft_lighting(data, res, &direction, dist_min);
	return (color);
}
