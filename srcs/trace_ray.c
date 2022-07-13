/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:37:16 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/13 12:58:43 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_mlx_pixel_put(t_main *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx->addr + (y * data->mlx->line_length + x * \
											(data->mlx->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	ft_ray_tracing(t_main *data, void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	float		x_angle;
	float		y_angle;
	int			color;
	t_vec3		ray;
	float		x_ray;
	float		y_ray;

	mlx_y = 0;
	y_angle = (scene->height / 2);
	data->mlx->img = mlx_new_image(data->mlx->mlx, WIDTH, HEIGHT);
	if (data->mlx->img == NULL)
		return ; //обработать
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, \
	&data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	if (data->mlx->addr == NULL)
		return ; //обработать
	while (y_angle >= (scene->height / 2) * (-1))
	{
		y_ray = y_angle * data->vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * data->vplane->x_pixel;
			ray = ft_new_vec3(x_ray, y_ray, -1);
			ft_norm(&ray);
			color = ft_pxl_color(data, data->scene, &data->scene->sh, &ray);
			// printf("color - %d\n", color); //del
			ft_mlx_pixel_put(data, mlx_x, mlx_y, color);
			++x_angle;
			++mlx_x;
		}
		--y_angle;
		++mlx_y;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
	// printf("\ndata->mlx->img - %p\n", data->mlx->img); //del
	// printf("data->mlx->addr - %p\n", data->mlx->addr); //del
	mlx_destroy_image(data->mlx->img, data->mlx->addr);
	free(data->mlx->img); //??
}

// color(vec3 color)
// {
// 	int res;
// 	int red;
// 	int green;
// 	int blue;

// 	red = (int)randf(color.x);
// 	if (red > 255)
// 		red = 255;
// 	else if (red < 0)
// 		red = 0;
// 	res = (red << 16) | (green << 8) | (blue);
// 	return (res);
// }
