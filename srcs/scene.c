/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:30:37 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/20 20:29:52 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_scene	ft_new_scene(t_ambient *ambient, t_camera *cam, t_light *light, t_shapes *sh)
{
	t_scene	new;

	new.amb = *ambient;
	new.cam = *cam;
	new.lght = *light;
	new.sh = *sh;
	new.width = WIDTH;
	new.height = HEIGHT;
	return (new);
}
