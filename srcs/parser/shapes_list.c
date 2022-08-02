/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:46:01 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/02 20:46:02 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	ft_shape_add_front(t_shapes **lst, t_shapes *new)
{
	if (NULL != new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_shapes	*ft_shape_last(t_shapes *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_shape_add_back(t_shapes **lst, t_shapes *new)
{
	t_shapes	*lst_last;

	if (new != NULL)
	{
		lst_last = ft_shape_last(*lst);
		if (lst_last == NULL)
		{
			ft_shape_add_front(lst, new);
		}
		else
		{
			lst_last->next = new;
		}
	}
}
