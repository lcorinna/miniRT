/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/05 18:54:35 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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

t_vec3	ft_mul(t_vec3 *a, t_vec3 *b)
{
	t_vec3	multiplication;

	multiplication.x = a->x * b->x;
	multiplication.y = a->y * b->y;
	multiplication.z = a->z * b->z;
	return (multiplication);
}

t_vec3	ft_s_mul(t_vec3 *a, float value)
{
	t_vec3	scalar_multiplication;

	scalar_multiplication.x = a->x * value;
	scalar_multiplication.y = a->y * value;
	scalar_multiplication.z = a->z * value;
	return (scalar_multiplication);
}

t_vec3	ft_cross(t_vec3 *a, t_vec3 *b)
{
	t_vec3	cross_product;

	cross_product.x = a->y * b->z - a->z * b->y;
	cross_product.y = a->z * b->x - a->x * b->z;
	cross_product.z = a->x * b->y - a->y * b->x;
	return (cross_product);
}

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
сложение (addition)
умножение (multiplication)
скалярное умножение (scalar multiplication)
векторное произведение (cross product)
отражение (reflect)
*/