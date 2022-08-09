/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:01:40 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 18:25:22 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	ft_dist(t_vec3 a, t_vec3 b)
{
	float	distance;
	t_vec3	subtraction;

	subtraction = ft_sub(&b, &a);
	distance = ft_length(subtraction);
	return (distance);
}

t_vec3	ft_reflect(t_vec3 *rd, t_vec3 *n)
{
	t_vec3	reflect;
	t_vec3	tmp;

	tmp = ft_s_mul(n, (2 * ft_dot(n, rd)));
	reflect = ft_sub(rd, &tmp);
	reflect = ft_norm(&reflect);
	return (reflect);
}

/*
отражение (reflect)
растояние между двумя точками (dist)
*/
