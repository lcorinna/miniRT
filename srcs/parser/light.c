/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:13:30 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/02 12:43:35 by lcorinna         ###   ########.fr       */
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
	i = ft_skip_type(str, i); //пропускаю тип
	position = ft_point_in_space(data, str + i);
	// printf("pos - %f\n", position.x); //del
	i = ft_skip_visible_char_munis(str, i); //пропускаю тип
	i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	bright = ft_ratio_ambiant(data, str + i, bright);
	// printf("br - %f\n", bright); //del
	i = ft_skip_visible_char(str, i); //пропускаю тип
	i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	color = ft_pars_clr(data, str + i, color);
	if (position.x == MAXFLOAT || bright == -1 || color.x == -1)
	{
		ft_data_entry_error(str);
		return ;
	}
	data->scene.lght = ft_new_light(&position, bright, &color);
	printf("LIGHT DONE\n"); //del
}
