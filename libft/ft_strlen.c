/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:47 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/13 19:07:21 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *r)
{
	size_t	i;

	i = 0;
	if (r == NULL)
		return (i);
	while (r[i])
		i++;
	return (i);
}
