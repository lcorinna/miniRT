/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_interesect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:51:29 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/06 19:52:13 by lcorinna         ###   ########.fr       */
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

	// printf("HERE\n"); //del
	cam_sphere = ft_sub(&cam->origin, &sphere->center);
	b = 2 * (ft_dot(&cam_sphere, ray));
	// printf("b - %f\n", b); //del
	// sleep(1);
	c = ft_dot(&cam_sphere, &cam_sphere) - (sphere->rad * sphere->rad);
	// printf("cam_sphere - %f\n", cam_sphere.x); //del
	// free(cam_sphere);
	discr = (b * b) - (4 * c);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist_1 > 0)
		return (1);
	// printf("cam_sphere - %p\n", cam_sphere); //del
	// printf("cam_sphere - %p\n", cam_sphere); //del
	return (0);
}
