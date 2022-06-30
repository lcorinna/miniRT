/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/30 19:53:51 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_program_completion(t_main *data, char *error, int flag)
{
	// ft_clear_arr_struct(data, 0); чистим всю память
	data = NULL; //заглушка
	if (flag)
		perror(error);
	exit (flag);
}

int	ft_draw(t_main *data, t_scene *scene)
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
	ray_tracing(data->mlx->mlx, data->mlx->win, scene);
	mlx_hook(data->mlx->win, 2, (1L << 0), ft_buttons, data);
	// mlx_hook(data->mlx->win, 17, (1L << 0), ft_red_cross, data);
	mlx_loop(data->mlx->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	data;

	data = (t_main){};
	ft_parser(argc, argv, &data);
	ft_draw(&data, data.scene);
	return (0);
}
