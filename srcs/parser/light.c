/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:13:30 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/04 20:41:56 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_light	ft_new_light(t_vec3 *position, float bright, t_vec3 *color)
{
	t_light	new;

	new.pos = *position;
	new.bright = bright;
	new.clr = *color;
	return (new);
}

void	ft_light(t_main *data, char *str)
{
	int		i;
	t_vec3	position;
	float	bright;
	t_vec3	color;

	i = 0;
	i = ft_search_next_value(str, i, 1); //пропускаю тип
	position = ft_point_in_space(data, str + i);
	// printf("pos - %f\n", position.x); //del
	i = ft_search_next_value(str, i, 2);
	bright = ft_ratio_ambiant(data, str + i, bright);
	// printf("br - %f\n", bright); //del
	i = ft_search_next_value(str, i, 2);
	color = ft_pars_clr(data, str + i, color);
	if (position.x == MAXFLOAT || bright == -1 || color.x == -1)
	{
		ft_data_entry_error(str, NULL);
		return ;
	}
	data->scene.lght = ft_new_light(&position, bright, &color);
	printf("LIGHT DONE\n"); //del
}
