/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:43:28 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/21 13:14:28 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*f_element;

	f_element = (t_list *) malloc(sizeof(t_list));
	if (f_element == NULL)
		return (f_element);
	(*f_element).content = content;
	f_element->next = NULL;
	return (f_element);
}
