/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:25:24 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:19:18 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;
	char	i;

	i = (char) c;
	a = (char *) s;
	while (*a)
	{
		if (*a == i)
			return (a);
		a++;
	}
	if (*a == i)
		return (a);
	return (NULL);
}
