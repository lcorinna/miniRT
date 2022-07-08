/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:38:49 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/07 15:00:06 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_initialization(t_main *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		return (1); //обработать выход
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		return (1); //обработать выход
	data->mlx->win = mlx_new_window(data->mlx->mlx, WIDTH, HEIGHT, "miniRT");
	if (!data->mlx->win)
		return (1); //обработать выход
	return (0);
}

int	ft_draw(t_main *data, t_scene *scene)
{
	ft_ray_tracing(data, data->mlx->mlx, data->mlx->win, scene);
	mlx_hook(data->mlx->win, 2, (1L << 0), ft_buttons, data);
	// mlx_hook(data->mlx->win, 17, (1L << 0), ft_red_cross, data);
	mlx_loop(data->mlx->mlx);
	return (0);
}
