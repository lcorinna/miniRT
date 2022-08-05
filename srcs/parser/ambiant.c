/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:03 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/05 19:00:09 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	ft_check_repetitions(t_main *data, char *str, char *type)
{
	if (ft_strncmp("A", type, 2) == 0 && data->scene.amb.flag != 0 || \
		ft_strncmp("C", type, 2) == 0 && data->scene.cam.flag != 0 || \
		ft_strncmp("L", type, 2) == 0 && data->scene.lght.flag != 0)
	{
		// printf("address - %p\n", data->scene.amb); //del
		// printf("color - %f\n", data->scene.amb.clr.x); //del
		// printf("color - %f\n", data->scene.amb.clr.y); //del
		// printf("color - %f\n", data->scene.amb.clr.z); //del
		// printf("color - %f\n", data->scene.amb.bright); //del
		ft_putstr_fd("The value of type \"", 2);
		ft_putstr_fd(type, 2);
		ft_putstr_fd("\" already exists.", 2);
		ft_exit(data, "Check the scene map and try again.\n", 1);
	}
}

t_ambient	ft_new_amb(float bright, t_vec3 *clr)
{
	t_ambient	new;

	new = (t_ambient){};
	new.bright = bright;
	new.clr = *clr;
	new.flag = 1;
	return (new);
}

float	ft_ratio_ambiant(t_main *data, char *str, float bright)
{
	char	number[2];
	float	decimal;

	if (str[1] != '.' || str[3] != 32 && (str[3] < 8 || str[3] > 14))
		return (-1);
	number[0] = str[0];
	number[1] = '\0';
	bright = (float)ft_atoi(number);
	number[0] = str[2];
	number[1] = '\0';
	decimal = (float)ft_atoi(number);
	decimal /= 10;
	bright += decimal;
	if (bright < (0.0) || bright > (1.0))
		return (-1);
	return (bright);
}

void	ft_ambiant(t_main *data, char *type, char *str)
{
	int		i;
	float	bright;
	t_vec3	color;

	i = 0;
	bright = 0;
	i = ft_search_next_value(str, i, 1); //пропускаю тип
	bright = ft_ratio_ambiant(data, str + i, bright);
	// printf("bright - %f\n", bright); //del
	i = ft_search_next_value(str, i, 2);
	color = ft_pars_clr(data, str + i, color);
	if (bright == -1 || color.x == -1)
	{
		ft_data_entry_error(str, NULL);
		return ;
	}
	data->scene.amb = ft_new_amb(bright, &color);
	printf("AMBIANT DONE\n"); //del
}
