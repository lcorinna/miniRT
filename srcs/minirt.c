/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/06 20:05:20 by lcorinna         ###   ########.fr       */
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

// void	ft_calibration(t_vec3 *a, t_vec3 *b)
// {
// }

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
	// printf("HERE			HERE\n"); //del
	ft_ray_tracing(data, data->mlx->mlx, data->mlx->win, scene);
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
	// printf("HERE\n"); //del
	// ft_calibration(&data);
	if (ft_initialization(&data))
		ft_program_completion(&data, "", 1);
	ft_draw(&data, data.scene);
	return (0);
}
