/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/28 17:30:12 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	*ft_new_vec3(float x, float y, float z)
{
	t_vec3	*new;
	new = malloc(sizeof(t_vec3));
	if (!new)
		return (NULL); //обработать выход
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_vec3	*ft_sub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*result;

	result = ft_new_vec3((a->x - b->x), (a->y - b->y), (a->z - b->z));
	return (result);
}

float	ft_length(t_vec3 *a)
{
	float	res;

	res = sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z));
	return (res);
}

void	ft_norm(t_vec3 *a)
{
	float	length;

	length = ft_length(a);
	a->x /= length;
	a->y /= length;
	a->z /= length;
}

float	ft_dot(t_vec3 *a, t_vec3 *b)
{
	float	res;

	res = ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
	return (res);
}
