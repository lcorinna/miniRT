/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/30 19:54:10 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_parser(int argc, char **argv, t_main *data)
{
	t_sphere	*sphere;
	t_vec3		*sphere_center;
	t_camera	*cam;
	t_vec3		*cam_origin;
	t_vec3		*cam_direction;

	sphere_center = ft_new_vec3(10, 10, -300);
	sphere = ft_new_sphere(sphere_center, 100 / 2);
	cam_origin = ft_new_vec3(0, 0, 0);
	cam_direction = ft_new_vec3(0, 0, -1);
	cam = ft_new_camera(cam_origin, cam_direction, 70);
	data->scene = ft_new_scene(cam, sphere);
	argc = 0; //del
	argv = NULL; //del
	return (0);
}