/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:41:57 by ayajirob          #+#    #+#             */
/*   Updated: 2022/08/09 21:11:04 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_shapes	*ft_new_plane(t_vec3 *position, t_vec3 *color, t_vec3 *direction, \
																t_main *data)
{
	t_shapes	*new;

	new = malloc(sizeof(t_shapes));
	if (new == NULL)
		return (NULL);
	*new = (t_shapes){};
	new->type = PLANE;
	new->pos = *position;
	new->clr = *color;
	new->direction = ft_norm(direction);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_plane(t_main *data, char *str)
{
	int			i;
	t_shapes	*plane;
	t_vec3		origin;
	t_vec3		direction;
	t_vec3		color;

	i = 0;
	i = ft_search_next_value(str, i, 1);
	origin = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	direction = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	color = ft_pars_clr(data, str + i, color);
	plane = ft_new_plane(&origin, &color, &direction, data);
	if (origin.x == MAXFLOAT || color.x == -1 || ft_check_dir(direction))
	{
		ft_data_entry_error(str, plane, 1);
		return ;
	}
	ft_shape_add_back(&data->scene.sh, plane);
}
