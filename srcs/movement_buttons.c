/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_buttons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:10:53 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 16:24:30 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_move_light(int key, t_main *data)
{
	if (key == ESC || key >= 123 && key <= 126 || key >= 0 && key <= 3 \
	|| key == 13 || key == 12 || key == 14)
		ft_general_scene(key, data);
	if (key == SH_LEFT)
		data->scene.lght.pos.y -= MOVE;
	else if (key == SH_RIGHT)
		data->scene.lght.pos.y += MOVE;
	else if (key == SH_UP)
		data->scene.lght.pos.z += MOVE;
	else if (key == SH_DOWN)
		data->scene.lght.pos.z -= MOVE;
	else if (key == SH_MINUS)
		data->scene.lght.pos.x += MOVE;
	else if (key == SH_PLUS)
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
	if (key == 83 && (sh->type == PLANE || sh->type == CYLINDER))
	{
		sh->direction = ft_rotate_shape(sh->direction, ROTATE);
	}
	else if (key == 85 && (sh->type == PLANE || sh->type == CYLINDER))
		sh->direction = ft_rotate_shape(sh->direction, (-ROTATE));
	else if (key == MINUS && sh->rad > 10 && \
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
	if (key == ESC || key >= 123 && key <= 126 || key >= 0 && key <= 3 \
	|| key == 13 || key == 12 || key == 14)
		ft_general_scene(key, sh->data);
	if (key == 69 || key == 78 || key == 83 || key == 85)
		ft_move_shape_two(key, sh);
	else if (key == SH_LEFT)
		sh->pos.y -= MOVE;
	else if (key == SH_RIGHT)
		sh->pos.y += MOVE;
	else if (key == SH_UP)
		sh->pos.z += MOVE;
	else if (key == SH_DOWN)
		sh->pos.z -= MOVE;
	else if (key == SH_MINUS)
		sh->pos.x += MOVE;
	else if (key == SH_PLUS)
		sh->pos.x -= MOVE;
	mlx_clear_window(sh->data->mlx.mlx, sh->data->mlx.win);
	ft_draw_loop(sh->data, &(sh->data->scene), &(sh->data->mlx));
	return (0);
}
