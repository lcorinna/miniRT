/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:29:57 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/03 23:07:46 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_shapes	ft_new_sphere(t_vec3 *center, t_vec3 *color, float diameter)
{
	t_shapes	new;

	new = (t_shapes){};
	new.type = SPHERE;
	new.pos = *center;
	new.clr = *color;
	new.diameter = diameter;
	new.rad = diameter / 2;
	new.next = NULL;
	return (new);
}

int	ft_found_diameter_utils(char *str, char *diametr, int *i)
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

float	ft_found_diameter(char *str)
{
	char	diametr[11];
	char	decimal[11];
	float	res[2];
	int		i;
	int		j;

	i = 0;
	if (!ft_isdigit(str[i]))
		return (MAXFLOAT);
	if (ft_found_diameter_utils(str, diametr, &i))
		return (MAXFLOAT);
	res[0] = (float)ft_atoi(diametr);
	if (str[i] == '.')
	{
		i++;
		j = i - 1;
		if (ft_found_diameter_utils(str, decimal, &i))
			return (MAXFLOAT);
		res[1] = (float)ft_atoi(decimal);
		while (str[++j] == '0')
			res[1] /= 10;
		res[1] /= 100;
		res[0] += res[1];
	}
	return (res[0]);
}

void	ft_sphere(t_main *data, char *str)
{
	int			i;
	t_shapes	sphere;
	t_vec3		center;
	t_vec3		color;
	float		diameter;

	i = 0;
	i = ft_search_next_value(str, i, 1); //пропускаю тип
	center = ft_point_in_space(data, str + i);
	i = ft_search_next_value(str, i, 2);
	diameter = ft_found_diameter(str + i);
	// printf("alan - %f\n", diameter); //del
	i = ft_search_next_value(str, i, 2);
	color = ft_pars_clr(data, str + i, color);
	if (center.x == MAXFLOAT || diameter == MAXFLOAT || color.x == -1)
	{
		ft_data_entry_error(str);
		return ;
	}
	sphere = ft_new_sphere(&center, &color, diameter);
	ft_shape_add_back(data->scene.sh, &sphere);
	printf("SPHERE DONE\n"); //del
	printf("qwer one  - %d\n", data->scene.sh->type); //del
	printf("qwer one - %f\n", data->scene.sh->pos.x); //del
	printf("qwer one  - %p\n", data->scene.sh); //del
	printf("qwer two  - %d\n", data->scene.sh->next->type); //del
	printf("qwer two  - %f\n", data->scene.sh->next->pos.x); //del
	printf("qwer two  - %p\n", data->scene.sh->next); //del
}
