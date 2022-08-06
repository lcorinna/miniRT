/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:20:59 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/15 14:39:15 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		len_res;

	start = 0;
	res = (char *)s1;
	while (*res && ft_strchr(set, *res) != NULL)
	{
		res++;
		start++;
	}
	len_res = ft_strlen(res);
	res += (len_res - 1);
	while (len_res > 0 && ft_strchr(set, *res) != NULL)
	{
		res--;
		len_res--;
	}
	res = ft_substr(s1, start, len_res);
	return (res);
}
