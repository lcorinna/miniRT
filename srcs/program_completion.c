/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_completion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:20:48 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/20 20:05:23 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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

int	ft_exit(char *str)
{
	ft_putstr_fd(str);
	exit(0);
}
