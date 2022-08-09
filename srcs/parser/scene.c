/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:30:37 by ayajirob          #+#    #+#             */
/*   Updated: 2022/08/09 21:10:40 by ayajirob         ###   ########.fr       */
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
