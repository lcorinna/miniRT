/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:19:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/21 19:39:05 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_camera	ft_new_camera(t_vec3 *origin, t_vec3 *direction, float fov)
{
	t_camera	new;

	new.origin = *origin;
	new.direction = *direction;
	new.fov = fov;
	new.angle_y = 0;
	new.angle_z = 0;
	return (new);
}
