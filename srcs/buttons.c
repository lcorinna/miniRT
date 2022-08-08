/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:10:53 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/08 18:26:39 by lcorinna         ###   ########.fr       */
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
	else if (key == 14 && data->scene.cam.fov > 10)
		data->scene.cam.fov -= FOV;
}

void	ft_general_scene(int key, t_main *data)
{
	if (key == ESC)
	{
		// mlx_clear_window(data->mlx.mlx, data->mlx.win);
		// if (mlx_destroy_window(data->mlx.mlx, data->mlx.win))
		// 	ft_exit(data, "mlx does not destroy the window\n", 2);
		ft_exit(data, "", 0);
	}
	else if (key >= 123 && key <= 126) //переделать
		ft_move_cam(key, data);
	else if (key >= 0 && key <= 3 || key == 13)
		ft_rotate_cam(key, data);
	else if (key == 12 || key == 14)
		ft_change_fov(key, data);
}

int	ft_move_light(int key, t_main *data)
{
	printf("light key - %d\n", key); //del
	if (key == ESC || key >= 123 && key <= 126 || key >= 0 && key <= 3 \
	|| key == 13 || key == 12 || key == 14)
		ft_general_scene(key, data);
	if (key == 86)
		data->scene.lght.pos.y -= MOVE;
	else if (key == 88)
		data->scene.lght.pos.y += MOVE;
	else if (key == 91)
		data->scene.lght.pos.z += MOVE;
	else if (key == 84)
		data->scene.lght.pos.z -= MOVE;
	else if (key == 89)
		data->scene.lght.pos.x += MOVE;
	else if (key == 92)
		data->scene.lght.pos.x -= MOVE;
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	ft_draw_loop(data, &(data->scene), &(data->mlx));
	return (0);
}

t_vec3	ft_rotate_shape(t_vec3 direction, float alpha)
{
	float	new_y;
	float	new_z;

	new_y = direction.y * cos(alpha) + direction.z * sin(alpha);
	new_z = -direction.y * sin(alpha) + direction.z * cos(alpha);
	direction = ft_new_vec3(direction.x, new_y, new_z);
	direction = ft_norm(&direction);
	return (direction);
}

void	ft_move_shape_two(int key, t_shapes *sh)
{
	printf("key inside - %d\n", key); //del
	if (key == 83 && (sh->type == PLANE || sh->type == CYLINDER))
	{
		sh->direction = ft_rotate_shape(sh->direction, ROTATE);
	}
	else if (key == 85 && (sh->type == PLANE || sh->type == CYLINDER))
		sh->direction = ft_rotate_shape(sh->direction, (-ROTATE));
	else if (key == MINUS && sh->diameter > 10 && \
								(sh->type == SPHERE || sh->type == CYLINDER))
	{
		if (sh->type == CYLINDER && sh->height > 10)
			sh->height -= 10;
		sh->rad -= 10;
	}
	else if (key == PLUS && sh->type == SPHERE || sh->type == CYLINDER)
	{
		sh->height += 10;
		sh->rad += 10;
	}
}

int	ft_move_shape(int key, t_shapes *sh)
{
	printf("shape key - %d\n", key); //del
	if (key == ESC || key >= 123 && key <= 126 || key >= 0 && key <= 3 \
	|| key == 13 || key == 12 || key == 14)
		ft_general_scene(key, sh->data);
	if (key == 69 || key == 78 || key == 83 || key == 85)
		ft_move_shape_two(key, sh);
	else if (key == 86)
		sh->pos.y -= MOVE;
	else if (key == 88)
		sh->pos.y += MOVE;
	else if (key == 91)
		sh->pos.z += MOVE;
	else if (key == 84)
		sh->pos.z -= MOVE;
	else if (key == 89)
		sh->pos.x += MOVE;
	else if (key == 92)
		sh->pos.x -= MOVE;
	mlx_clear_window(sh->data->mlx.mlx, sh->data->mlx.win);
	ft_draw_loop(sh->data, &(sh->data->scene), &(sh->data->mlx));
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
