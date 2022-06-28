/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_interesect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:51:29 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/28 13:15:09 by lcorinna         ###   ########.fr       */
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
	t_vec3	*cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = ft_sub(cam->origin, sphere->center);
	b = 2 * (ft_dot(cam_sphere, ray));
	c = ft_dot(cam_sphere, cam_sphere) - (sphere->rad * sphere->rad);
	discr = (b * b) - (4 * c);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist_1 > 0)
		return (1);
	free(cam_sphere);
	return (0);
}
