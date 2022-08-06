/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:10:53 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/06 23:27:32 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_camera_movement(int key, t_main *data)
{
	// t_vec3	tmp;

	// if (key == 123)
	// 	tmp = ft_new_vec3(-1, 0, 0);
	// else if (key == 124)
	// 	tmp = ft_new_vec3(1, 0, 0);
	// else if (key == 126)
	// 	tmp = ft_new_vec3(0, 1, 0);
	// else if (key == 125)
	// 	tmp = ft_new_vec3(0, -1, 0);
	// printf("data->scene->cams->origin - %p\n", data->scene->cams->origin);
	// data->scene->cam->origin = ft_add(&data->scene->cam->origin, &tmp);
	// data->scene->sh.sp->center = ft_add(&data->scene->sh.sp->center, &tmp);
	// printf("data->scene->cams->origin - %p\n", data->scene->cams->origin);
	// mlx_clear_window(data->mlx->mlx, data->mlx->win);
}

int	ft_buttons(int key, t_main *data)
{
	printf("key - %d\n", key); //del
	if (key == ESC)
	{
		// mlx_clear_window(data->mlx.mlx, data->mlx.win);
		// if (mlx_destroy_window(data->mlx.mlx, data->mlx.win))
		// 	ft_exit(data, "mlx does not destroy the window\n", 2);
		ft_exit(data, "", 0);
	}
	else if ((key >= 123 && key <= 126))
		return (0);
	return (0);
}

int	ft_exit_cross(int key, t_main *data)
{
	(void)key;
	exit(0);  //пацанский выход
	// mlx_destroy_image(data->mlx.img, data->mlx.addr);
	// mlx_clear_window(data->mlx->mlx, data->mlx->win);
	// if (mlx_destroy_window(data->mlx->mlx, data->mlx->win))
	// 	ft_program_completion(data, "mlx does not destroy the window", 1);
	ft_exit(data, "", 0);
	return (0);
}
