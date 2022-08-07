/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:02:34 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/07 20:23:56 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_shapes	*ft_figure_search(t_main *data, t_shapes *sh, t_vec3 direction)
{
	float		dist;
	float		dist_min;
	t_shapes	*tmp;
	t_shapes	*res;

	res = NULL;
	dist_min = MAXFLOAT;
	tmp = sh;
	while (tmp)
	{
		dist = ft_find_dist(tmp, &data->scene.cam.origin, &direction);
		if (dist > 0 && dist < dist_min)
		{
			dist_min = dist;
			res = tmp;
		}
		tmp = tmp->next;
	}
	return (res);
}

void	ft_left_button(t_main *data, int x, int y)
{
	t_vec3		direction;
	float		dst;
	t_shapes	*shape;

	dst = WIDTH / (2 * tanf(data->scene.cam.fov * M_PI / 360));
	direction = ft_find_dir(dst, x, y, ft_norm(&(data->scene.cam.direction)));
	direction = ft_rotate_dir(&(data->scene.cam), &direction);
	shape = ft_figure_search(data, data->scene.sh, direction);
	if (shape != NULL)
	{
		// printf("type - %d\n", shape->type); //del
		mlx_hook(data->mlx.win, 2, 1L << 0, ft_move_shape, shape);
	}
	else if (shape == NULL)
		mlx_hook(data->mlx.win, 2, 1L << 0, ft_move_light, data);
}

int	ft_mouse(int button, int x, int y, void *data1)
{
	t_main	*data;

	data = (t_main *)data1;
	if (button == LMB)
		ft_left_button(data, x, y);
	return (0);
}
