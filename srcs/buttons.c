/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:10:53 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/30 19:48:45 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// int	ft_red_cross(int key, t_main *data)
// {
// 	// mlx_destroy_window(data->mlx->mlx, data->mlx->win);
// 	mlx_clear_window(data->mlx->mlx, data->mlx->win);
// 	exit (0);
// }

void	ft_camera_movement(int key, t_main *data)
{
	t_vec3	*tmp;

	free(data->scene->cams->origin);
	if (key == 123)
		tmp = ft_new_vec3(2, 0, 0);
	else if (key == 124)
		tmp = ft_new_vec3(-2, 0, 0);
	else if (key == 126)
		tmp = ft_new_vec3(0, -2, 0);
	else if (key == 125)
		tmp = ft_new_vec3(0, 2, 0);
	if (!tmp)
		return ; //обработать выход
	data->scene->cams->origin = ft_add(data->scene->cams->origin, tmp);
	free(tmp);
	if (!data->scene->cams->origin)
		return ; //обработать выход
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	ray_tracing(data->mlx->mlx, data->mlx->win, data->scene);
}

int	ft_buttons(int key, t_main *data)
{
	int	i;

	printf("key - %d\n", key); //del
	// 	mlx_clear_window(data->tmp.mlx, data->tmp.win);
	// 	ft_drawline(data);
	if (key == 53)
	{
		if (mlx_destroy_window(data->mlx->mlx, data->mlx->win))
			ft_program_completion(data, "mlx does not destroy the window", 1);
		ft_program_completion(data, "", 0);
	}
	else if ((key >= 123 && key <= 126))
		ft_camera_movement(key, data); //скорее всего не правильно
	// else if (key >= 0 && key <= 273)
	// 	key++;
	// else
	// 	exit (0);
	return (0);
}
