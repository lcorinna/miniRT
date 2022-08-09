/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:51:29 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 15:56:17 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	ft_diff_lght(t_vec3 nrmlz, t_vec3 inter_point, t_main *data)
{
	t_vec3	spot;
	t_vec3	tmp;
	float	res;

	tmp = ft_sub(&(data->scene.lght.pos), &inter_point);
	spot = ft_norm(&tmp);
	res = ft_dot(&nrmlz, &spot);
	return (res * data->scene.lght.bright);
}

float	ft_spec_lght(t_vec3	nrmlz, t_vec3 direction, t_vec3 inter_point, \
																t_main *data)
{
	float	bright;
	t_vec3	reflect;
	t_vec3	spot;
	t_vec3	tmp;

	bright = data->scene.lght.bright;
	tmp = ft_sub(&(data->scene.lght.pos), &inter_point);
	spot = ft_norm(&tmp);
	reflect = ft_reflect(&direction, &nrmlz);
	return (pow(fmax(ft_dot(&reflect, &spot), 0), 32) * bright);
}

int	ft_drop_shadow(t_main *data, t_shapes *shape, t_vec3 *inter_point)
{
	t_vec3		dir;
	t_vec3		vec_tmp;
	t_shapes	*tmp;
	float		dist;

	vec_tmp = ft_sub(&(data->scene.lght.pos), inter_point);
	dir = ft_norm(&vec_tmp);
	tmp = data->scene.sh;
	while (tmp)
	{
		dist = ft_find_dist(tmp, inter_point, &dir);
		if (tmp->type != shape->type)
		{
			if (dist > 0 && dist < ft_dist(*inter_point, data->scene.lght.pos) \
			&& tmp != shape)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_vec3	ft_normal_surface(t_vec3 inter_point, t_shapes *sh)
{
	t_vec3	nrmlz;
	t_vec3	tmp;

	if (sh->type == SPHERE)
	{
		tmp = ft_sub(&inter_point, &(sh->pos));
		nrmlz = ft_norm(&tmp);
	}
	else if (sh->type == PLANE)
		nrmlz = ft_norm(&(sh->direction));
	else if (sh->type == CYLINDER)
		nrmlz = ft_cylinder_norm(sh, &inter_point);
	return (nrmlz);
}

int	ft_lighting(t_main *data, t_shapes *sh, t_vec3 *direction, float dist)
{
	t_vec3	inter_point;
	t_vec3	nrmlz;
	t_vec3	tmp;
	int		drop;
	int		clr;

	tmp = ft_s_mul(direction, dist);
	inter_point = ft_add(&(data->scene.cam.origin), &tmp);
	nrmlz = ft_normal_surface(inter_point, sh);
	drop = ft_drop_shadow(data, sh, &inter_point);
	if (drop == 0)
		clr = ft_add_clr3(ft_mul_clr(sh->clr, data->scene.amb.bright), \
		ft_mul_clr(sh->clr, ft_diff_lght(nrmlz, inter_point, data) * DIFF), \
ft_mul_clr(sh->clr, ft_spec_lght(nrmlz, *direction, inter_point, data) * SPEC));
	else if (drop == 1)
		clr = ft_add_clr(ft_add_clr3 \
		(ft_mul_clr(sh->clr, data->scene.amb.bright), \
ft_mul_clr(sh->clr, ft_diff_lght(nrmlz, inter_point, data) * DIFF), 0), SHADOW);
	return (clr);
}
