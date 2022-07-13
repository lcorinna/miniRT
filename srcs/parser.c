/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/13 18:59:15 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_parser(int argc, char **argv, t_main *data)
{
	t_shapes	sh;
	t_sphere	*sphere;
	t_vec3		sphere_center;
	t_vec3		sphere_color;
	t_sphere	*sphere2;
	t_vec3		sphere_center2;
	t_vec3		sphere_color2;
	t_sphere	*sphere3;
	t_vec3		sphere_center3;	
	t_vec3		sphere_color3;
	t_sphere	*sphere4;
	t_vec3		sphere_center4;
	t_vec3		sphere_color4;
	t_camera	*cam;
	t_vec3		cam_origin;
	t_vec3		cam_direction;

	// sphere_center = ft_new_vec3(0, 0, 0);
	sphere_center = ft_new_vec3(12, 5, -30);
	sphere_color = ft_new_vec3(255, 0, 0);
	sphere = ft_new_sphere(&sphere_center, &sphere_color, 12 / 2);
	sphere_center2 = ft_new_vec3(12, 5, -20);
	sphere_color2 = ft_new_vec3(0, 255, 0);
	sphere2 = ft_new_sphere(&sphere_center2, &sphere_color2, 6 / 2);
	sphere_center3 = ft_new_vec3(-14, -5, -25);
	sphere_color3 = ft_new_vec3(0, 0, 255);
	sphere3 = ft_new_sphere(&sphere_center3, &sphere_color3, 12 / 2);
	sphere_center4 = ft_new_vec3(10, 5, -31);
	sphere_color4 = ft_new_vec3(255, 255, 255);
	sphere4 = ft_new_sphere(&sphere_center4, &sphere_color4, 12 / 2);
	ft_sphere_add_back(&sphere, sphere2);
	ft_sphere_add_back(&sphere, sphere3);
	ft_sphere_add_back(&sphere, sphere4);
	cam_origin = ft_new_vec3(0, 0, 0);
	cam_direction = ft_new_vec3(0, 0, -1);
	cam = ft_new_camera(&cam_origin, &cam_direction, 70);
	sh = ft_new_shapes(sphere);
	data->scene = ft_new_scene(cam, &sh);
	argc = 0; //del
	argv = NULL; //del
	return (0);
}
