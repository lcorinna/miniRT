/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 16:02:14 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	ft_length(t_vec3 a)
{
	float	length;

	length = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return (length);
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

float	ft_dot(t_vec3 *a, t_vec3 *b)
{
	float	dot_product;

	dot_product = ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
	return (dot_product);
}

t_vec3	ft_cross(t_vec3 *a, t_vec3 *b)
{
	t_vec3	cross_product;

	cross_product.x = a->y * b->z - a->z * b->y;
	cross_product.y = a->z * b->x - a->x * b->z;
	cross_product.z = a->x * b->y - a->y * b->x;
	return (cross_product);
}

/*
длина (length)
умножение (multiplication)
скалярное умножение (scalar multiplication)
скалярное произведение векторов (dot product)
векторное произведение (cross product)
*/