/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/06 23:23:00 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_initialization(t_main *data)
{
	data->mlx = (t_mlx){};
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		ft_exit(data, "mlx_init error\n", 2);
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, data->n_wndw);
	if (!data->mlx.win)
		ft_exit(data, "mlx_new_window error\n", 2);
	mlx_hook(data->mlx.win, 17, 1L << 0, ft_exit_cross, data);
	mlx_hook(data->mlx.win, 2, 1L << 0, ft_buttons, data);
}

int	main(int argc, char **argv)
{
	t_main	data;

	data = (t_main){};
	if (argc != 2)
		ft_exit(&data, "Check the number of arguments\n", 1);
	ft_parser(argc, argv, &data);
	ft_initialization(&data);
	ft_draw_loop(&data, &data.scene, &data.mlx);
	mlx_loop(&data.mlx.mlx);
	return (0);
}
