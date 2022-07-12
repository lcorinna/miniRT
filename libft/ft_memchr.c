/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:41:38 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:18:08 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	symbol;

	symbol = (unsigned char) c;
	str = (unsigned char *) s;
	while (n != 0)
	{
		if (*str == symbol)
			return (str);
		n--;
		str++;
	}
	return (NULL);
}
