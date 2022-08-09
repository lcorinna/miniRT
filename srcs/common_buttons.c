/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_buttons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:09:01 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 18:42:08 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_move_cam(int key, t_main *data)
{
	t_vec3	tmp;

	if (key == LEFT)
		data->scene.cam.origin.y -= MOVE;
	else if (key == RIGHT)
		data->scene.cam.origin.y += MOVE;
	else if (key == UP)
		data->scene.cam.origin.z += MOVE;
	else if (key == DOWN)
		data->scene.cam.origin.z -= MOVE;
}

void	ft_rotate_cam(int key, t_main *data)
{
	if (key == R_UP)
		data->scene.cam.angle_y += ROTATE;
	else if (key == R_DOWN)
		data->scene.cam.angle_y -= ROTATE;
	else if (key == R_LEFT)
		data->scene.cam.angle_z -= ROTATE;
	else if (key == R_RIGHT)
		data->scene.cam.angle_z += ROTATE;
}

void	ft_change_fov(int key, t_main *data)
{
	if (key == 12 && data->scene.cam.fov < 180)
		data->scene.cam.fov += FOV;
	else if (key == 14 && data->scene.cam.fov > 11)
		data->scene.cam.fov -= FOV;
}

void	ft_general_scene(int key, t_main *data)
{
	if (key == ESC)
	{
		mlx_clear_window(data->mlx.mlx, data->mlx.win);
		if (mlx_destroy_window(data->mlx.mlx, data->mlx.win))
			ft_exit(data, "mlx does not destroy the window\n", 2);
		ft_exit(data, "", 0);
	}
	else if (key >= 123 && key <= 126)
		ft_move_cam(key, data);
	else if (key >= 0 && key <= 3 || key == 13)
		ft_rotate_cam(key, data);
	else if (key == 12 || key == 14)
		ft_change_fov(key, data);
}

int	ft_exit_cross(int key, t_main *data)
{
	(void)key;
	exit(0);
	// mlx_clear_window(data->mlx.mlx, data->mlx.win);
	// if (mlx_destroy_window(data->mlx.mlx, data->mlx.win))
	// 	ft_exit(data, "", 0);
	// ft_exit(data, "", 0);
	return (0);
}
