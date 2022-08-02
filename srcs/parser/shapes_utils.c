/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:41:57 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/02 23:50:40 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	ft_plane(t_main *data, char *str)
{
	int			i;
	t_shapes	plane;
	t_vec3		origin;
	t_vec3		direction;
	t_vec3		color;

	i = 0;
	i = ft_skip_type(str, i); //пропускаю тип
	origin = ft_point_in_space(data, str + i);
	i = ft_skip_visible_char_munis(str, i); //пропускаю тип
	i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	direction = ft_point_in_space(data, str + i);
	i = ft_skip_visible_char_munis(str, i); //пропускаю тип
	i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	color = ft_pars_clr(data, str + i, color);
	if (origin.x == MAXFLOAT || color.x == -1 || ft_chec_direction(direction))
	{
		ft_data_entry_error(str);
		return ;
	}
	plane = ft_new_plane(&origin, &color, &direction);
	ft_shape_add_back(&data->scene.sh, &plane);
	printf("PLANE DONE\n"); //del
}

int	ft_found_diametr_utils(char *str, char *diametr, int *i)
{
	int	j;

	j = 0;
	while (str[*i] != '\0' && str[*i] != '\n' && str[*i] != 32 && \
								str[*i] != '.' && (str[*i] < 8 || str[*i] > 14))
	{
		if (!ft_isdigit(str[*i]))
			return (1);
		diametr[j] = str[*i];
		(*i)++;
		j++;
		diametr[j] = '\0';
	}
	return (0);
}

float	ft_found_diametr(char *str)
{
	char	diametr[11];
	char	decimal[11];
	float	res;
	float	dec;
	int		i;

	i = 0;
	if (!ft_isdigit(str[i]))
		return (MAXFLOAT);
	if (ft_found_diametr_utils(str, diametr, &i))
		return (MAXFLOAT);
	res = (float)ft_atoi(diametr);
	if (str[i] == '.')
	{
		i++;
		if (ft_found_diametr_utils(str, decimal, &i))
			return (MAXFLOAT);
		dec = (float)ft_atoi(decimal);
		i = -1;
		dec /= 10;
		dec /= 10;
		// printf("dec - %f\n", dec); //del
		// printf("sts - %c\n", str[])
		while (str[++i] == '0')
		{
			dec /= 10;
			printf("dec - %f\n", dec); //del
		}
		res += dec;
	}
	return (res);
}

void	ft_sphere(t_main *data, char *str)
{
	int			i;
	t_shapes	sphere;
	t_vec3		center;
	t_vec3		color;
	float		diametr;

	i = 0;
	i = ft_skip_type(str, i); //пропускаю тип
	center = ft_point_in_space(data, str + i);
	i = ft_skip_visible_char_munis(str, i); //пропускаю тип
	i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	diametr = ft_found_diametr(str + i);
	printf("alan - %f\n", diametr); //del
	i = ft_skip_visible_char_munis(str, i); //пропускаю тип
	i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	color = ft_pars_clr(data, str + i, color);
	if (center.x == MAXFLOAT || diametr == MAXFLOAT || color.x == -1)
	{
		ft_data_entry_error(str);
		return ;
	}
	sphere = ft_new_sphere(&center, &color, diametr);
	ft_shape_add_back(&data->scene.sh, &sphere);
	printf("SPHERE DONE\n"); //del
}
