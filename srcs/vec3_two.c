/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/28 17:35:57 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	*ft_add(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*addition;

	addition = ft_new_vec3((a->x + b->x), (a->y + b->y), (a->z + b->z));
	return (addition);
}

t_vec3	*ft_mul(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*multiplication;

	multiplication = ft_new_vec3((a->x * b->x), (a->y * b->y), (a->z * b->z));
	return (multiplication);
}

t_vec3	*ft_s_mul(t_vec3 *a, float value)
{
	t_vec3	*scalar_multiplication;

	scalar_multiplication = ft_new_vec3((a->x * value), (a->y * value), \
																(a->z * value));
	return (scalar_multiplication);
}

t_vec3	*ft_cross(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*cross;

	cross = ft_new_vec3((a->y * b->z - a->z * b->y), \
					(a->z * b->x - a->x * b->z), (a->x * b->y - a->y * b->x));
	return (cross);
}

t_vec3	*reflect(t_vec3 *rd, t_vec3 *n)
{
	t_vec3	*reflect;

	reflect = ft_sub(rd, ft_s_mul(n, (2 * ft_dot(n, rd))));
	return (reflect);
}
