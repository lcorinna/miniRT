/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:11:48 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/06 20:00:49 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_sphere	*ft_new_sphere(t_vec3 *center, int color, float rad)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	if (!new)
		return (NULL); //обработать
	new->center = *center;
	new->color = color;
	new->rad = rad;
	new->next = NULL;
	return (new);
}

void	ft_sphere_add_front(t_sphere **lst, t_sphere *new)
{
	if (NULL != new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_sphere	*ft_sphere_last(t_sphere *lst)
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

void	ft_sphere_add_back(t_sphere **lst, t_sphere *new)
{
	t_sphere	*lst_last;

	if (new != NULL)
	{
		lst_last = ft_sphere_last(*lst);
		if (lst_last == NULL)
		{
			ft_sphere_add_front(lst, new);
		}
		else
		{
			lst_last->next = new;
		}
	}
}