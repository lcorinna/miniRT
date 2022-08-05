/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:19:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/05 15:03:10 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_camera	ft_new_camera(t_vec3 *origin, t_vec3 *direction, float fov)
{
	t_camera	new;

	new = (t_camera){};
	new.origin = *origin;
	new.direction = *direction;
	new.fov = fov;
	new.angle_y = 0;
	new.angle_z = 0;
	new.flag = 1;
	return (new);
}

float	ft_fov_cam(char	*str)
{
	int		i;
	char	fov[5];
	float	res;
	int		j;

	i = 0;
	j = 0;
	if (!ft_isdigit(str[i]))
		return (MAXFLOAT);
	while (str[i] != '\0' && str[i] != '\n' && str[i] != 32 && \
		(str[i] < 8 || str[i] > 14))
	{
		if (!ft_isdigit(str[i]))
			return (MAXFLOAT);
		fov[j] = str[i];
		j++;
		i++;
	}
	fov[j] = '\0';
	res = (float)ft_atoi(fov);
	if (res < 0 || res > 180)
		return (MAXFLOAT);
	return (res);
}

void	ft_camera(t_main *data, char *type, char *str)
{
	int		i;
	t_vec3	origin;
	t_vec3	direction;
	float	fov;

	i = 0;
	i = ft_search_next_value(str, i, 1); //пропускаю тип
	origin = ft_point_in_space(data, str + i);
	// printf("camera x - %f y - %f z - %f\n", origin.x, origin.y, origin.z); //del
	i = ft_search_next_value(str, i, 2);
	direction = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	fov = ft_fov_cam(str + i);
	if (origin.x == MAXFLOAT || fov == MAXFLOAT || ft_check_dir(direction))
	{
		ft_data_entry_error(str, NULL);
		return ;
	}
	data->scene.cam = ft_new_camera(&origin, &direction, fov);
	printf("CAMERA DONE\n"); //del
}
