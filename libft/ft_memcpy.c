/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:42:02 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:18:22 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*e;
	char	*w;

	w = dst;
	e = (char *)src;
	i = 0;
	if (w == NULL && e == NULL)
		return (NULL);
	while (i < (int) n)
	{
		w[i] = e[i];
		i++;
	}
	return (w);
}
