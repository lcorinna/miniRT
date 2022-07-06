/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:30:37 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/06 20:05:05 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_scene	*ft_new_scene(t_camera *cam, t_sphere *sphere)
{
	t_scene	*new;

	new = malloc(sizeof(t_scene));
	if (!new)
		return (NULL); //обработать выход
	new->cams = cam;
	new->sphere = sphere;
	new->width = WIDTH;
	new->height = HEIGHT;
	return (new);
}
