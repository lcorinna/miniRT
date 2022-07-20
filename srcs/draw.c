/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:38:49 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/20 19:54:57 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vplane	*ft_get_view_plane(float width, float height, float fov)
{
	t_vplane	*new;
	float		aspect_ratio;

	new = malloc(sizeof(t_vplane));
	if (!new)
		return (NULL); //обработать
	aspect_ratio = width / height; //соотношение сторон
	new->width = (tan(fov / 2 * (M_PI / 180))) * 2;
	new->height = new->width / aspect_ratio;
	new->p_x = new->width / width;
	new->p_y = new->height / height;
	return (new);
}

int	ft_initialization(t_main *data, t_scene *scene)
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
	data->vplane =  ft_get_view_plane(scene->width, scene->height, scene->cam->fov);
	if (!data->vplane)1
		return (1); //обработать выход
	mlx_hook(data->mlx->win, 2, 1L << 0, ft_buttons, data);
	mlx_hook(data->mlx->win, 17, 0, ft_exit_cross, data);
	// mlx_hook(mlx->win_ptr, 02, 1L << 0, esc_key, (void *)mlx);
	return (0);
}

int	ft_draw(t_main *data, t_scene *scene)
{
	ft_ray_tracing(data, data->mlx->mlx, data->mlx->win, scene);
	return (0);
}
