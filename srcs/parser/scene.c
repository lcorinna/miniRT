/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:30:37 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/07 15:07:02 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_scene	ft_new_scene(void)
{
	t_scene	new;

	new = (t_scene){};
	new.width = WIDTH;
	new.height = HEIGHT;
	return (new);
}
