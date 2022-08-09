/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:38:49 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 17:04:53 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *) dest = color;
}

void	ft_new_image(t_main *data, t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		ft_exit(data, "mlx_new_image error\n", 2);
	mlx->addr = mlx_get_data_addr(mlx->img, \
						&mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	if (mlx->addr == NULL)
		ft_exit(data, "mlx_get_data_addr error\n", 2);
}

t_vec3	ft_find_dir(float dst, int x, int y, t_vec3	cam_dir)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;
	t_vec3	dir;

	a = ft_new_vec3(dst, x - WIDTH / 2, -(y - HEIGHT / 2));
	b = ft_new_vec3(-(x - WIDTH / 2), dst, -(y - HEIGHT / 2));
	c = ft_new_vec3(-(y - HEIGHT / 2), x - WIDTH / 2, dst);
	a = ft_s_mul(&a, cam_dir.x);
	b = ft_s_mul(&b, cam_dir.y);
	c = ft_s_mul(&c, cam_dir.z);
	dir = ft_add3(&a, &b, &c);
	return (dir);
}

t_vec3	ft_rotate_dir(t_camera *cam, t_vec3 *dir)
{
	float	new_x;
	float	new_y;
	float	new_z;
	float	cut;

	cut = cam->angle_y;
	new_x = dir->x * cos(cut) - dir->z * sin(cut);
	new_z = dir->x * sin(cut) + dir->z * cos(cut);
	*dir = ft_new_vec3(new_x, dir->y, new_z);
	*dir = ft_norm(dir);
	cut = cam->angle_z;
	new_x = dir->x * cos(cut) - dir->y * sin(cut);
	new_y = dir->x * sin(cut) + dir->y * cos(cut);
	*dir = ft_new_vec3(new_x, new_y, dir->z);
	*dir = ft_norm(dir);
	return (*dir);
}

void	ft_draw_loop(t_main *data, t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;
	int		clr;
	t_vec3	direction;
	float	dst;

	y = -1;
	ft_new_image(data, mlx);
	dst = WIDTH / (2 * tanf(scene->cam.fov * M_PI / 360));
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			direction = ft_find_dir(dst, x, y, ft_norm(&scene->cam.direction));
			direction = ft_rotate_dir(&scene->cam, &direction);
			clr = ft_intersection(data, data->scene.sh, direction);
			ft_mlx_pixel_put(&data->mlx, x, y, clr);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	// mlx_destroy_image(mlx->img, mlx->addr);
}
