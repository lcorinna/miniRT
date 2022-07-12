/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:11:41 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/17 18:02:25 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{	
	char	*tmp;
	size_t	i;

	 i = dstsize;
	tmp = dst;
	if (ft_strlen(dst) >= i && i >= 0)
		return (ft_strlen(src) + i);
	while (*dst && i >= 0)
	{
		dst++;
		i--;
	}
	while (i > 1 && *src)
	{
		*dst = *src;
		src++;
		dst++;
		i--;
	}
	*dst = '\0';
	return (ft_strlen(src) + ft_strlen(tmp));
}
