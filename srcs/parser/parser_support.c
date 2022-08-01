/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:06:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/01 21:44:01 by lcorinna         ###   ########.fr       */
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
		// printf("alan - %c\n", str[*i]); //del
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
	// printf("part - %f\n", part); //del
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
	// printf("r - %f\n", r); //del
	g = ft_pars_one_clr(str, &i);
	// printf("g - %f\n", g); //del
	b = ft_pars_one_clr(str, &i);
	// printf("b - %f\n", b); //del
	if (r < 0.0 || r > 255.0 || g < 0.0 || g > 255.0 || b < 0.0 || b > 255.0)
	{
		clr = ft_new_vec3(-1, -1, -1);
		return (clr);
	}	
	clr = ft_new_vec3(r, g, b);
	return (clr);
}

float	ft_pre_assembly(char *str, int *i)
{
	float	res;
	char	number[4];
	int		j;

	res = 1;
	j = 0;
	// printf("pre begin - %s\n", str + *i); //del
	if (str[*i] == '-')
	{
		res = -1;
		(*i)++;
	}
	if (!ft_isdigit(str[*i]))
		return (MAXFLOAT);
	while (str[*i] != '\0' && str[*i] != '\n' && str[*i] != ',' && \
		str[*i] != 32 && (str[*i] >= '0' && str[*i] <= '9'))
	{
		if (!ft_isdigit(str[*i]))
			return (MAXFLOAT);
		number[j] = '\0';
		number[j] = str[*i];
		(*i)++;
		j++;
	}
	if (str[*i] == ',')
		(*i)++;
	number[j] = '\0';
	res *= (float)ft_atoi(number);
	return (res);
}

t_vec3	ft_point_in_space(t_main *data, char *str)
{
	t_vec3	origin;
	float	x;
	float	y;
	float	z;
	int		i;

	i = 0;
	x = ft_pre_assembly(str, &i);
	// printf("x - %f\n", x); //del
	y = ft_pre_assembly(str, &i);
	// printf("y - %f\n", y); //del
	z = ft_pre_assembly(str, &i);
	origin = ft_new_vec3(x, y, z);
	// printf("z - %f\n", z); //del
	// printf("str - %s\n", str + i); //del
	return (origin);
}

void	ft_data_entry_error(char *str)
{
	ft_putstr_fd("Check the line for the correct input\n", 2);
	ft_putstr_fd(str, 2);
}
