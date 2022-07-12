/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_interesect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:51:29 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/12 15:22:16 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_sphere_intersect(t_camera *cam, t_vec3 *ray, t_sphere *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist_1;
	float	dist_2;
	t_vec3	cam_sphere;
	
	cam_sphere = ft_sub(&cam->origin, &sphere->center);
	b = 2 * (ft_dot(&cam_sphere, ray));
	c = ft_dot(&cam_sphere, &cam_sphere) - (sphere->rad * sphere->rad);
	discr = (b * b) - (4 * c);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	// printf("dist_1 - %f\n", dist_1); //del
	// printf("dist_2 - %f\n", dist_2); //del
	// sleep(1); //del
	if (dist_1 > 0)
		return (1);
	else if (dist_2 > 0)
		return (1);
	return (0);
}

int	ft_pxl_color(t_main *data, t_scene *scene, t_shapes *sh, t_vec3 *ray)
{
	int	color;

	if (ft_sphere_intersect(scene->cam, ray, scene->sh.sp))
		color = 65280;
	else
		color = BLACK;
	// color = func;
	return (color);
}
