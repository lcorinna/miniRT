/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:54:32 by ayajirob          #+#    #+#             */
/*   Updated: 2022/08/09 21:10:57 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	ft_pre_assembly_utils(char *str, char *diametr, int *i)
{
	int	j;

	j = 0;
	if (!ft_isdigit(str[*i]))
		return (1);
	while (str[*i] != '\0' && str[*i] != '\n' && str[*i] != 32 && j < 10 && \
			str[*i] != '.' && str[*i] != ',' && (str[*i] < 8 || str[*i] > 14))
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

float	ft_pre_assembly_support(char *str, char *decimal, int *i, int j)
{
	float	dec;

	dec = 1;
	(*i)++;
	if (ft_pre_assembly_utils(str, decimal, i))
		return (MAXFLOAT);
	dec = (float)ft_atoi(decimal);
	while (str[++j] == '0')
		dec /= 10;
	dec /= 10;
	return (dec);
}

float	ft_pre_assembly(char *str, int *i, float *res)
{
	char	number[11];
	char	decimal[11];
	float	dec;

	dec = 1;
	if (str[*i] == '-')
	{
		*res = -1;
		dec = -1;
		(*i)++;
	}
	if (ft_pre_assembly_utils(str, number, i))
		return (MAXFLOAT);
	*res *= (float)ft_atoi(number);
	if (str[*i] == '.')
	{
		dec *= ft_pre_assembly_support(str, decimal, i, *i);
		if (dec == MAXFLOAT)
			return (MAXFLOAT);
		*res += dec;
	}
	if (str[*i] == ',')
		(*i)++;
	return (*res);
}

t_vec3	ft_point_in_space(t_main *data, char *str)
{
	t_vec3	origin;
	float	x;
	float	y;
	float	z;
	int		i;

	i = 0;
	x = 1;
	y = 1;
	z = 1;
	x = ft_pre_assembly(str, &i, &x);
	y = ft_pre_assembly(str, &i, &y);
	z = ft_pre_assembly(str, &i, &z);
	i--;
	if (x == MAXFLOAT || y == MAXFLOAT || z == MAXFLOAT || (str[i]) == ',')
	{
		origin = ft_new_vec3(MAXFLOAT, MAXFLOAT, MAXFLOAT);
		return (origin);
	}
	origin = ft_new_vec3(x, y, z);
	return (origin);
}
