/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:05:36 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:20:31 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[b] != '\0')
	{
		l = 0;
		while (haystack[b + l] == needle[l] && (b + l) < len)
		{
			if (haystack[b + l] == '\0' && needle[l] == '\0')
				return ((char *)haystack + b);
			l++;
		}
		if (needle[l] == '\0')
			return ((char *)haystack + b);
		b++;
	}
	return (NULL);
}
