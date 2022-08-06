/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:53:30 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/06 22:41:35 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

float	ft_pars_one_clr(char *str, int	*i)
{
	char	color[4];
	float	part;
	int		j;

	j = 0;
	if (!ft_isdigit(str[*i]))
		return (MAXFLOAT);
	while (str[*i] != '\0' && str[*i] != '\n' && str[*i] != ',' && \
		str[*i] != 32 && (str[*i] < 8 || str[*i] > 14))
	{
		if (!ft_isdigit(str[*i]))
			return (MAXFLOAT);
		color[j] = '\0';
		color[j] = str[*i];
		(*i)++;
		j++;
	}
	(*i)++;
	color[j] = '\0';
	part = (float)ft_atoi(color);
	part = roundf(part);
	return (part);
}

t_vec3	ft_pars_clr(t_main *data, char *str, t_vec3	clr)
{
	int		i;
	float	r;
	float	g;
	float	b;

	i = 0;
	r = ft_pars_one_clr(str, &i);
	if (r == 0)
		r = 15;
	g = ft_pars_one_clr(str, &i);
	if (g == 0)
		g = 15;
	b = ft_pars_one_clr(str, &i);
	if (b == 0)
		b = 15;
	i--;
	if (r < 0.0 || r > 255.0 || g < 0.0 || g > 255.0 || b < 0.0 || b > 255.0 \
															|| str[i] == ',')
	{
		clr = ft_new_vec3(-1, -1, -1);
		return (clr);
	}	
	clr = ft_new_vec3(r, g, b);
	return (clr);
}
