/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:00:35 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:18:35 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	len -= 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy (d, s, len + 1));
	while ((int)len != -1)
	{
		d[len] = s[len];
		len--;
	}
	return (d);
}
