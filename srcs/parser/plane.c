/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:41:57 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/04 20:42:24 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_shapes	*ft_new_plane(t_vec3 *position, t_vec3 *color, t_vec3 *direction)
{
	t_shapes	*new;

	new = malloc(sizeof(t_shapes));
	if (new == NULL)
		return (NULL);
	*new = (t_shapes){};
	new->type = PLANE;
	new->pos = *position;
	new->clr = *color;
	new->direction = *direction;
	new->next = NULL;
	return (new);
}

// t_shapes	*ft_new_plane(t_vec3 *position, t_vec3 *color, t_vec3 *direction)
// {
// 	t_shapes	*new;

// 	new = malloc(sizeof(t_shapes));
// 	if (!new)
// 		return (NULL);
// 	new->type = PLANE;
// 	new->pos = *position;
// 	new->clr = *color;
// 	new->direction = *direction;
// 	new->next = NULL;
// 	return (new);
// }

void	ft_plane(t_main *data, char *str)
{
	int			i;
	t_shapes	*plane;
	t_vec3		origin;
	t_vec3		direction;
	t_vec3		color;

	i = 0;
	i = ft_search_next_value(str, i, 1); //пропускаю тип
	origin = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	direction = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	color = ft_pars_clr(data, str + i, color);
	plane = ft_new_plane(&origin, &color, &direction);
	if (origin.x == MAXFLOAT || color.x == -1 || ft_check_dir(direction))
	{
		ft_data_entry_error(str, plane);
		return ;
	}
	// printf("sh - 		%p\n", data->scene.sh); //del
	// printf("plane - 	%p\n", &plane); //del
	ft_shape_add_back(&data->scene.sh, plane);
	printf("PLANE DONE\n"); //del
}
