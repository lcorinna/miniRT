/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/21 16:27:01 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_parser(int argc, char **argv, t_main *data)
{
	t_ambient	amb;
	t_vec3		clr_amb;

	t_light		lght;
	t_vec3		lght_pos;
	t_vec3		lght_clr;

	t_camera	cam;
	t_vec3		cam_origin;
	t_vec3		cam_direction;
	
	t_shapes	sphere;
	t_vec3		sphere_center;
	t_vec3		sphere_color;

	clr_amb = ft_new_vec3(255, 255, 255);
	amb = ft_new_amb(0.5, &clr_amb); //добавляю общий свет

	cam_origin = ft_new_vec3(0, 0, 0);
	cam_direction = ft_new_vec3(0, 0, -1);
	cam = ft_new_camera(&cam_origin, &cam_direction, 70); //добавляю камеру

	lght_pos = ft_new_vec3(-200, 200, 300);
	lght_clr = ft_new_vec3(255, 255, 255);
	lght = ft_new_light(&lght_pos, 0.9, &lght_clr); //делаю точечный свет

	sphere_center = ft_new_vec3(50, 50, -50);
	sphere_color = ft_new_vec3(255, 0, 0);
	sphere = ft_new_sphere(&sphere_center, &sphere_color, 40 / 2); //делаю сферу

	data->scene = ft_new_scene(&amb, &cam, &lght, &sphere); //добавляю все в структуру сцена
	argc = 0; //del
	argv = NULL; //del
	return (0);
}
