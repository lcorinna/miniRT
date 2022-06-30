/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:37:16 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/30 18:06:45 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	float		x_angle;
	float		y_angle;
	int			color;
	t_vec3		*ray;
	t_vplane	*vplane;
	float		x_ray;
	float		y_ray;

	vplane =  ft_get_view_plane(scene->width, scene->height, scene->cams->fov);
	mlx_y = 0;
	y_angle	= (scene->height / 2);
	while (y_angle >= (scene->height / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel; //0.25
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel; //-0.5
			ray = ft_new_vec3(x_ray, y_ray, -1);
			ft_norm(ray);
			if (ft_sphere_intersect(scene->cams, ray, scene->sphere))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			// printf("mlx_x = %d,	mlx_y = %d\n", mlx_x, mlx_y); //del
			// printf("ray - %p\n", ray); //del
			free(ray);
			// printf("ray - %p\n", ray); //del
			// sleep(5); //del
			++x_angle;
			++mlx_x;
		}
		--y_angle;
		++mlx_y;
	}
	free(vplane);
}

t_vplane	*ft_get_view_plane(float width, float height, float fov) //fov
{
	t_vplane	*vplane;
	float		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		return (NULL); //обработать
	aspect_ratio = width / height; //1.8 //соотношение сторон
	vplane->width = 1;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width; //0.0005208333333
	vplane->y_pixel = vplane->height / height; //0.000462962963
	return (vplane);
}
