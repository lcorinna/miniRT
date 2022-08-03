/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:46:01 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/03 23:08:47 by lcorinna         ###   ########.fr       */
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
			printf("type - %d\n", lst->type); //del
			printf("pos - %f\n", lst->pos.x); //del
			lst = lst->next;
		}
		printf("LENA\n"); //del
	}
	return (lst);
}

void	ft_shape_add_back(t_shapes *lst, t_shapes *new)
{
	t_shapes	*lst_last;
	t_shapes	*tmp;

	tmp = lst;
	if (new != NULL)
	{
		lst_last = ft_shape_last(tmp);
		if (lst_last == NULL)
		{
			ft_shape_add_front(tmp, new);
		}
		else
		{
			lst_last->next = new;
		}
	}
	// printf("TUTA  - %d\n", (*lst)->type); //del
	// printf("TUTA2  - %f\n", (*lst)->pos.x); //del
}

// void	ft_shape_add_front(t_shapes **lst, t_shapes *new)
// {
// 	(*new).next = *lst;
// 	*lst = new;
// }

// t_shapes	*ft_shape_last(t_shapes *lst)
// {
// 	if (lst == NULL)
// 		return (lst);
// 	printf("HERE"); //del
// 	while ((*lst).next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }

// void	ft_shape_add_back(t_shapes **lst, t_shapes *new)
// {
// 	t_shapes	*tmp;

// 	if (*lst == NULL)
// 		*lst = new;
// 	else
// 	{
// 		tmp = *lst;
// 		tmp = ft_shape_last(*lst);
// 		(*tmp).next = new;
// 	}
// }
