/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:13:30 by ayajirob          #+#    #+#             */
/*   Updated: 2022/08/09 21:10:52 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_light	ft_new_light(t_vec3 *position, float bright, t_vec3 *color)
{
	t_light	new;

	new = (t_light){};
	new.pos = *position;
	new.bright = bright;
	new.clr = *color;
	new.flag = 1;
	return (new);
}

void	ft_light(t_main *data, char *str)
{
	int		i;
	t_vec3	position;
	float	bright;
	t_vec3	color;

	i = 0;
	i = ft_search_next_value(str, i, 1);
	position = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	bright = ft_ratio_ambiant(data, str + i, bright);
	i = ft_search_next_value(str, i, 2);
	color = ft_pars_clr(data, str + i, color);
	if (position.x == MAXFLOAT || bright == -1 || color.x == -1)
	{
		ft_data_entry_error(str, NULL, 0);
		return ;
	}
	data->scene.lght = ft_new_light(&position, bright, &color);
}
