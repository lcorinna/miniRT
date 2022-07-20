/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:13:30 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/20 20:25:58 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_light	ft_new_light(t_vec3 *position, float bright, t_vec3 *color)
{
	t_light	new;

	new.pos = *position;
	new.bright = bright;
	new.clr = *color;
	return (new);
}
