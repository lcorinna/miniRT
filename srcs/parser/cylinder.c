/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:11:48 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 19:12:16 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	ft_new_cylinder_utils(t_shapes *cylinder, float height, t_main *data)
{
	cylinder->height = height;
	cylinder->data = data;
}

t_shapes	*ft_new_cylinder(t_vec3 *position, t_vec3 *direction, \
												float diameter, t_vec3 *color)
{
	t_shapes	*new;

	new = malloc(sizeof(t_shapes));
	if (new == NULL)
		return (NULL);
	*new = (t_shapes){};
	new->type = CYLINDER;
	new->pos = *position;
	new->direction = ft_norm(direction);
	new->clr = *color;
	new->diameter = diameter;
	new->rad = diameter / 2;
	new->next = NULL;
	return (new);
}

void	ft_cylinder(t_main *data, char *str, int i)
{
	t_shapes	*cylinder;
	t_vec3		or_dir[2];
	float		diameter;
	float		height;
	t_vec3		color;

	i = ft_search_next_value(str, i, 1);
	or_dir[0] = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	or_dir[1] = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	diameter = ft_found_diameter(str + i);
	i = ft_search_next_value(str, i, 2);
	height = ft_found_diameter(str + i);
	i = ft_search_next_value(str, i, 2);
	color = ft_pars_clr(data, str + i, color);
	cylinder = ft_new_cylinder(&or_dir[0], &or_dir[1], diameter, &color);
	if (or_dir[0].x == MAXFLOAT || diameter == MAXFLOAT || color.x == -1 || \
			height == MAXFLOAT || ft_check_dir(or_dir[1]) || cylinder == NULL)
	{
		ft_data_entry_error(str, cylinder, 1);
		return ;
	}
	ft_new_cylinder_utils(cylinder, height, data);
	ft_shape_add_back(&data->scene.sh, cylinder);
}
