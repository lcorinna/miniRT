/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:34:06 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:19:28 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	len = (ft_strlen(s1) + 1);
	dup = (char *) malloc(len * sizeof(char));
	if (dup == NULL)
		return (dup);
	while (*s1)
		*dup++ = *s1++;
	*dup = '\0';
	return (dup - len + 1);
}
