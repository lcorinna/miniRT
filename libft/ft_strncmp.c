/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:26:32 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/31 19:08:47 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					res;
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *) s1;
	p2 = (const unsigned char *) s2;
	res = 0;
	i = 0;
	// printf("HERE\n"); //del
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while ((i < n) && ((p1[i] != '\0') || (p2[i] != '\0')))
	{
		if (p1[i] != p2[i])
		{
			// printf("p1[%zu] - %c\n", i, p1[i]); //del
			// printf("p2[%zu] - %c\n\n", i, p2[i]); //del
			res = p1[i] - p2[i];
			return (res);
		}
		i++;
	}
	return (res);
}
