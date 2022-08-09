/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 16:02:56 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	ft_new_vec3(float x, float y, float z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec3	ft_add(t_vec3 *a, t_vec3 *b)
{
	t_vec3	addition;

	addition.x = a->x + b->x;
	addition.y = a->y + b->y;
	addition.z = a->z + b->z;
	return (addition);
}

t_vec3	ft_add3(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	t_vec3	addition3;

	addition3.x = a->x + b->x + c->x;
	addition3.y = a->y + b->y + c->y;
	addition3.z = a->z + b->z + c->z;
	return (addition3);
}

t_vec3	ft_sub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	subtraction;

	subtraction.x = a->x - b->x;
	subtraction.y = a->y - b->y;
	subtraction.z = a->z - b->z;
	return (subtraction);
}

t_vec3	ft_norm(t_vec3 *a)
{
	t_vec3	new;
	float	length;

	length = ft_length(*a);
	new.x = a->x / length;
	new.y = a->y / length;
	new.z = a->z / length;
	return (new);
}

/*
сложение (addition)
вычитание (subtraction)
нормализация (normal)
*/