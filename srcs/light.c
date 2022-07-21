/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:13:30 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/21 16:03:28 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_ambient	ft_new_amb(float bright, t_vec3 *clr)
{
	t_ambient	new;

	new.bright = bright;
	new.clr = *clr;
	return (new);
}

t_light	ft_new_light(t_vec3 *position, float bright, t_vec3 *color)
{
	t_light	new;

	new.pos = *position;
	new.bright = bright;
	new.clr = *color;
	return (new);
}
