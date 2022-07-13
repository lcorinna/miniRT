/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_completion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:20:48 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/13 13:28:00 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_clear_scene(t_scene *scene)
{
	// if (scene->amb)
	// 	free(scene->amb);
	if (scene->cam)
		free(scene->cam);
	// if (scene->lght)
	// 	free(scene->lght)
	if (scene->sh.sp)
		free(scene->sh.sp);
	// if (scene->sh.cy)
	// 	free(scene->sh.cy);
	// if (scene->sh.pl)
	// 	free(scene->sh.pl);
	if (scene)
		free(scene);
}

void	ft_clear_arr_struct(t_main *data, int flag)
{
	if (data->scene)
		ft_clear_scene(data->scene);
	if (data->mlx)
		free(data->mlx);
	if (data->vplane)
		free(data->vplane);
}

void	ft_program_completion(t_main *data, char *error, int flag)
{
	// ft_clear_arr_struct(data, 0);
	if (flag)
		perror(error);
	if (flag > 0)
		flag = 1;
	exit (flag);
}
