/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/20 20:31:13 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_parser(int argc, char **argv, t_main *data)
{
	t_shapes	sh;
	t_shapes	sphere;
	t_vec3		sphere_center;
	t_vec3		sphere_color;
	t_camera	cam;
	t_vec3		cam_origin;
	t_vec3		cam_direction;
	t_light		lght;
	t_vec3		lght_pos;
	t_vec3		lght_clr;

	// sphere_center = ft_new_vec3(0, 0, 0);
	sphere_center = ft_new_vec3(12, 5, -30); //делаю сферу
	sphere_color = ft_new_vec3(255, 0, 0);
	sphere = ft_new_sphere(&sphere_center, &sphere_color, 12 / 2);
	lght_pos = ft_new_vec3(24, 20, -1); //делаю точечный свет
	lght_clr = ft_new_vec3(255, 255, 255);
	lght = ft_new_light(&lght_pos, 0.6, &lght_clr);
	cam_origin = ft_new_vec3(0, 0, 0);
	cam_direction = ft_new_vec3(0, 0, -1);
	cam = ft_new_camera(&cam_origin, &cam_direction, 70); //добовляю камеру
	sh = ft_new_shapes(sphere);
	data->scene = ft_new_scene(&cam, &lght, &sh); //добовляю все в структуру сцена
	argc = 0; //del
	argv = NULL; //del
	return (0);
}
