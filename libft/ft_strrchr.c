/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:22:01 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:20:37 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		i;
	char	m;

	m = (char) c;
	i = 0;
	a = (char *) s;
	while (a[i])
		i++;
	if (c == '\0')
		return (&a[i]);
	while (i-- != 0)
	{
		if (a[i] == m)
			return (a += i);
		if (a[i + 1] == m)
			return (&a[i + 1]);
	}
	return (NULL);
}
