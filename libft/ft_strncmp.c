/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:26:32 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:20:23 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;
	int				l;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	i = 0;
	l = (int) n;
	if (l < 0)
		return (-1);
	while ((i < l) && (a[i] != '\0' || b[i] != '\0'))
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
