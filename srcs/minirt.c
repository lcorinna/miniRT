/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/28 17:45:20 by lcorinna         ###   ########.fr       */
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

// int	ft_red_cross(int key, t_main *data)
// {
// 	// mlx_destroy_window(data->mlx->mlx, data->mlx->win);
// 	mlx_clear_window(data->mlx->mlx, data->mlx->win);
// 	exit (0);
// }

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
	// else if (key >= 123 && key <= 126)
	// {
	// 	if (key == 126)
	// 		data->tmp.shift_y -= MOVE;
	// 	else if (key == 125)
	// 		data->tmp.shift_y += MOVE;
	// 	else if (key == 123)
	// 		data->tmp.shift_x -= MOVE;
	// 	else if (key == 124)
	// 		data->tmp.shift_x += MOVE;
	// 	mlx_clear_window(data->tmp.mlx, data->tmp.win);
	// 	ft_drawline(data);
	// }
	// else if (key >= 0 && key <= 273)
	// 	key++;
	// else
	// 	exit (0);
	return (0);
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

int	ft_parser(int argc, char **argv, t_main *data)
{
	argc = 0; //del
	argv = NULL; //del

	t_vec3		*sphere_center = ft_new_vec3(10, 10, -300);
	t_sphere	*sphere = ft_new_sphere(sphere_center, 100 / 2);
	t_vec3		*cam_origin = ft_new_vec3(0, 0, 0);
	t_vec3		*cam_direction = ft_new_vec3(0, 0, -1);
	t_camera	*cam = ft_new_camera(cam_origin, cam_direction, 70);
	data->scene = ft_new_scene(cam, sphere);
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
