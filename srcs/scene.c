/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:30:37 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/07 14:38:35 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_shapes	ft_new_shapes(t_sphere	*sp)
{
	t_shapes	new;

	new.sp = sp;
	// new->pl = pl; //добавить когда появяться фигуры
	// new->cy = cy; //добавить когда появяться фигуры
	return (new);
}

t_scene	*ft_new_scene(t_camera *cam, t_shapes *sh)
{
	t_scene	*new;

	new = malloc(sizeof(t_scene));
	if (!new)
		return (NULL); //обработать выход
	new->cam = cam;
	new->sh = *sh;
	new->width = WIDTH;
	new->height = HEIGHT;
	return (new);
}
