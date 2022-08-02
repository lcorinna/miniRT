/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:11:48 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/02 21:19:37 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_shapes	ft_new_plane(t_vec3 *position, t_vec3 *color, t_vec3 *direction)
{
	t_shapes	new;

	new = (t_shapes){};
	new.type = PLANE;
	new.pos = *position;
	new.clr = *color;
	new.direction = *direction;
	new.next = NULL;
	return (new);
}

t_shapes	ft_new_sphere(t_vec3 *center, t_vec3 *color, float diameter)
{
	t_shapes	new;

	new = (t_shapes){};
	new.type = SPHERE;
	new.pos = *center;
	new.clr = *color;
	new.diameter = diameter;
	new.rad = diameter / 2;
	new.next = NULL;
	return (new);
}

t_shapes	ft_new_cylinder(t_vec3 *position, t_vec3 *color, float diameter, \
																float height)
{
	t_shapes	new;

	new = (t_shapes){};
	new.type = CYLINDER;
	new.pos = *position;
	new.clr = *color;
	new.diameter = diameter;
	new.rad = diameter / 2;
	new.height = height;
	new.next = NULL;
	return (new);
}
