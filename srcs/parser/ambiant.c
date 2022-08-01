/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:03 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/01 21:32:49 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_ambient	ft_new_amb(float bright, t_vec3 *clr)
{
	t_ambient	new;

	new.bright = bright;
	new.clr = *clr;
	return (new);
}

float	ft_ratio_ambiant(t_main *data, char *str, float bright)
{
	char	number[2];
	float	decimal;

	if (str[1] != '.' || (str[3] != 32) || (str[3] > 8 && str[3] < 14))
		return (-1);
	number[0] = str[0];
	number[1] = '\0';
	bright = (float)ft_atoi(number);
	number[0] = str[2];
	number[1] = '\0';
	decimal = (float)ft_atoi(number);
	decimal /= 10;
	bright += decimal;
	if (bright < (0.0) || bright > (2.0))
		return (-1);
	return (bright);
}

void	ft_ambiant(t_main *data, char *type, char *str)
{
	int		i;
	float	bright;
	t_vec3	clr;

	i = 0;
	bright = 0;
	i = ft_skip_type(str, i); //пропускаю тип
	bright = ft_ratio_ambiant(data, str + i, bright);
	// printf("bright - %f\n", bright); //del
	i = ft_skip_visible_char(str, i); //пропускаю тип
	i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	clr = ft_pars_clr(data, str + i, clr);
	if (bright == -1 || clr.x == -1)
	{
		ft_data_entry_error(str);
		return ;
	}
	data->scene.amb = ft_new_amb(bright, &clr);
	printf("AMBIANT DONE\n"); //del
}
