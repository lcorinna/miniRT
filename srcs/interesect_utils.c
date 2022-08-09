/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interesect_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:12:27 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 14:44:52 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	ft_cylinder_norm(t_shapes *cyl, t_vec3 *inter_point)
{
	t_vec3	norm;
	t_vec3	top_center;
	t_vec3	pt;
	t_vec3	tmp;
	float	t;

	tmp = ft_s_mul(&cyl->direction, cyl->height);
	top_center = ft_add(&cyl->pos, &tmp);
	if (ft_length(ft_sub(inter_point, &cyl->pos)) < cyl->rad)
		norm = ft_s_mul(&(cyl->pos), -1);
	else if (ft_length(ft_sub(inter_point, &top_center)) < cyl->rad)
		norm = cyl->direction;
	else
	{
		tmp = ft_sub(inter_point, &cyl->pos);
		t = ft_dot(&tmp, &(cyl->direction));
		tmp = ft_s_mul(&(cyl->direction), t);
		pt = ft_add(&(cyl->pos), &tmp);
		tmp = ft_sub(inter_point, &pt);
		norm = ft_norm(&tmp);
	}
	return (norm);
}

float	ft_calc_t(float ca_co_cp, float cadir, float caca, float res)
{
	float	t;

	if (res < 0)
		t = (0 - ca_co_cp) / cadir;
	else
		t = (caca - ca_co_cp) / cadir;
	return (t);
}

float	ft_cylinder_intersect_unils(t_shapes *cyl, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box)
{
	box.tmp = ft_sub(cam_origin, &cyl->pos);
	box.res = ft_dot(&box.ca, &box.tmp) + \
			((-box.b - sqrt(box.discr)) / box.a) * ft_dot(&box.ca, direction);
	if (box.res > 0 && box.res < ft_dot(&box.ca, &box.ca))
		return (((-box.b - sqrt((box.b * box.b - box.a * box.c))) / box.a));
	box.tmp = ft_sub(cam_origin, &cyl->pos);
	box.res = ft_calc_t(ft_dot(&box.ca, &box.tmp), ft_dot(&box.ca, direction), \
											ft_dot(&box.ca, &box.ca), box.res);
	if (fabs(box.b + box.a * box.res) < sqrt(box.discr))
		return (box.res);
	return (0);
}

float	ft_cylinder_intersect(t_shapes *cyl, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box)
{
	box.tmp = ft_s_mul(&cyl->direction, cyl->height);
	box.tmp = ft_add(&cyl->pos, &box.tmp);
	box.ca = ft_sub(&box.tmp, &cyl->pos);
	box.a = ft_dot(&box.ca, &box.ca) - ft_dot(&box.ca, direction) * \
													ft_dot(&box.ca, direction);
	box.tmp = ft_sub(cam_origin, &cyl->pos);
	box.b = ft_dot(&box.ca, &box.ca) * ft_dot(&box.tmp, direction) - \
						ft_dot(&box.ca, &box.tmp) * ft_dot(&box.ca, direction);
	box.tmp = ft_sub(cam_origin, &cyl->pos);
	box.c = ft_dot(&box.ca, &box.ca) * ft_dot(&box.tmp, &box.tmp) - \
					ft_dot(&box.ca, &box.tmp) * ft_dot(&box.ca, &box.tmp) - \
								cyl->rad * cyl->rad * ft_dot(&box.ca, &box.ca);
	box.discr = box.b * box.b - box.a * box.c;
	if (box.discr < 0)
		return (0);
	box.res = ft_cylinder_intersect_unils(cyl, cam_origin, direction, box);
	return (box.res);
}
