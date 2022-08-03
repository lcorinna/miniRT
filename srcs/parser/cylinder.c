/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:11:48 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/03 23:07:52 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_shapes	ft_new_cylinder(t_vec3 *position, t_vec3 *direction, \
												float diameter, t_vec3 *color)
{
	t_shapes	new;

	new = (t_shapes){};
	new.type = CYLINDER;
	new.pos = *position;
	new.pos = *direction;
	new.clr = *color;
	new.diameter = diameter;
	new.rad = diameter / 2;
	// new.height = height;
	new.next = NULL;
	return (new);
}

void	ft_cylinder(t_main *data, char *str, int i)
{
	t_shapes	cylinder;
	t_vec3		or_dir[2];
	float		diameter;
	float		height;
	t_vec3		color;

	i = ft_search_next_value(str, i, 1); //пропускаю тип
	or_dir[0] = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	or_dir[1] = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	diameter = ft_found_diameter(str + i);
	i = ft_search_next_value(str, i, 2);
	height = ft_found_diameter(str + i);
	i = ft_search_next_value(str, i, 2);
	color = ft_pars_clr(data, str + i, color);
	if (or_dir[0].x == MAXFLOAT || diameter == MAXFLOAT || color.x == -1 || \
								height == MAXFLOAT || ft_check_dir(or_dir[1]))
	{
		ft_data_entry_error(str);
		return ;
	}
	cylinder = ft_new_cylinder(&or_dir[0], &or_dir[1], diameter, &color);
	cylinder.height = height;
	printf("origin - %f\n", or_dir[0].x); //del
	printf("direction - %f\n", or_dir[1].x); //del
	printf("diametr - %f\n", diameter); //del
	printf("height - %f\n", height); //del
	printf("color - %f\n", color.x); //del
	ft_shape_add_back(data->scene.sh, &cylinder);
	printf("CYLINDER DONE\n"); //del
}

	// printf("origin - %f\n", or_dir[0].x); //del
	// printf("direction - %f\n", or_dir[1].x); //del
	// printf("diametr - %f\n", diameter); //del
	// printf("height - %f\n", height); //del
	// printf("color - %f\n", color.x); //del
	// printf("CYLINDER DONE\n"); //del
