/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:25:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/06/30 16:41:54 by lcorinna         ###   ########.fr       */
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
	t_vec3	*subtraction;

	subtraction = ft_new_vec3((a->x - b->x), (a->y - b->y), (a->z - b->z));
	return (subtraction);
}

float	ft_length(t_vec3 *a)
{
	float	length;

	length = sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z));
	return (length);
}

void	ft_norm(t_vec3 *a)
{
	float	length;

	length = ft_length(a); //проверять длинну чтобы не была равно 0 (0, 0, 0)
	a->x /= length;
	a->y /= length;
	a->z /= length;
}

float	ft_dot(t_vec3 *a, t_vec3 *b)
{
	float	dot_product;

	dot_product = ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));	
	return (dot_product);
}

/*
вычитание (subtraction)
длина (length)
нормализация (normal)
скалярное произведение векторов (dot product)
*/