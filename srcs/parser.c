/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/07 18:01:59 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_parser(int argc, char **argv, t_main *data)
{
	t_shapes	sh;
	t_sphere	*sphere;
	t_vec3		sphere_center;
	t_sphere	*sphere2;
	t_vec3		sphere_center2;
	t_camera	*cam;
	t_vec3		cam_origin;
	t_vec3		cam_direction;

	sphere_center = ft_new_vec3(3, 2, -32);
	sphere = ft_new_sphere(&sphere_center, 16777215, 12 / 2);
	sphere_center2 = ft_new_vec3(10, 6, -322);
	sphere2 = ft_new_sphere(&sphere_center2, 255000000, 12 / 2);
	ft_sphere_add_back(&sphere, sphere2);
	cam_origin = ft_new_vec3(2, 0, 0);
	cam_direction = ft_new_vec3(0, 0, -1);
	cam = ft_new_camera(&cam_origin, &cam_direction, 70);
	sh = ft_new_shapes(sphere);
	data->scene = ft_new_scene(cam, &sh);
	argc = 0; //del
	argv = NULL; //del
	return (0);
}
